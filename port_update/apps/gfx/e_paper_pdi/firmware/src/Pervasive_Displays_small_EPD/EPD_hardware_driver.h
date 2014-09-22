/**
* \brief The SPI, PWM, Temperature definitions of COG hardware driver
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

#ifndef 	DISPLAY_HARDWARE_DRIVCE_H_INCLUDED_
#define 	DISPLAY_HARDWARE_DRIVCE_H_INCLUDED_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "system.h"
#include "driver/spi/drv_spi.h"


/**Temperature Callback function **********************************************/
typedef uint16_t (*DRV_EPD_TEMPERATURE_GET_FUNC)(void); // typedef for get temperature function pointer


/**SPI Defines ****************************************************************/
//#define SPI_baudrate        (SMCLK_FREQ/COG_SPI_baudrate)   /**< the baud rate of SPI */

#define DRV_EPD_SPI_Enable()     (DRV_EPD_SPI_CS_LAT= 0)
#define DRV_EPD_SPI_Disable()    (DRV_EPD_SPI_CS_LAT= 1)

void DRV_EPD_SPI_Initialize(DRV_SPI_INIT_DATA *pInitData);
void DRV_EPD_SPI_Reinitialize(void);
void DRV_EPD_SPI_Detach(void);
void DRV_EPD_SPI_Attach(void);

void DRV_EPD_SPI_ByteSend ( uint8_t register_index,
                            uint8_t register_data);
void DRV_EPD_SPI_Send (     uint8_t register_index,
                            uint8_t *register_data,
                            uint16_t length);
void DRV_EPD_TIMER_Start(void);
void DRV_EPD_TIMER_Stop(void);

//void DRV_EPD_TempSensorInitialize(void);
int16_t DRV_EPD_TemperatureGet(void);
void DRV_EPD_TemperatureGetCallbackSet( DRV_EPD_TEMPERATURE_GET_FUNC pFunc);

uint32_t DRV_EPD_TickCountGet(void);

void DRV_EPD_PWMRun(uint16_t time);
void DisplayDriverInitialize(void);

extern inline void __attribute__ ((always_inline)) DRV_EPD_DisplayEnable(void);
extern inline void __attribute__ ((always_inline)) DRV_EPD_DisplayDisable(void);
extern inline void __attribute__ ((always_inline)) DRV_EPD_DischargeSet(void);
extern inline void __attribute__ ((always_inline)) DRV_EPD_DischargeReset(void);
extern inline void __attribute__ ((always_inline)) DRV_EPD_PowerEnable(void);
extern inline void __attribute__ ((always_inline)) DRV_EPD_PowerDisable(void);
extern inline void __attribute__ ((always_inline)) DRV_EPD_BorderEnable(void);
extern inline void __attribute__ ((always_inline)) DRV_EPD_BorderDisable(void);
extern inline void __attribute__ ((always_inline)) DRV_EPD_PWMPortSet(void);
extern inline void __attribute__ ((always_inline)) DRV_EPD_PWMPortReset(void);
extern inline bool __attribute__ ((always_inline)) DRV_EPD_BusyStatusGet(void);

void sys_delay_ms(uint32_t ms);
#if  (defined COG_V230_G2)
uint8_t SPI_R(uint8_t Register, uint8_t Data);
#endif
#endif 	//DISPLAY_HARDWARE_DRIVCE_H_INCLUDED_
