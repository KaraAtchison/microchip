/**
* \file
*
* \brief The content layout and order of appearance of Demo Home menu for 2.7" EPD
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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <xc.h>
#include "gfx/gfx.h"
#include "system_config.h"
#include "epd_demo_home.h"
#include "Pervasive_Displays_small_EPD.h"
#include "font_resources_epd_demo.h"
#include "image_resources_epd_2.7_inch_demo.h"


#if (USE_EPD_Type==EPD_270)
#define PDI_Logo_Pos_X  35
#define PDI_Logo_Pos_Y  10
#define Microchip_Logo_Pos_X  10
#define Microchip_Logo_Pos_Y  110
#define Home_Title1_Pos_X  30
#define Home_Title1_Pos_Y  40
#define Home_Title2_Pos_X  27
#define Home_Title2_Pos_Y  61
#define Home_Title1_Str    (GFX_XCHAR *)"EPD demonstration with"
#define Home_Title2_Str    (GFX_XCHAR *)"Microchip Graphic Library"

#define Button_High        16
#define Button_pos_x       125

#define Button1_pos_x      Button_pos_x
#define Button1_pos_y      84
#define Button1_Str        (GFX_XCHAR *)" Global update    "

#define Button2_pos_x      Button_pos_x
#define Button2_pos_y      Button1_pos_y + Button_High + 2
#define Button2_Str        (GFX_XCHAR *)" Square,Circle    "

#define Button3_pos_x      Button_pos_x
#define Button3_pos_y      Button2_pos_y + Button_High + 2
#define Button3_Str        (GFX_XCHAR *)" Bar Chart        "

#define Button4_pos_x      Button_pos_x
#define Button4_pos_y      Button3_pos_y + Button_High + 2
#define Button4_Str        (GFX_XCHAR *)" A/C Control Panel "

#define Button5_pos_x      Button_pos_x
#define Button5_pos_y      Button4_pos_y + Button_High + 2
#define Button5_Str        (GFX_XCHAR *)" Medical ECG      "

GFX_GOL_OBJ_SCHEME scheme, scheme2;
GFX_GOL_OBJ_SCHEME homeDemoScheme;

void Show_Button(void);
void Show_Logo(void);
//void Update_Home_Button(uint8_t index_select);

void APP_EPD_DemoHomeInit(void)
{

    // set style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&homeDemoScheme, WHITE, BLACK, WHITE);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&homeDemoScheme, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&homeDemoScheme, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&homeDemoScheme, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&homeDemoScheme, (GFX_RESOURCE_HDR*)&Verdana_Bold_12);
    GFX_GOL_SchemeBackgroundTypeSet(&homeDemoScheme, GFX_BACKGROUND_NONE);


    // set style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&scheme, BLACK, WHITE, WHITE);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&scheme, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&scheme, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&scheme, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&scheme, (GFX_RESOURCE_HDR*)&Verdana_Bold_16);
    GFX_GOL_SchemeBackgroundTypeSet(&scheme, GFX_BACKGROUND_NONE);

    // set style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&scheme2, BLACK, WHITE, WHITE);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&scheme2, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&scheme2, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&scheme2, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&scheme2, (GFX_RESOURCE_HDR*)&Verdana_12);
    GFX_GOL_SchemeBackgroundTypeSet(&scheme2, GFX_BACKGROUND_NONE);

}

/**
 * Show an image has Microchip logo, Pervasive Displays logo and QR-Code
 */
void Show_global_image(void)
{
    uint16_t left, top, right, bottom;

    left = (GFX_MaxXGet() - global_image_WIDTH) >> 1;
    top  = (GFX_MaxYGet() - global_image_HEIGHT) >> 1;
    right = left + global_image_WIDTH - 1;
    bottom = top + global_image_HEIGHT - 1;

    GFX_GOL_PictureControlCreate(
        ID_PDI_Logo,
        left, top, right, bottom,
        GFX_GOL_PICTURECONTROL_DRAW_STATE,
        1,                                
        (void *)&global_image,            
        (GFX_GOL_OBJ_SCHEME*)&homeDemoScheme);

    GFX_ColorSet(WHITE);
    GFX_ScreenClear();                          //clear screen of EPD

    if(GFX_GOL_ObjectListDraw())
        DRV_EPD_UpdateGlobal();
}


///**
// * Show Demo_Home screen on EPD and press on which button
// * @param index_select Button index to press
// * @param IsShowButton Show pressed button
// */
//void Show_Home(uint8_t index_select,uint8_t IsShowButton)
//{
//    GFX_GOL_ObjectListFree();
//    GFX_ColorSet(WHITE);
//    GFX_ScreenClear();                          //clear screen of EPD
//
//    Show_Logo();                                // layout logos
//    Show_Button();                              // layout buttons
//    if(GFX_GOL_ObjectListDraw())
//        DRV_EPD_UpdateGlobal();                 //show Demo_home screen
//
//    if(IsShowButton)
//        Update_Home_Button(index_select);       //show pressed button if IsShowButton
//
//    if(index_select==1)
//        Show_global_image();                    //show logos and QR-code image
//}

void APP_EPD_CreateHomeScreen(void)
{
    GFX_GOL_ObjectListFree();
    GFX_ColorSet(WHITE);
    GFX_ScreenClear();                          //clear screen of EPD

    Show_Logo();                                // layout logos
    Show_Button();                              // layout buttons

}

void APP_EPD_CreateGlobalImageScreen(void)
{
    uint16_t left, top, right, bottom;

    GFX_GOL_ObjectListFree();
    GFX_ColorSet(WHITE);
    GFX_ScreenClear();                          //clear screen of EPD

    left = (GFX_MaxXGet() - global_image_WIDTH) >> 1;
    top  = (GFX_MaxYGet() - global_image_HEIGHT) >> 1;
    right = left + global_image_WIDTH - 1;
    bottom = top + global_image_HEIGHT - 1;

    GFX_GOL_PictureControlCreate(
        ID_PDI_Logo,
        left, top, right, bottom,
        GFX_GOL_PICTURECONTROL_DRAW_STATE,
        1,
        (void *)&global_image,
        (GFX_GOL_OBJ_SCHEME*)&homeDemoScheme);

}


/**
 * Layout Microchip and Pervasive Displays logo on EPD
 */
void Show_Logo(void)
{
    GFX_GOL_PictureControlCreate(
        ID_Logo,                           
        PDI_Logo_Pos_X,
        PDI_Logo_Pos_Y,
        PDI_logo_1_WIDTH+PDI_Logo_Pos_X,
        PDI_logo_1_HEIGHT+PDI_Logo_Pos_Y,  
        GFX_GOL_PICTURECONTROL_DRAW_STATE |
        GFX_GOL_PICTURECONTROL_FRAME_STATE,
        1,                                 
        (void *)&PDI_logo_1,               
        &homeDemoScheme);

    GFX_GOL_PictureControlCreate(
        ID_Microchip_Logo,                 
        Microchip_Logo_Pos_X,
        Microchip_Logo_Pos_Y,
        Microchip_logo_1_WIDTH + Microchip_Logo_Pos_X,
        Microchip_logo_1_HEIGHT + Microchip_Logo_Pos_Y,  
        GFX_GOL_PICTURECONTROL_DRAW_STATE |                         
        GFX_GOL_PICTURECONTROL_FRAME_STATE,
        1,                                 
        (void *) &Microchip_logo_1,        
        &homeDemoScheme);

    GFX_GOL_StaticTextCreate(
        ID_HOME_TITLE1,
        Home_Title1_Pos_X, 
        Home_Title1_Pos_Y, 
        Home_Title1_Pos_X + GFX_TextStringWidthGet(
                        Home_Title1_Str,
                        scheme.pFont) + 2,
        Home_Title1_Pos_Y + GFX_TextStringHeightGet(scheme.pFont) + 2,
        GFX_GOL_STATICTEXT_DRAW_STATE,
        Home_Title1_Str,
        GFX_ALIGN_CENTER,
        &scheme);                          

    GFX_GOL_StaticTextCreate(
        ID_HOME_TITLE2,
        Home_Title2_Pos_X, 
        Home_Title2_Pos_Y, 
        Home_Title2_Pos_X + GFX_TextStringWidthGet(
                        Home_Title2_Str,
                        scheme.pFont) + 2,
        Home_Title2_Pos_Y + GFX_TextStringHeightGet(scheme.pFont) + 2,
        GFX_GOL_STATICTEXT_DRAW_STATE,
        Home_Title2_Str,
        GFX_ALIGN_CENTER,
        &scheme);                           
}

///**
// * Show pressed button effect
// * @param index_select Button index to press
// */
//void Update_Home_Button(uint8_t index_select)
//{
//    GFX_GOL_BUTTON *But = NULL;
//
//    switch(index_select)
//     {
//        case 0:
//
//            break;
//        case 1:
//            But=(GFX_GOL_BUTTON *)GFX_GOL_ObjectFind(ID_BUTTON1);
//            break;
//        case 2:
//            But=(GFX_GOL_BUTTON *)GFX_GOL_ObjectFind(ID_BUTTON2);
//            break;
//        case 3:
//            But=(GFX_GOL_BUTTON *)GFX_GOL_ObjectFind(ID_BUTTON3);
//            break;
//        case 4:
//            But=(GFX_GOL_BUTTON *)GFX_GOL_ObjectFind(ID_BUTTON4);
//            break;
//        case 5:
//            But=(GFX_GOL_BUTTON *)GFX_GOL_ObjectFind(ID_BUTTON5);
//            break;
//     }
//
//    if(But != NULL)
//        GFX_GOL_ObjectStateSet(But, GFX_GOL_BUTTON_PRESSED_STATE);
//
//    GFX_GOL_ButtonDraw(But);
//
//    EPD_power_init(USE_EPD_Type);
//
//    if(GFX_GOL_ObjectListDraw())
//        DRV_EPD_UpdatePartial();
//
//    EPD_power_end();
//
//}

/**
 * Layout buttons on EPD
 */
void Show_Button(void)
{
    uint16_t Button_Width, Button_Height;

    Button_Width  = GFX_TextStringWidthGet(Button4_Str, scheme2.pFont) + 8;
    Button_Height = GFX_TextStringHeightGet(scheme2.pFont) + 2;

    GFX_GOL_ButtonCreate(
        ID_BUTTON1,                                    
        Button1_pos_x,
        Button1_pos_y,
        Button1_pos_x + Button_Width,
        Button1_pos_y + Button_Height,
        3,                                             
        GFX_GOL_BUTTON_DRAW_STATE,
        NULL, NULL,                                    
        Button1_Str,                                   
        GFX_ALIGN_LEFT | GFX_ALIGN_VCENTER,
        &scheme2);

     GFX_GOL_ButtonCreate(
        ID_BUTTON2,                                    
        Button2_pos_x,
        Button2_pos_y,
        Button2_pos_x + Button_Width,
        Button2_pos_y + Button_Height,
        3,                                             
        GFX_GOL_BUTTON_DRAW_STATE,
        NULL, NULL,                                    
        Button2_Str,                                   
        GFX_ALIGN_LEFT | GFX_ALIGN_VCENTER,
        &scheme2);

    GFX_GOL_ButtonCreate(
        ID_BUTTON3,                                    
        Button3_pos_x,
        Button3_pos_y,
        Button3_pos_x + Button_Width,
        Button3_pos_y + Button_Height,
        3,                                             
        GFX_GOL_BUTTON_DRAW_STATE,
        NULL, NULL,                                    
        Button3_Str,                                   
        GFX_ALIGN_LEFT | GFX_ALIGN_VCENTER,
        &scheme2);

    GFX_GOL_ButtonCreate(
        ID_BUTTON4,                                    
        Button4_pos_x,
        Button4_pos_y,
        Button4_pos_x + Button_Width,
        Button4_pos_y + Button_Height,
        3,                                             
        GFX_GOL_BUTTON_DRAW_STATE, 
        NULL, NULL,                                    
        Button4_Str,                                   
        GFX_ALIGN_LEFT | GFX_ALIGN_VCENTER,
        &scheme2);

    GFX_GOL_ButtonCreate(
        ID_BUTTON5,                                    
        Button5_pos_x,
        Button5_pos_y,
        Button5_pos_x + Button_Width,
        Button5_pos_y + Button_Height,
        3,                                             
        GFX_GOL_BUTTON_DRAW_STATE,
        NULL, NULL,                                    
        Button5_Str,                                   
        GFX_ALIGN_LEFT | GFX_ALIGN_VCENTER,
        &scheme2);
}
#endif

