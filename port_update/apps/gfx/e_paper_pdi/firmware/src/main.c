/******************************************************************************
   
PIC24F Starter Kit 1

The PIC24F Starter Kit firmware provides several examples of some of the 
features of Microchip's PIC24F microcontrollers.  The highlighted features 
include:

    - USB Embedded Host and USB Device capability - Your application can
        utilize USB devices, or can become a USB device, by utilizing one
        of the PIC24FJ256GB1 microcontrollers.
    - CTMU - Use capacitive touch sensing to obtain user input, instead of
        switches that can wear out.
    - Peripheral Pin Select - Optimized your output pins by redirecting,
        optimizing, separating, and even overlaying digital pin connections.
    - Parallel Master Port - Communicate easily with sophisticated devices,
        such as graphics displays.
    - Real Time Clock-Calendar - Simplify date and time tracking.
    - Nine independent Output Compare modules - Increase the number and
        complexity of the external devices controlled by your application.

In addition, check out the horsepower of the PIC24F:

    - Plenty of processing power - provide a real-time graphics display and
        monitor user input while capturing time-dependent data and storing it
        to a USB flash drive.
    - Plenty of room for growth - the entire demo (including USB Embedded Host,
        File System, and Graphics libraries), written in C and compiled
        with no optimizations, requires less than half of the available
        program and data memory of the PIC24FJ256GB106.

The structure of this demo matches the layout of the demo.  This file contains
the main line function and coordinates the graphics message and draw
processing.  The other source files are:
    Demos.c     Contains the demonstrations that are accessed via the
                Demos menu selection. These include controlling the RGB LED,
                displaying real-time graphical data, and capturing time
                sensitive data while displaying it graphically and saving it
                to a USB flash drive.
    Flash.c     Contains the demonstrations that are accessed via the
                Flash menu selection.  This includes the USB flash drive
                directory explorer.
    Games.c     Contains the demonstrations that are accessed via the
                Games menu selection.
    Utilities.c Contains the demonstrations that are accessed via the
                Utilities menu selection.  These include setting the current
                time and date, and calibrating the CTMU.

*******************************************************************************/
//DOM-IGNORE-BEGIN
/******************************************************************************

* File Name:       PIC24F Starter Kit.c
* Dependencies:    None
* Processor:       PIC24FJ256GB1
* Compiler:        XC16 v1.11
* Company:         Microchip Technology, Inc.

Software License Agreement

The software supplied herewith by Microchip Technology Incorporated
(the �Company�) for its PICmicro� Microcontroller is intended and
supplied to you, the Company�s customer, for use solely and
exclusively on Microchip PICmicro Microcontroller products. The
software is owned by the Company and/or its supplier, and is
protected under applicable copyright laws. All rights are reserved.
Any use in violation of the foregoing restrictions may subject the
user to criminal sanctions under applicable laws, as well as to
civil liability for the breach of the terms and conditions of this
license.

THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

Author          Date    Comments
--------------------------------------------------------------------------------
KO          14-Feb-2008 First release

*******************************************************************************/

// EPD PICtail Plus Daughter Board_Quick Start Guide
/******************************************************************************
 * This section of quick start guide for the EPD PICtail Plus Daughter Board is
 * made by Pervasive Displays Inc. with its small size EPDs on how to setup the
 * board to Microchip Explorer 16 Development Board (DM240001) via standard
 * PICtail Plus connector which allows evaluating Microchip technology, solution
 * and graphic library for 16 and 32 bits microcontroller.
 *
 * - Firmware code version in this project = v1.02 (16 May, 2014)
 * - MPLAB IDE version = MPLAB X IDE v1.85
 * - Compiler = XC16 v1.21
 * - PDi = Pervasive Displays Inc. http://www.pervasivedisplays.com
 * - EPD = Electronic Paper Display (Electrophoretic Display)
 * - FPL (Front Plane Laminate) supplied by E-Ink
 * - COG = Chip on Glass, the driver IC on EPD module
 * - COG G1 or G2: G is for generation. PDi offers V110 with G1 COG and V230 with G2 COG
 *   EPD to the market.(~2014)
 * - For driving PDi's small size EPDs, please read the "COG Driver Interface
 *   Timing" document(hereinafter COG Document) first. It explains the interface
 *   to the COG driver of EPD for a MCU based solution.
 * - COG G1 Document number: 4P008-00
 *   Download URL: http://www.pervasivedisplays.com/LiteratureRetrieve.aspx?ID=138408
 * - COG G2 Document number: 4P015-00
 *   Download URL: http://www.pervasivedisplays.com/LiteratureRetrieve.aspx?ID=198794
 * - This project code supports EPD size: 1.44 inch, 2 inch and 2.7 inch
 * - Global Update (also known as “Full Update”): to update display from one
 *   previous image to another image and every pixel of entire display has been
 *   refreshed and updated.
 * - Partial Update (also known as “Local Update”) is the process to update
 *   display from one previous image to another image directly but only the
 *   pixels to be changed are updated.
 * - For optical performance and the best contrast ratio quality, PDi recommends
 *   following the standard stage time and running four stages to complete an EPD
 *   global update. Every EPD update, have to do EPD initialization first. After
 *   updating EPD, have to do the power off stage.
 * - This board features partial update technology due to Microchip Graphic
 *   Library is a great fit to do such application.
 * - The difference of Partial Update is if there is next pattern to be updated
 *   on EPD, user is able to write next image data to memory and COG without
 *   power off the COG for better visual experience and faster update time.
 * - We highly recommend after several partial patterns have updated on EPD or
 *   finished a demonstration cycle, it’s better to perform a standard Global
 *   Update stage or Power OFF COG and Power ON while next update to get good
 *   optical performance back. It also improves the ghosting.
 *
 * \section Features
 * - Supports driving 1.44", 2" and 2.7" EPD panels including V110 and V230 FPL
 * - Direct drive EPD by Microchip PIC24 microcontroller without extra graphic
 *   or timing controller
 * - On board 256K bits serial RAM and temperature sensor
 * - On board LDO voltage regulator to 3V for EPD operation
 * - PICtail Plus Interface for connecting to Explorer 16 Development Board
 * - Open documentation and driving waveform for EPD panel
 * - Provides Microchip MPLAB® X project source code with Microchip Graphic Library
 * - Provides global update and partial update driving technology on EPD panels
 *
 * \section File explanation
 * - <b>main.c</b>\n
 *   The entrance file controls all of the demonstrations.
 * - <b>conf_EPD:</b> The EPD configurations.\n
 *   The COG configurations define which COG driving waveform model will be used,
 *   EPD size and the SPI speed
 *   -# COG_VXXX: define which COG driving waveform you will use
 *   -# COG_SPI_baudrate: SPI speed (12MHz)
 *   -# USE_EPD_Type: Using which EPD size for demonstration
 * - <b>Demo Screen for xx inch</b> folder:\n
 *   The content layout and order of appearance for all of the demo screens of 
 *   each EPD size including global update and partial update.
 *   Home menu, logos, Square & circle, GFX_BarDraw chart, HVAC panel, Medical ECG.
 * - <b>gfx</b> folder:\n
 *   The directory of definitions of Graphics Library.
 *     -# <b>resource_EPD_demo:</b>\n
 *        The converted resources of Graphics Resource Converter.
 *     -# <b>GraphicsConfig.h:</b>\n
 *        This file defines all of the configurations of Graphics to enable or
 *        disable the objects and features. The following objects are supported
 *        by EPD demonstration: GOL, button, slider, statictext and picture.
 *     -# <b>HardwareProfile.h:</b>\n
 *        This file defines all of the hardware-specific information for the project.
 *     -# <b>PDI e-paper display_driver:</b>\n
 *       The functions that demonstration will be used for EPD.
 * - <b>Pervasive_Displays_small_EPD</b> folder:\n
 *   All of the COG driving waveforms are located in this folder. Logically 
 *   developer doesn't need to change the codes in this folder in order to keep
 *   correct driving the EPDs.\n\n
 *   <b><em>Software architecture:</em></b>\n
 *   [Application (ex.your host)] <-- [COG Interface (<em>EPD_controller</em>)] <--
 *   [COG Process (<em>EPD_COG_process</em>)] <-- [Hardware Driver (<em>EPD_hardware_driver
 *   & EPD_hardware_gpio</em>)]\n\n
 *    -# <b>EPD_hardware_driver:</b>\n
 *       Most of the COG hardware initialization and configuration. User can 
 *       implement the driver layer of EPD if some variables need to be adjusted.
 *       The provided settings and functions are Timer, SPI, PWM, temperature
 *       and EPD hardware initialization.
 *    -# <b>EPD_hardware_gpio:</b>\n
 *       GPIO pins configuration.
 *    -# <b>EPD_COG_process.h:</b>\n
 *       The common definition of COG driving process.
 *    -# <b>EPD_controller:</b>\n
 *       The application interface for external function to work with EPD.
 *    -# <b>Pervasive_Displays_small_EPD.h:</b>\n
 *       The header file when using PDI’s EPD.
 *    -# <b>SpiRAM:</b>\n
 *       The functions of working with serial RAM.
 *    -# <b>COG</b> folder:\n
 *       Each COG driving file presents the different waveform driving processes
 *       of COG and updating stages.
 *       The parameters of driving different EPD is defined at COG_parameters_t 
 *       structure which is easy for developer adjusting initial parameters,
 *       resolution, frame time of MCU and the size of data line.
 *       - <b>[V110_G1]</b> folder: \n
 *         The EPD has built in E Ink V110 FPL (Front Plane Laminate) with 
 *         version 1 COG by PDI.
 *       - <b>[V230_G2]</b> folder: \n
 *         The EPD has built in E Ink V230 FPL with version 2 COG.
 *
 *       - <b>EPD_COG_process_V110_G1.c:</b>\n
 *         The waveform driving processes and updating stages of G1 COG with
 *         V110 EPD for global update and partial update. *
 *       - <b>EPD_COG_process_V230_G2.c:</b>\n
 *         The waveform driving processes and updating stages of G2 COG with V230 EPD.
 *         User is able to adjust the EPD_WaveformTable structure to fine tune
 *         the update speed or display quality.
 *
 * \section Steps
 * - Before programming firmware onto the MCU of Explorer 16 Development Board,
 *   user should make sure the definition of EPD size and COG version in project
 *   code is same as the connected EPD panel. To do this, please select the correct
 *   EPD size from the pull-down menu of MPLAB X IDE.
 *   To check the configurations, right click on the project name and select
 *   [Set Configuration] / [Customize…] / select one of the conf: item /
 *   [xc16-gcc] / [Preprocessing and messages] option category.
 *   The definition is set in the [Define C macros] item.
 *
 * \section PDi EPD displays
 * ========================================
 * | Size | PDi Model              | FPL  |
 * |------|------------------------|------|
 * | 1.44 | EK014AS014, EK014AS015 | V110 |
 * | 2.0  | EG020AS012, EG020AS013 | V110 |
 * | 2.7  | EM027AS012, EM027AS013 | V110 |
 * | 1.44 | TBD (Q2'14)            | V230 |
 * | 2.0  | EG020BS011, EG020BS012 | V230 |
 * | 2.7  | EM027BS013, EM027BS014 | V230 |
 *
 *
 * For more details on how to work with EPD PICtail Plus Daughter Board, please
 * find and read the user guide in PDi website.
 *
*******************************************************************************/
//DOM-IGNORE-END

#include "system.h"
#include "gfx/gfx.h"
#include <stdint.h>

#include <stdlib.h>
#include <string.h>
#include <libpic30.h>
#include "Pervasive_Displays_small_EPD.h"
#include "epd_demo1.h"
#include "epd_demo2.h"
#include "epd_demo3.h"
#include "epd_demo4.h"
#include "epd_demo_home.h"


//******************************************************************************
//******************************************************************************
// Constants
//******************************************************************************
//******************************************************************************
#define Init_global_image_Pos_X  0
#define Init_global_image_Pos_Y  0

#define APP_DEMO_CHANGE_TIME_DELTA  0x6000
#define APP_DEMO_CHANGE_TIME_DELTA2 0x1000

//******************************************************************************
//******************************************************************************
// Global Variables
//******************************************************************************
//******************************************************************************
DEMO_STATES         screenState             = EPD_DEMO_CREATE_HOME;
DEMO_STATES         next_screenState;
bool                needFullScreenUpdate    = false;
bool                needPartialScreenUpdate = false;

//*****************************************************************************
//******************************************************************************
// Function Prototypes
//******************************************************************************
//******************************************************************************
void wait_next_scheme(void);
void set_Next_Scheme(DEMO_STATES screen, uint32_t wait_time);

/* Required callback functions (note: function name can be any name since
   the callbacks are initialized using:
   - GFX_GOL_MessageCallbackSet(function_name);
   - GFX_GOL_DrawCallbackSet(function_name);
 */
bool APP_ObjectMessageCallback(
                                GFX_GOL_TRANSLATED_ACTION objectMessage,
                                GFX_GOL_OBJ_HEADER *pObject,
                                GFX_GOL_MESSAGE *pMessage);
bool APP_ObjectDrawCallback(void);


int main( void )
{

    // GOL message structure to interact with GOL
    GFX_GOL_MESSAGE msg;

    //clear RESET CONTROL REGISTER
    RCON = 0;

    SYSTEM_InitializeBoard();
   
    // set the message callback function pointer
    GFX_GOL_MessageCallbackSet(APP_ObjectMessageCallback);
    // set the draw callback function pointer
    GFX_GOL_DrawCallbackSet(APP_ObjectDrawCallback);

    APP_EPD_DemoHomeInit();
    APP_EPD_InitDemo3();
    APP_EPD_InitDemo4();

    //set the first demo program
    screenState = EPD_DEMO_CREATE_HOME; //EPD_DEMO1;

    while (1)
    {
#if 0
#if (USE_EPD_Type == EPD_144)

       switch(screenState)
        {                        
            case EPD_DEMO1: //Draw concentric square and circle
                Show_Home(1,true);
                Show_EPD_Demo1();
                set_Next_Scheme(EPD_DEMO2,0);
                break;          
            case EPD_DEMO2: //Bar Chart
                Show_Home(2,true);
                Show_EPD_Demo2();
                set_Next_Scheme(EPD_DEMO3,0);
                break;
            case EPD_DEMO3: //HVAC panel
                Show_Home(3,true);
                Show_EPD_Demo3();
                set_Next_Scheme(EPD_DEMO4,0);
                break;
            case EPD_DEMO4: //ECG medical
                Show_Home(4,true);
                Show_EPD_Demo4();
                set_Next_Scheme(EPD_DEMO1,1000);
                break;
            case EPD_DEMO_NONE:
                break;
        }
#elif (USE_EPD_Type == EPD_200)
       switch(screenState)
        {                        
            case EPD_DEMO1: //Draw concentric square and circle
                Show_Home(1,true);
                Show_EPD_Demo1();
                set_Next_Scheme(EPD_DEMO2,0);
                break;          
            case EPD_DEMO2: //Bar Chart
                Show_Home(2,true);
                Show_EPD_Demo2();
                set_Next_Scheme(EPD_DEMO3,0);
                break;
            case EPD_DEMO3: //HVAC panel
                Show_Home(3,true);
                Show_EPD_Demo3();
                set_Next_Scheme(EPD_DEMO4,0);
                break;
            case EPD_DEMO4: //ECG medical
                Show_Home(4,true);
                Show_EPD_Demo4();
                set_Next_Scheme(EPD_DEMO1,1000);
                break;
            case EPD_DEMO_NONE:
                break;
        }
#elif (USE_EPD_Type == EPD_270)

       switch(screenState)
        {
            case EPD_DEMO1: //Microchip & PDi Logo & QR-Code
                Show_Home(1,true);
                set_Next_Scheme(EPD_DEMO2,0);
                break;
            case EPD_DEMO2: //Draw concentric square and circle
                Show_Home(2,true);
                Show_EPD_Demo1();
                set_Next_Scheme(EPD_DEMO3,0);
                break;
            case EPD_DEMO3: //Bar Chart
                Show_Home(3,true);
                Show_EPD_Demo2();
                set_Next_Scheme(EPD_DEMO4,0);
                break;
            case EPD_DEMO4: //HVAC panel
                Show_Home(4,true);
                Show_EPD_Demo3();
                set_Next_Scheme(EPD_DEMO5,0);
                break;
            case EPD_DEMO5: //ECG medical
                Show_Home(5,true);
                Show_EPD_Demo4();
                set_Next_Scheme(EPD_DEMO1,1000);
                break;
             case EPD_DEMO_NONE:
                break;
        } 


#endif

       wait_next_scheme();
#else

        if(GFX_GOL_ObjectListDraw() == GFX_STATUS_SUCCESS)
        {

            if (needFullScreenUpdate)
            {
                DRV_GFX_UpdateBiStableScreen(true);
                needFullScreenUpdate = false;
            }
            else if (needPartialScreenUpdate)
            {
                DRV_GFX_UpdateBiStableScreen(false);
                needPartialScreenUpdate = false;
            }
            

            TouchGetMsg(&msg);              // Get message from touch screen
            GFX_GOL_ObjectMessage(&msg);    // Process message

        }

    }



#endif




    
}
/**
 * Switch to next demo program, 10ms base
 * @param screen the next EPD demo program
 * @param wait_time
 */
void set_Next_Scheme(DEMO_STATES screen, uint32_t wait_time) {
    displayChangeTime = wait_time;
    if (displayChangeTime > 0)
    {
        previousTick = tick;
        screenState = EPD_DEMO_NONE;
        next_screenState = screen;
    }
    else
    {
        screenState = screen;
    }
}


void wait_next_scheme(void)
{
    if(displayChangeTime == 0)
        return;
    if((tick-previousTick) >= displayChangeTime)
    {
        screenState       = next_screenState;
        displayChangeTime = 0;
    }
}

// *****************************************************************************
/*  Function:
    bool APP_ObjectDrawCallback(void)

    Summary:
        Required application layer function. GFX_GOL_ObjectListDraw()
        function calls it each time when object layer drawing is completed.
        User drawing should be done here. See GFX_GOL_DrawCallbackSet()
        documentation in the Graphics Library Help file for details.

    Parameters:
        None.

    Returns:
        true  - When rendering control will be passed back to object layer
                rendering of the Graphics Library.
        false - When rendering control stays with the application.
                Do this when application needs more time to render.

*/
// *****************************************************************************
bool APP_ObjectDrawCallback(void)
{
    bool status = false;

    switch (screenState)
    {
        case EPD_DEMO_CREATE_HOME:
            APP_EPD_CreateHomeScreen();
            needFullScreenUpdate = true;
            screenState = EPD_DEMO_SHOW_HOME;
            break;

        case EPD_DEMO_SHOW_HOME:
            break;

        case EPD_DEMO_CREATE_GLOBAL_IMAGE:
            APP_EPD_CreateGlobalImageScreen();
            needFullScreenUpdate = true;
            screenState = EPD_DEMO_SHOW_GLOBAL_IMAGE;
            break;

        case EPD_DEMO_SHOW_GLOBAL_IMAGE:
            break;

        case EPD_CREATE_DEMO1:
            APP_EPD_CreateDemo1();
            needFullScreenUpdate = true;
            screenState = EPD_SHOW_DEMO1;
            break;

        case EPD_SHOW_DEMO1:
            APP_EPD_ShowDemo1();
            screenState = EPD_DEMO_CREATE_HOME;
            break;

        case EPD_CREATE_DEMO2:
            APP_EPD_CreateDemo2();
            needFullScreenUpdate = true;
            screenState = EPD_SHOW_DEMO2;
            break;

        case EPD_SHOW_DEMO2:
            APP_EPD_ShowDemo2();
            screenState = EPD_DEMO_CREATE_HOME;
            break;

        case EPD_CREATE_DEMO3:
            APP_EPD_CreateDemo3();
            needFullScreenUpdate = true;
            screenState = EPD_SHOW_DEMO3;
            displayChangeTime = APP_DEMO_CHANGE_TIME_DELTA;
            previousTick = tick;
            break;

        case EPD_SHOW_DEMO3:
            if((tick - previousTick) >= displayChangeTime)
            {
                status = APP_EPD_DrawCallbackDemo3();

                // only update if there was a change in the callback
                if (status)
                    needPartialScreenUpdate = true;

                previousTick = tick;
                displayChangeTime = APP_DEMO_CHANGE_TIME_DELTA;
            }
            break;

        case EPD_CREATE_DEMO4:
            APP_EPD_CreateDemo4();
            needFullScreenUpdate = true;
            screenState = EPD_SHOW_DEMO4;
            displayChangeTime = APP_DEMO_CHANGE_TIME_DELTA2;
            previousTick = tick;
            break;

        case EPD_SHOW_DEMO4:
            if((tick - previousTick) >= displayChangeTime)
            {
                status = APP_EPD_DrawCallbackDemo4();

                // only update if there was a change in the callback
                if (status)
                    needPartialScreenUpdate = true;

                previousTick = tick;
                displayChangeTime = APP_DEMO_CHANGE_TIME_DELTA2;
            }
            break;

        case EPD_DEMO_NONE:
         
            break;
    }

    return true;   // Callback complete
}

// *****************************************************************************
/*  Function:
    bool APP_ObjectMessageCallback(
                                GFX_GOL_TRANSLATED_ACTION objectMessage,
                                GFX_GOL_OBJ_HEADER *pObject,
                                GFX_GOL_MESSAGE *pMessage)

    Summary:
        Required application layer function. GFX_GOL_ObjectMessage()
        function calls this function each time a valid message for the
        object is received. See GFX_GOL_MessageCallbackSet()
        documentation in the Graphics Library Help file for details.

    Parameters:
        objectMessage - translated message for the object,
        pObject - pointer to the object,
        pMessage - pointer to the non-translated, raw GOL message

    Returns:
        true  - The message will be processed using default settings
        false - The message will not be processed by object layer
                and application may or may not process the message.

*/
// *****************************************************************************
bool APP_ObjectMessageCallback(
                                GFX_GOL_TRANSLATED_ACTION objectMessage,
                                GFX_GOL_OBJ_HEADER *pObject,
                                GFX_GOL_MESSAGE *pMessage)
{
//    static  uint16_t index = 1;
//            GFX_GOL_BUTTON *But = NULL;

    uint16_t objID;

    objID = GFX_GOL_ObjectIDGet(pObject);

    switch (screenState)
    {
        case EPD_DEMO_CREATE_HOME:
            break;

        case EPD_DEMO_SHOW_HOME:

            // check if the buttons needs to be refreshed
            switch (objID)
            {
                case ID_BUTTON1:
                case ID_BUTTON2:
                case ID_BUTTON3:
                case ID_BUTTON4:
                case ID_BUTTON5:

                    if(
                        (objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED) ||
                        (objectMessage == GFX_GOL_BUTTON_ACTION_PRESSED)  ||
                        (objectMessage == GFX_GOL_BUTTON_ACTION_CANCELPRESS)
                      )
                    {
                        needPartialScreenUpdate = true;

                        // check if the a new screen is needed
                        if (    (objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED) &&
                                (objID         == ID_BUTTON1))
                        {
                            screenState = EPD_DEMO_CREATE_GLOBAL_IMAGE;
                        }
                        else if((objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED) &&
                                (objID         == ID_BUTTON2))
                        {
                            screenState = EPD_CREATE_DEMO1;
                        }
                        else if((objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED) &&
                                (objID         == ID_BUTTON3))
                        {
                            screenState = EPD_CREATE_DEMO2;
                        }
                        else if((objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED) &&
                                (objID         == ID_BUTTON4))
                        {
                            screenState = EPD_CREATE_DEMO3;
                        }
                        else if((objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED) &&
                                (objID         == ID_BUTTON5))
                        {
                            screenState = EPD_CREATE_DEMO4;
                        }

                    }
                    else
                    {
                        return false;
                    }
                    break;

                default:
                        return false;
            }
            
            break;

        case EPD_DEMO_CREATE_GLOBAL_IMAGE:
            break;

        case EPD_DEMO_SHOW_GLOBAL_IMAGE:

            if (    (objectMessage == GFX_GOL_PICTURECONTROL_ACTION_SELECTED) &&
                    (objID         == ID_PDI_Logo))
            {
                screenState = EPD_DEMO_CREATE_HOME;
            }
            break;

        case EPD_CREATE_DEMO1:
            break;

        case EPD_SHOW_DEMO1:
            break;

        case EPD_CREATE_DEMO2:
            break;

        case EPD_SHOW_DEMO2:
            break;

        case EPD_CREATE_DEMO3:
            break;

        case EPD_SHOW_DEMO3:
            if (APP_EPD_MessageCallbackDemo3(objectMessage, pObject, pMessage) == true)
            {
                needPartialScreenUpdate = true;
                // slow down the animation so it does not affect timing of touch
                displayChangeTime = APP_DEMO_CHANGE_TIME_DELTA;
                previousTick = tick;
            }
            else
            {
                // check to return to main menu is selected
                if ( (objID         == ID_AC_Fan) &&
                     (objectMessage == GFX_GOL_PICTURECONTROL_ACTION_SELECTED)
                   )
                {
                    screenState = EPD_DEMO_CREATE_HOME;
                }

            }
            break;

        case EPD_CREATE_DEMO4:
            break;

        case EPD_SHOW_DEMO4:
            // check to return to main menu is selected
            if ( (objID         == ID_GLA_ECG_BG) &&
                 (objectMessage == GFX_GOL_PICTURECONTROL_ACTION_SELECTED)
               )
            {
                screenState = EPD_DEMO_CREATE_HOME;
            }
            break;

        case EPD_DEMO_NONE:
            break;

        default:
            break;
    }

    return true;   // Callback complete

}




