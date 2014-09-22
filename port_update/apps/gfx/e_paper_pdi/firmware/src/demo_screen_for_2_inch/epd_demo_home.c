/**
* \file
*
* \brief The content layout and order of appearance of Demo Home menu for 2" EPD
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
#include "image_resources_epd_2.0_inch_demo.h"

#if (USE_EPD_Type==EPD_200)
#define Logo_Pos_X  0
#define Logo_Pos_Y  0
#define Microchip_Logo_Pos_X  10
#define Microchip_Logo_Pos_Y  110
#define Home_Title1_Pos_X  30
#define Home_Title1_Pos_Y  40
#define Home_Title2_Pos_X  27
#define Home_Title2_Pos_Y  61
#define Home_Title1_Str    (GFX_XCHAR *)"EPD demonstration with"
#define Home_Title2_Str    (GFX_XCHAR *)"Microchip Graphic Library"

#define Button_pos_x       7
#define Button_pos_y       55

#define Button1_pos_x      Button_pos_x
#define Button1_pos_y      Button_pos_y
#define Button1_Str        (GFX_XCHAR *)"Square,Circle"

#define Button2_pos_x      Button1_pos_x+10
#define Button2_pos_y      Button1_pos_y
#define Button2_Str        (GFX_XCHAR *)"HVAC Panel"

#define Button3_pos_x      Button_pos_x
#define Button3_pos_y      Button1_pos_y+2
#define Button3_Str        (GFX_XCHAR *)"Bar Chart"

#define Button4_pos_x      Button3_pos_x+10
#define Button4_pos_y      Button3_pos_y
#define Button4_Str        (GFX_XCHAR *)"Medical ECG "

#define Button5_pos_x      Button_pos_x
#define Button5_pos_y      Button4_pos_y+5
#define Button5_Str        (GFX_XCHAR *)" Medical ECG      "


GFX_GOL_OBJ_SCHEME scheme, scheme2;
GFX_GOL_OBJ_SCHEME homeDemoScheme;

void Show_Button(void);
void Show_Logo(void);
void Update_Home_Button(uint8_t index_select);

void EPD_Demo_Home_Init(void)
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

    GFX_GOL_SchemeFontSet(&scheme, (GFX_RESOURCE_HDR*)&Verdana_Bold_14);
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
 * Show Demo_Home image on EPD and press on which button
 * @param index_select Button index to press
 * @param IsShowButton Show pressed button
 */
void Show_Home(uint8_t index_select,uint8_t IsShowButton)
{
   
    GFX_GOL_ObjectListFree();
    GFX_ColorSet(WHITE);
    GFX_ScreenClear();                      //clear screen of EPD
    Show_Logo();                            // layout logos
    Show_Button();                          // layout buttons
    if(GFX_GOL_ObjectListDraw())
        DRV_EPD_UpdateGlobal();             //show Demo_home screen
    if(IsShowButton)
        Update_Home_Button(index_select);   //show pressed button if IsShowButton
}

/**
 * Show Microchip and Pervasive Displays background image on EPD
 */
void Show_Logo(void)
{

    GFX_GOL_PictureControlCreate(
        ID_Logo,
        Logo_Pos_X,
        Logo_Pos_Y,
        GLA_front_menu_BG_2_inch_WIDTH + Logo_Pos_X,
        GLA_front_menu_BG_2_inch_HEIGHT + Logo_Pos_Y,
        GFX_GOL_PICTURECONTROL_DRAW_STATE,
        1,
        (void *)&GLA_front_menu_BG_2_inch,
        (GFX_GOL_OBJ_SCHEME*)&homeDemoScheme);

}

/**
 * Show pressed button effect
 * @param index_select Button index to press
 */
void Update_Home_Button(uint8_t index_select)
{
   GFX_GOL_BUTTON *Button = NULL;

    switch(index_select)
     {   
        case 0:
            break;
        case 1:
            Button=(GFX_GOL_BUTTON *)GFX_GOL_ObjectFind(ID_BUTTON1);
            break;
        case 2:
            Button=(GFX_GOL_BUTTON *)GFX_GOL_ObjectFind(ID_BUTTON3);
            break;
        case 3:
            Button=(GFX_GOL_BUTTON *)GFX_GOL_ObjectFind(ID_BUTTON2);
            break;
        case 4:
            Button=(GFX_GOL_BUTTON *)GFX_GOL_ObjectFind(ID_BUTTON4);
            break;             
     }
    
    if(Button != NULL)
        GFX_GOL_ObjectStateSet(Button, GFX_GOL_BUTTON_PRESSED_STATE);
    
    GFX_GOL_ButtonDraw(Button);
    
    EPD_power_init(USE_EPD_Type);

    if(GFX_GOL_ObjectListDraw())
        DRV_EPD_UpdatePartial();
   
    EPD_power_end();   
}

/**
 * Layout buttons on EPD
 */
void Show_Button(void)
{
    uint16_t Button_Width, Button_Height;

    Button_Width  = GFX_TextStringWidthGet(Button1_Str, scheme2.pFont) + 8;
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
        Button2_pos_x + Button_Width,
        Button2_pos_y,
        Button2_pos_x + Button_Width + Button_Width - 8,
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
        Button3_pos_y + Button_Height,
        Button3_pos_x + Button_Width,
        Button3_pos_y + Button_Height + Button_Height,
        3,
        GFX_GOL_BUTTON_DRAW_STATE,
        NULL, NULL,                                    
        Button3_Str,                                   
        GFX_ALIGN_LEFT | GFX_ALIGN_VCENTER,
        &scheme2);

    GFX_GOL_ButtonCreate(
        ID_BUTTON4,
        Button4_pos_x + Button_Width,
        Button4_pos_y + Button_Height,
        Button4_pos_x + Button_Width + Button_Width - 8,
        Button4_pos_y + Button_Height + Button_Height,
        3,
        GFX_GOL_BUTTON_DRAW_STATE,
        NULL, NULL,                                    
        Button4_Str,                                   
        GFX_ALIGN_LEFT | GFX_ALIGN_VCENTER,
        &scheme2);

}
#endif
