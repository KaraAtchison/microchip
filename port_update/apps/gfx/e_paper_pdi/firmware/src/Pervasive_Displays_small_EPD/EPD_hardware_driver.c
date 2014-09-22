/**
 *
 * \brief The initialization and configuration of COG hardware driver
 *
 * Copyright (c) 2013-2014 Pervasive Displays Inc. All rights reserved.
 *
 *  Authors: Pervasive Displays Inc.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <math.h>
#include <stdbool.h>
#include <xc.h>
#include "timer_1ms.h"
#include "EPD_hardware_driver.h"
#include "Pervasive_Displays_small_EPD.h"

//////////////////////// FUNCTION POINTERS ///////////////////////////
DRV_EPD_TEMPERATURE_GET_FUNC  pTemperatureGet = NULL; // function pointer to get raw temperature value

void EPD_DRV_SysTick_Handler(void);
void DRV_EPD_ControlSignalsInitialize(void);

static volatile uint32_t            EPD_Counter;
static          uint8_t             spi_flag = false;
static          DRV_SPI_INIT_DATA   EPD_spiInitData;

#ifndef EPD_CONFIG_TEMPERATURE_SAMPLE_ALWAYS
static          bool                EPD_TempSampleDone = false;
#endif

/**
 * \brief Start Timer
 */
void DRV_EPD_TIMER_Start(void)
{
    TIMER_SetConfiguration(TIMER_CONFIGURATION_1MS);
    TIMER_RequestTick(&EPD_DRV_SysTick_Handler, 1);
    EPD_Counter = 0;
}

/**
 * \brief Stop Timer
 */
void DRV_EPD_TIMER_Stop(void)
{
    TIMER_CancelTick(&EPD_DRV_SysTick_Handler);
    TIMER_SetConfiguration(TIMER_CONFIGURATION_OFF);
}

/**
 * \brief Get current Timer after starting a new one
 */
uint32_t DRV_EPD_TickCountGet(void)
{
    return EPD_Counter;
}

/**
 * \brief Called by Timer Interrupt Service Routine for system tick counter
 */
void EPD_DRV_SysTick_Handler(void)
{
    EPD_Counter++;
}
/**
* \brief Delay mini-seconds
* \param ms The number of mini-seconds
*/
void sys_delay_ms(uint32_t ms)
{
    delay_ms(ms);
}


static void Wait_10us(void)
{
    delay_us(5);
}

//******************************************************************
//* PWM  Configuration/Control
//******************************************************************

/**
 * \brief PWM toggling.
 *
 * \param ms The interval of PWM toggling (mini seconds)
 */
void DRV_EPD_PWMRun(uint16_t ms)
{
    DRV_EPD_TIMER_Start();

    do {
        DRV_EPD_PWMPortSet();
        delay_us(5);
        DRV_EPD_PWMPortReset();
        delay_us(5);
    } while (DRV_EPD_TickCountGet() < ms); //wait Delay Time

    DRV_EPD_TIMER_Stop();
        
}

//******************************************************************
//* SPI  Configuration
//******************************************************************

/**
 * \brief Configure SPI
 */
void DRV_EPD_SPI_Initialize(DRV_SPI_INIT_DATA *pInitData)
{

    if (spi_flag)
        return;

    spi_flag = true;

    DRV_SPI_Initialize(pInitData);
    memcpy(&EPD_spiInitData, pInitData, sizeof(DRV_SPI_INIT_DATA));

}


/**
 * \brief Initialize SPI
 */
void DRV_EPD_SPI_Attach(void)
{
    DRV_SPI_Initialize(&EPD_spiInitData);
}

/**
 * \brief Disable SPI and change to GPIO
 */
void DRV_EPD_SPI_Detach(void)
{
    spi_flag = false;

    // disable the SPI module
    DRV_SPI_Deinitialize(EPD_spiInitData.channel);

    // make sure the SPI pins will not
    // drive the EPD controller
    DRV_EPD_SPI_SCK_TRIS = 0;
    DRV_EPD_SPI_SDO_TRIS = 0;
    DRV_EPD_SPI_SDI_TRIS = 0;

    DRV_EPD_SPI_SCK_LAT  = 0;
    DRV_EPD_SPI_SDO_LAT  = 0;
    DRV_EPD_SPI_SDI_LAT  = 0;

}

#if (defined COG_V230_G2)
/**
* \brief SPI command
*
* \param register_index The Register Index as SPI Data to COG
* \param register_data The Register Data for sending command data to COG
* \return the SPI read value
*/
uint8_t SPI_R(uint8_t Register, uint8_t Data)
{
    uint8_t result;
    uint8_t send_data[2];

    while(!DRV_SPI_Lock(EPD_spiInitData.channel));

    DRV_EPD_SPI_Enable();

    send_data[0] = 0x70;
    send_data[1] = Register;
    DRV_SPI_PutBuffer(EPD_spiInitData.channel, send_data, 2);

    DRV_EPD_SPI_Disable();
    Wait_10us();
    DRV_EPD_SPI_Enable();

    DRV_SPI_Put(EPD_spiInitData.channel, 0x73);
    result = DRV_SPI_Get(EPD_spiInitData.channel);

    DRV_EPD_SPI_Disable();
    DRV_SPI_Unlock(EPD_spiInitData.channel);

    return result;
}
#endif

/**
* \brief SPI command if register data is larger than two bytes
*
* \param register_index The Register Index as SPI command to COG
* \param register_data The Register Data for sending command data to COG
* \param length The number of bytes of Register Data which depends on which
* Register Index is selected.
*/
void DRV_EPD_SPI_Send (     uint8_t register_index,
                            uint8_t *register_data,
                            uint16_t length)
{
    uint8_t send_data[2];

    while(!DRV_SPI_Lock(EPD_spiInitData.channel));

    DRV_EPD_SPI_Enable();

    send_data[0] = 0x70;
    send_data[1] = register_index;
    DRV_SPI_PutBuffer(EPD_spiInitData.channel, send_data, 2);


    DRV_EPD_SPI_Disable();
    Wait_10us();
    DRV_EPD_SPI_Enable();

    DRV_SPI_Put(EPD_spiInitData.channel, 0x72);
    DRV_SPI_PutBuffer(EPD_spiInitData.channel, register_data, length);

    DRV_EPD_SPI_Disable();

    DRV_SPI_Unlock(EPD_spiInitData.channel);

    Wait_10us();
}

/**
* \brief SPI command
*
* \param register_index The Register Index as SPI command to COG
* \param register_data The Register Data for sending command data to COG
*/
void DRV_EPD_SPI_ByteSend ( uint8_t register_index,
                            uint8_t register_data)
{
    uint8_t send_data[2];

    while(!DRV_SPI_Lock(EPD_spiInitData.channel));

    DRV_EPD_SPI_Enable();

    send_data[0] = 0x70;
    send_data[1] = register_index;

    DRV_SPI_PutBuffer(EPD_spiInitData.channel, send_data, 2);

    DRV_EPD_SPI_Disable();
    Wait_10us();
    DRV_EPD_SPI_Enable();
    
    send_data[0] = 0x72;
    send_data[1] = register_data;

    DRV_SPI_PutBuffer(EPD_spiInitData.channel, send_data, 2);

    DRV_EPD_SPI_Disable();
    DRV_SPI_Unlock(EPD_spiInitData.channel);

    Wait_10us();
}

//******************************************************************
//* Temperature sensor  Configuration
//******************************************************************
static float IntDegC;
#define Voltag_base     (float)((3.3*100)/1024)
#define Deg_0_voltag    (float)(500/10)    //500mv/10

/**
 * \brief Set temperature read callback function
 */
void DRV_EPD_TemperatureGetCallbackSet( DRV_EPD_TEMPERATURE_GET_FUNC pFunc)
{
    pTemperatureGet = pFunc;
}

/**
 * \brief Get temperature value from user supplied function that samples temperature
 *
 * \return the Celsius temperature
 */
int16_t DRV_EPD_TemperatureGet(void)
{
    static uint16_t adcval;

    adcval = pTemperatureGet();
    IntDegC=(adcval*Voltag_base)-Deg_0_voltag;

    return (int16_t) IntDegC;

}

///**
// * \brief Get temperature value from ADC
// *
// * \return the Celsius temperature
// */
//int16_t DRV_EPD_TemperatureGet(void)
//{
//    uint16_t adcval;
//
//#ifndef EPD_CONFIG_TEMPERATURE_SAMPLE_ALWAYS
//    if (EPD_TempSampleDone == false)
//#endif
//    {
//        adcval = ADC_Read10bit(ADC_CHANNEL_TEMPERATURE_SENSOR);
//        IntDegC=(adcval*Voltag_base)-Deg_0_voltag;
//
//#ifndef EPD_CONFIG_TEMPERATURE_SAMPLE_ALWAYS
//        EPD_TempSampleDone = true;
//#endif
//    }
//
//    return (int16_t) IntDegC;
//}
//
///**
// * \brief Initialize the temperature sensor
// */
//void DRV_EPD_TempSensorInitialize(void)
//{
//#ifndef EPD_CONFIG_TEMPERATURE_SAMPLE_ALWAYS
//    if (EPD_TempSampleDone == false)
//#endif
//    {
//        /* Enable ADC connected to temperature sensor channel
//           and configure it as 10 bit manual read mode */
//        ADC_ChannelEnable ( ADC_CHANNEL_TEMPERATURE_SENSOR );
//        ADC_SetConfiguration ( ADC_CONFIGURATION_DEFAULT );
//        AD1CHS = ADC_CHANNEL_4;
//
//    }
//}

/**
 * \brief Initialize the EPD hardware setting
 */
void DRV_EPD_DisplayDriverInitialize(void)
{
    DRV_EPD_ControlSignalsInitialize();
    DRV_EPD_PowerDisable();


    // assumption here is that the SPI driver must be
    // initialized prior to this call
    DRV_EPD_SPI_Attach();
    
//    DRV_EPD_TempSensorInitialize();
    DRV_EPD_SPI_Enable();

    DRV_EPD_PWMPortReset();
    DRV_EPD_DisplayDisable();
    DRV_EPD_DischargeReset();
    DRV_EPD_BorderDisable();
}

//******************************************************************
//* Display Controller Controls
//******************************************************************

/**
* \brief Configure GPIO
*/
void DRV_EPD_ControlSignalsInitialize(void)
{
    DRV_EPD_DISPLAY_BUSY_TRIS = 1;
    DRV_EPD_DISPLAY_RESET_TRIS = 0;
    DRV_EPD_DISPLAY_PWM_TRIS = 0;
    DRV_EPD_DISPLAY_PANEL_ON_TRIS = 0;
    DRV_EPD_DISPLAY_DISCHARGE_TRIS = 0;
    DRV_EPD_DISPLAY_BORDER_TRIS = 0;
    DRV_EPD_DISPLAY_TEMP_TRIS = 1;

    DRV_EPD_BorderDisable();

}


/**
* \brief Set /RESET pin to high
*/
inline void __attribute__ ((always_inline)) DRV_EPD_DisplayEnable(void)
{
    DRV_EPD_DISPLAY_RESET_LAT = 1;
}

/**
* \brief Set /RESET pin to low
*/
inline void __attribute__ ((always_inline)) DRV_EPD_DisplayDisable(void)
{
    DRV_EPD_DISPLAY_RESET_LAT = 0;
}

/**
* \brief Set DISCHARGE pin to high
*/
inline void __attribute__ ((always_inline)) DRV_EPD_DischargeSet(void)
{
    DRV_EPD_DISPLAY_DISCHARGE_LAT = 1;
}

/**
* \brief Set DISCHARGE pin to low
*/
inline void __attribute__ ((always_inline)) DRV_EPD_DischargeReset(void)
{
    DRV_EPD_DISPLAY_DISCHARGE_LAT = 0;
}

/**
* \brief Set Vcc (PANEL_ON) to high
*/
inline void __attribute__ ((always_inline)) DRV_EPD_PowerEnable(void)
{
    DRV_EPD_DISPLAY_PANEL_ON_LAT = 1;
}

/**
* \brief Set Vcc (PANEL_ON) to low
*/
inline void __attribute__ ((always_inline)) DRV_EPD_PowerDisable(void)
{
    DRV_EPD_DISPLAY_PANEL_ON_LAT = 0;
}

/**
* \brief Set BORDER_CONTROL pin to high
*/
inline void __attribute__ ((always_inline)) DRV_EPD_BorderEnable(void)
{
    DRV_EPD_DISPLAY_BORDER_LAT = 1;
}

/**
* \brief Set BORDER_CONTROL pin to low
*/
inline void __attribute__ ((always_inline)) DRV_EPD_BorderDisable(void)
{
    DRV_EPD_DISPLAY_BORDER_LAT = 0;
}

/**
* \brief Set PWM pin to high
*/
inline void __attribute__ ((always_inline)) DRV_EPD_PWMPortSet(void)
{
    DRV_EPD_DISPLAY_PWM_LAT = 1;
}

/**
* \brief Set PWM pin to low
*/
inline void __attribute__ ((always_inline)) DRV_EPD_PWMPortReset(void)
{
    DRV_EPD_DISPLAY_PWM_LAT = 0;
}

/**
* \brief Get BUSY pin status
*/
inline bool __attribute__ ((always_inline)) DRV_EPD_BusyStatusGet(void)
{
    if (DRV_EPD_DISPLAY_BUSY_PORT == 0)
        return false;
    else
        return true;
}
