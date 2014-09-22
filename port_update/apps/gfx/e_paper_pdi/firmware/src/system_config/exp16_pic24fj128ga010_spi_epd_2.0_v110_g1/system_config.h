/*******************************************************************************
  System Specific Definitions

  Company:
    Microchip Technology Inc.

  File Name:
    system_config.h

  Summary:
    System level definitions for the specific Microchip Development Board used.

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

#ifndef __SYSTEM_CONFIG_H
#define __SYSTEM_CONFIG_H

/*********************************************************************
* PIC Device Specific includes
*********************************************************************/
#include "gfx_config.h"
//#include "../src/Pervasive_Displays_small_EPD/Pervasive_Displays_small_EPD.h"

/*********************************************************************
* Overview: Display controller selection.
*
********************************************************************/
// define the EPD type, valid values:
//typedef enum
//{
//    EPD_144 = 0,
//    EPD_200 = 1,
//    EPD_270 = 2,
//} EPD_TYPES;

#define EPD_144 0
#define EPD_200 1
#define EPD_270 2

#define GFX_USE_DISPLAY_CONTROLLER_EPD
#define USE_EPD_Type                    EPD_200

#define DISP_ORIENTATION                0
#define DISP_HOR_RESOLUTION             200
#define DISP_VER_RESOLUTION             96

#define COG_V110_G1

// define the SPI channel used for EPD
#define DRV_SPI_CONFIG_CHANNEL_1_ENABLE
// define the SPI channel used for Serial RAM
#define DRV_SPI_CONFIG_CHANNEL_2_ENABLE

// Enable SPI FIFO mode in parts where it is supported
// Enabling the FIFO mode will improve library performance.
// In this demo this definition is sometimes disabled because early versions of the PIC24FJ128GA010s have an errata preventing this feature from being used.
#if defined (__PIC24FJ128GA010__)
#define DRV_SPI_CONFIG_ENHANCED_BUFFER_DISABLE
#endif

// EPD Serial RAM pins
#define MCHP_23K256_CS_TRIS             TRISGbits.TRISG9
#define MCHP_23K256_CS_LAT              LATGbits.LATG9

#define MCHP_23K256_SCK_TRIS            TRISFbits.TRISF6
#define MCHP_23K256_SDO_TRIS            TRISFbits.TRISF8
#define MCHP_23K256_SDI_TRIS            TRISFbits.TRISF7

#define MCHP_23K256_SCK_LAT             LATFbits.LATF6
#define MCHP_23K256_SDO_LAT             LATFbits.LATF8
#define MCHP_23K256_SDI_LAT             LATFbits.LATF7

// EPD SPI pins
#define DRV_EPD_SPI_CS_TRIS             TRISBbits.TRISB2
#define DRV_EPD_SPI_CS_LAT              LATBbits.LATB2

#define DRV_EPD_SPI_SCK_TRIS            TRISFbits.TRISF6
#define DRV_EPD_SPI_SDO_TRIS            TRISFbits.TRISF8
#define DRV_EPD_SPI_SDI_TRIS            TRISFbits.TRISF7

#define DRV_EPD_SPI_SCK_LAT             LATFbits.LATF6
#define DRV_EPD_SPI_SDO_LAT             LATFbits.LATF8
#define DRV_EPD_SPI_SDI_LAT             LATFbits.LATF7

// EPD busy pin
#define DRV_EPD_DISPLAY_BUSY_TRIS       TRISDbits.TRISD15
#define DRV_EPD_DISPLAY_BUSY_PORT       PORTDbits.RD15
// EPD reset pin
#define DRV_EPD_DISPLAY_RESET_TRIS      TRISEbits.TRISE8
#define DRV_EPD_DISPLAY_RESET_LAT       LATEbits.LATE8
// EPD PWM pin
#define DRV_EPD_DISPLAY_PWM_TRIS        TRISDbits.TRISD0
#define DRV_EPD_DISPLAY_PWM_LAT         LATDbits.LATD0
// EPD panel on pin
#define DRV_EPD_DISPLAY_PANEL_ON_TRIS   TRISEbits.TRISE9
#define DRV_EPD_DISPLAY_PANEL_ON_LAT    LATEbits.LATE9
// EPD discharge pin
#define DRV_EPD_DISPLAY_DISCHARGE_TRIS  TRISDbits.TRISD14
#define DRV_EPD_DISPLAY_DISCHARGE_LAT   LATDbits.LATD14
// EPD border pin
#define DRV_EPD_DISPLAY_BORDER_TRIS     TRISAbits.TRISA14
#define DRV_EPD_DISPLAY_BORDER_LAT      LATAbits.LATA14
// EPD temperature pin
#define DRV_EPD_DISPLAY_TEMP_TRIS       TRISBbits.TRISB0
#define DRV_EPD_DISPLAY_TEMP_PORT       PORTBbits.RB0

/*********************************************************************
* HARDWARE PROFILE FOR DISPLAY CONTROLLER INTERFACE
*********************************************************************/
/*
    The following defines the different IO signals used to connect
    to the display controller.
    The hardware profile used is dependent on the PIC device
    and the development board used.

    The following are used to control the following signals to the
    Display Controller:
    1. Reset Signal - this signal controls the reset pin of the display
            controller if available.

            Example:
            #define DisplayResetConfig()        TRISAbits.TRISA4 = 0
            #define DisplayResetEnable()        LATAbits.LATA4 = 0
            #define DisplayResetDisable()       LATAbits.LATA4 = 1

    2. Command/Data Signal - this signal indicates to the controller
            if the command or data is being sent to the display controller.

            Example:
            #define DisplayCmdDataConfig()      TRISAbits.TRISA1 = 0
            #define DisplaySetCommand()         LATAbits.LATA1 = 0
            #define DisplaySetData()            LATAbits.LATA1 = 1

    3. Controller Chip Select Signal - this signal controls the chip select
            pin of the display controller is available.

            Example:
            #define DisplayConfig()             TRISBbits.TRISB15 = 0
            #define DisplayEnable()             LATBbits.LATB15 = 0
            #define DisplayDisable()            LATBbits.LATB15 = 1

    4. Display Module Power Control Signal - this signal turns on or off
            the display module if available. In some cases, this can be an
            IO port that will enable the power circuitry of your
            display module.

            Example:
            #define DisplayPowerConfig()        TRISAbits.TRISA5 = 0
            #define DisplayPowerOn()            LATAbits.LATA5 = 1
            #define DisplayPowerOff()           LATAbits.LATA5 = 0

    5. Display Backlight Brightness Control - this controls the backlight
            brightness or ON or OFF states if available. If brightness is
            controllable, this signal may be driven by some PWM signal.

            Example:
            #define DisplayBacklightConfig()    TRISDbits.TRISD0 = 0
            #define DisplayBacklightOn()        LATDbits.LATD0 = 0
            #define DisplayBacklightOff()       LATDbits.LATD0 = 1

*/

    // Depending on the display panel used, the backlight control may be
    // different. This portion sets up the correct backlight level to
    // turn on or off the backlight.
#define BACKLIGHT_ENABLE_LEVEL      0
#define BACKLIGHT_DISABLE_LEVEL     1

// Definitions for reset pin
#define DisplayResetConfig()        TRISCbits.TRISC1 = 0
#define DisplayResetEnable()        LATCbits.LATC1 = 0
#define DisplayResetDisable()       LATCbits.LATC1 = 1

// Definitions for RS pin
#define DisplayCmdDataConfig()      TRISCbits.TRISC2 = 0
#define DisplaySetCommand()         LATCbits.LATC2 = 0
#define DisplaySetData()            LATCbits.LATC2 = 1

// Definitions for CS pin
#define DisplayConfig()             TRISDbits.TRISD10 = 0
#define DisplayEnable()             LATDbits.LATD10 = 0
#define DisplayDisable()            LATDbits.LATD10 = 1

// Definitions for FLASH CS pin
#define DisplayFlashConfig()
#define DisplayFlashEnable()
#define DisplayFlashDisable()

// Definitions for POWER ON pin
#define DisplayPowerConfig()
#define DisplayPowerOn()
#define DisplayPowerOff()

// Definitions for backlight control pin
#define DisplayBacklightConfig()
#define DisplayBacklightOn()
#define DisplayBacklightOff()

#endif




