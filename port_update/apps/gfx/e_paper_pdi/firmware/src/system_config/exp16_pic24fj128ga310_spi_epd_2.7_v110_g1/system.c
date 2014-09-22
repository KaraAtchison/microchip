/*******************************************************************************
  System Specific Initializations

  Company:
    Microchip Technology Inc.

  File Name:
    system.c

  Summary:
    System level initializations for the specific Microchip Development Board used.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// Section: Includes
// *****************************************************************************
#include <xc.h>
#include <system.h>
#include "driver/spi/drv_spi.h"
#include "driver/gfx/drv_gfx_display.h"
#include "driver/touch_screen/drv_touch_screen.h"
#include "EPD_hardware_driver.h"

// *****************************************************************************
// Configuration bits
// *****************************************************************************


// PIC24FJ128GA310 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

// CONFIG4
#pragma config DSWDTPS = DSWDTPS1F      // Deep Sleep Watchdog Timer Postscale Select bits (1:68719476736 (25.7 Days))
#pragma config DSWDTOSC = LPRC          // DSWDT Reference Clock Select (DSWDT uses LPRC as reference clock)
#pragma config DSBOREN = OFF            // Deep Sleep BOR Enable bit (DSBOR Disabled)
#pragma config DSWDTEN = OFF            // Deep Sleep Watchdog Timer Enable (DSWDT Disabled)
#pragma config DSSWEN = ON              // DSEN Bit Enable (Deep Sleep is controlled by the register bit DSEN)

// CONFIG3
#pragma config WPFP = WPFP127           // Write Protection Flash Page Segment Boundary (Page 127 (0x1FC00))
#pragma config VBTBOR = OFF             // VBAT BOR enable bit (VBAT BOR disabled)
#pragma config SOSCSEL = OFF            // SOSC Selection bits (Digital (SCLKI) mode)
#pragma config WDTWIN = PS25_0          // Watch Dog Timer Window Width (Watch Dog Timer Window Width is 25 percent)
#pragma config BOREN = ON               // Brown-out Reset Enable (Brown-out Reset Enable)
#pragma config WPDIS = WPDIS            // Segment Write Protection Disable (Disabled)
#pragma config WPCFG = WPCFGDIS         // Write Protect Configuration Page Select (Disabled)
#pragma config WPEND = WPENDMEM         // Segment Write Protection End Page Select (Write Protect from WPFP to the last page of memory)

// CONFIG2
#pragma config POSCMD = XT              // Primary Oscillator Select (XT Oscillator Enabled)
#pragma config BOREN1 = EN              // BOR Override bit (BOR Enabled [When BOREN=1])
#pragma config IOL1WAY = ON             // IOLOCK One-Way Set Enable bit (Once set, the IOLOCK bit cannot be cleared)
#pragma config OSCIOFCN = OFF           // OSCO Pin Configuration (OSCO/CLKO/RC15 functions as CLKO (FOSC/2))
#pragma config FCKSM = CSECME           // Clock Switching and Fail-Safe Clock Monitor Configuration bits (Clock switching is enabled, Fail-Safe Clock Monitor is enabled)
#pragma config FNOSC = PRIPLL           // Initial Oscillator Select (Primary Oscillator with PLL module (XTPLL,HSPLL, ECPLL))
#pragma config ALTVREF = DLT_AV_DLT_CV  // Alternate VREF/CVREF Pins Selection bit (Voltage reference input, ADC =RA9/RA10 Comparator =RA9,RA10)
#pragma config IESO = OFF               // Internal External Switchover (Disabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler Select (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler Ratio Select (1:128)
#pragma config FWDTEN = WDT_DIS         // Watchdog Timer Enable (WDT disabled in hardware; SWDTEN bit disabled)
#pragma config WINDIS = OFF             // Windowed WDT Disable (Standard Watchdog Timer)
#pragma config ICS = PGx2               // Emulator Pin Placement Select bits (Emulator functions are shared with PGEC2/PGED2)
#pragma config LPCFG = OFF              // Low power regulator control (Disabled)
#pragma config GWRP = OFF               // General Segment Write Protect (Disabled)
#pragma config GCP = OFF                // General Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF             // JTAG Port Enable (Disabled)



// *****************************************************************************
// System Settings and Variables
// *****************************************************************************
volatile uint32_t   tick = 0, prevTick;  // tick counter,
volatile uint32_t   displayChangeTime;
volatile uint32_t   previousTick = 0;


// *****************************************************************************
// void SYSTEM_InitializeBoard(void)
// *****************************************************************************
void SYSTEM_InitializeBoard(void)
{
    // SPI initialization for Serial RAM
    const DRV_SPI_INIT_DATA SRAM_SPI_Init_Data = {
                                2, 3,
                                6, 1,
                                SPI_BUS_MODE_1, 0};

    // SPI initialization for EPD
    const DRV_SPI_INIT_DATA EPD_SPI_Init_Data = {
                                1, 3,
                                6, 1,
                                SPI_BUS_MODE_1, 0};

    // SPI initialization for Explorer 16 Serial EEPROM
    const DRV_SPI_INIT_DATA EX16_SPI_Init_Data = {
                                2, 3,
                                6, 1,
                                SPI_BUS_MODE_1, 0};

    // ---------------------------------------------------------
    // Make sure the display DO NOT flicker at start up
    // ---------------------------------------------------------
    DisplayBacklightConfig();
    DisplayPowerConfig();
    DisplayBacklightOff();

    // ---------------------------------------------------------
    // Set PIC peripheral speed
    // ---------------------------------------------------------
    // DOZEN disabled; DOZE 1:2; RCDIV FRC/1; ROI disabled;
    CLKDIV = 0x3000;

    // ---------------------------------------------------------
    // Set all pins with analog functionality that are used
    // as digital pins to be set to digital
    // ---------------------------------------------------------
     ANSBbits.ANSB2 = 0;
     ANSBbits.ANSB9 = 0;
     ANSAbits.ANSA10 = 0;
     ANSEbits.ANSE9 = 0;

     ANSGbits.ANSG6 = 0;
     ANSGbits.ANSG7 = 0;
     ANSGbits.ANSG8 = 0;
     ANSGbits.ANSG9 = 0;

     ANSBbits.ANSB15 = 0;

     ANSAbits.ANSA7 = 0;
     ANSAbits.ANSA6 = 0;

     // set analog pins
     ANSBbits.ANSB0 = 1;
     ANSBbits.ANSB3 = 1;

    // ---------------------------------------------------------
    // ADC Explorer 16 Development Board Errata (work around 2)
    // RB15 should be output
    // ---------------------------------------------------------
    LATBbits.LATB15 = 0;
    TRISBbits.TRISB15 = 0;

    // ---------------------------------------------------------
    // EPD PicTail Plus Daughter Board 23K256
    // SPI-RAM Device Chip Select pin
    // ---------------------------------------------------------
    MCHP_23K256_CS_TRIS = 0;
    MCHP_23K256_CS_LAT  = 1;

    // ---------------------------------------------------------
    // EPD PicTail Plus Daughter
    // Board EPD Controller Device Chip Select pin
    // ---------------------------------------------------------
    DRV_EPD_SPI_CS_TRIS = 0;
    DRV_EPD_SPI_CS_LAT  = 1;

    // ---------------------------------------------------------
    // EPD PicTail Plus Daughter
    // Board EPD Controller Device Chip Select pin
    // ---------------------------------------------------------
    MCHP25LC256_CS_TRIS = 0;
    MCHP25LC256_CS_LAT  = 1;

    // ---------------------------------------------------------
    // EPD SPI Port pins &  Explorer 16 Serial EEPROM SPI
    // Port pins (use SPI 1)
    // ---------------------------------------------------------
    // spi-clock pin
    TRISDbits.TRISD8 = 0;
    // spi-output pin
    TRISFbits.TRISF8 = 0;
    // spi-input pin
    TRISDbits.TRISD9 = 1;

    // ---------------------------------------------------------
    // Enable Internal Pull Up for Resistive Touch X+ and Y+ pins
    // ---------------------------------------------------------
    CNPU1bits.CN2PUE = 1;       // pullup X+
    CNPU1bits.CN5PUE = 1;       // pullup Y+
	
    // ---------------------------------------------------------
    // Serial RAM SPI Port pins (use SPI 2)
    // ---------------------------------------------------------
    // spi-clock pin
    TRISGbits.TRISG6 = 0;
    // spi-output pin
    TRISGbits.TRISG8 = 0;
    // spi-input pin
    TRISGbits.TRISG7 = 1;

    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    // this is for EPD
    RPOR1bits.RP2R    = 8;                  // assign RP2 for SCK1
    RPOR7bits.RP15R   = 7 ;                 // assign RP15 for SDO1
    RPINR20bits.SDI1R = 4;                  // assign RP4 for SDI1

    // this is for Serial RAM
    RPOR10bits.RP21R  = 11;                 // assign RP21 for SCK2
    RPOR9bits.RP19R   = 10;                 // assign RP19 for SDO2
    RPINR22bits.SDI2R = 26;                 // assign RP26 for SDI2

    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS
    
    // initialize SPI driver
    DRV_RAM_23K256_Initialize((DRV_SPI_INIT_DATA*)&SRAM_SPI_Init_Data);

    // initialize EPD driver
    DRV_EPD_SPI_Initialize((DRV_SPI_INIT_DATA*)&EPD_SPI_Init_Data);

    // initialize Explorer 16 Serial EEPROM
    DRV_NVM_MCHP25LC256_Initialize((DRV_SPI_INIT_DATA*)&EX16_SPI_Init_Data);

    // Set the callback for temperature reading (required by the EPD driver)
    DRV_EPD_TemperatureGetCallbackSet((DRV_EPD_TEMPERATURE_GET_FUNC)&TouchGetADCPot);
    // Initialize the e-paper (EPD)
    EPD_display_init();

    // ---------------------------------------------------------
    // Initialize the Display Driver
    // ---------------------------------------------------------
    DRV_GFX_Initialize();
    GFX_Initialize();
    
    // Initialize the reference timer.
    SYSTEM_TickInit();    

    // initialize the components for Resistive Touch Screen
    TouchInit(NVMWrite, NVMRead, NVMSectorErase, NULL);

}

/****************************************************************************
  Function:
    void TickInit( void )

  Description:
    This function sets up Timer 4 to generate an interrupt every 10 ms.

  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Remarks:
    The timer period and prescaler values are defined in HardwareProfile.h,
    since they are dependent on the oscillator speed.
  ***************************************************************************/

#define STOP_TIMER_IN_IDLE_MODE     0x2000
#define TIMER_SOURCE_INTERNAL       0x0000
#define TIMER_ON                    0x8000
#define GATED_TIME_DISABLED         0x0000
#define TIMER_16BIT_MODE            0x0000
#define TIMER_PRESCALER_1           0x0000
#define TIMER_PRESCALER_8           0x0010
#define TIMER_PRESCALER_64          0x0020
#define TIMER_PRESCALER_256         0x0030
#define TIMER_INTERRUPT_PRIORITY    0x1000


/****************************************************************************
  Function:
    void __attribute__((interrupt, shadow, auto_psv)) _T4Interrupt(void)

  Description:
    This function updates the tick count and calls ReadCTMU() to monitor the
    touchpads.

  Precondition:
    Timer 4 and the Timer 4 interrupt must be enabled in order for
                    this function to execute.  CTMUInit() must be called before
                Timer 4 and the Timer 4 interrupt are enabled.

  ***************************************************************************/
void __attribute__((interrupt, shadow, auto_psv)) _T4Interrupt(void)
{
    IFS1bits.T4IF = 0;
    tick++;
    TouchDetectPosition();

}

/*********************************************************************
 * Section: Tick Delay
 *********************************************************************/
#define SAMPLE_PERIOD   500 // us
#define TICK_PERIOD     (SYS_CLK_FrequencyPeripheralGet() * SAMPLE_PERIOD) / 4000000

// *****************************************************************************
/*  Function:
    void SYSTEM_TickInit(void)

    Summary:
        Initializes the tick timer of the demo.

    Description:
        This function initializes the tick timer of the demo.

*/
// *****************************************************************************
void SYSTEM_TickInit(void)
{
    // Initialize Timer4
    TMR4 = 0;
    PR4 = TICK_PERIOD;
    IFS1bits.T4IF = 0;  //Clear flag
    IEC1bits.T4IE = 1;  //Enable interrupt
    T4CONbits.TON = 1;  //Run timer
}

/*******************************************************************************
Function:       void __attribute__((__interrupt__, auto_psv)) _XXX(void)

These are just here to catch any spurious interrupts that we see during
debugging.

*******************************************************************************/
void __attribute__((interrupt, auto_psv)) _DefaultInterrupt(void)
{
  while (1)
  {
      Nop();
      Nop();
      Nop();
  }
}

void __attribute__((interrupt, auto_psv)) _OscillatorFail(void)
{
  while (1)
  {
      Nop();
      Nop();
      Nop();
  }
}
void __attribute__((interrupt, auto_psv)) _AddressError(void)
{
  while (1)
  {
      Nop();
      Nop();
      Nop();
  }
}
void __attribute__((interrupt, auto_psv)) _StackError(void)
{
  while (1)
  {
      Nop();
      Nop();
      Nop();
  }
}
void __attribute__((interrupt, auto_psv)) _MathError(void)
{
  while (1)
  {
      Nop();
      Nop();
      Nop();
  }
}

