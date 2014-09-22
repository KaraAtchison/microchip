/**
* \file
*
* \brief The content layout and order of appearance of Demo 3 HVAC for 2.7" EPD
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
#include "epd_demo3.h"
#include "Pervasive_Displays_small_EPD.h"
#include "font_resources_epd_demo.h"
#include "image_resources_epd_2.7_inch_demo.h"


#if (USE_EPD_Type==EPD_270)
#define AC_BG_Pos_x         0
#define AC_BG_Pos_y         0

#define AC_Fan_Pos_x        200
#define AC_Fan_Pos_y        5

#define Slide_Pos_x         60
#define Slide_Pos_y         65
#define Slide_Width         75
#define Slide_High          22

#define Set_Temp_pos_x      4
#define Set_Temp_pos_y      14

#define Set_Room_Temp_x     105
#define Set_Room_Temp_y     Set_Temp_pos_y

#define RPM_pos_x           190
#define RPM_pos_y           65

#define Energy_pos_x        88
#define Energy_pos_y        95

#define Last_pos_x          Energy_pos_x
#define Last_pos_y          115

#define Avg_pos_x           Energy_pos_x
#define Avg_pos_y           135

#define Est_pos_x           112
#define Est_pos_y           156

#define But_Down_pos_x      7
#define But_Down_pos_y      65
#define But_Down_Str        (GFX_XCHAR *)"DOWN"

#define But_Up_pos_x        140
#define But_Up_pos_y        But_Down_pos_y
#define But_Up_Str          (GFX_XCHAR *)"UP"

const GFX_XCHAR STR_Set_Temp[][3]={
                                {0x22,0x20,0x00},  //20
                                {0x22,0x21,0x00},  //21
                                {0x22,0x22,0x00},  //22
                                {0x22,0x23,0x00},  //23
                                {0x22,0x24,0x00},  //24
                                {0x22,0x25,0x00},  //25
                                {0x22,0x26,0x00},  //26
                                {0x22,0x27,0x00},  //27
                                {0x22,0x28,0x00},  //28
                                {0x22,0x29,0x00},  //29
                                {0x23,0x20,0x00},  //29
                              };
const GFX_XCHAR STR_Room_Temp[][3]={
                                {0x23,0x29,0x00},   //28
                                {0x23,0x28,0x00},   //27
                                {0x23,0x27,0x00},   //26
                                };
const GFX_XCHAR STR_RPM[][5]={"1240\0","1263\0","1285\0","1292\0","1318\0","1346\0","1359\0","1340\0","1311\0","1295\0","1289\0"};
const GFX_XCHAR STR_Energy[][4]={"254\0","255\0","256\0","258\0","259\0","261\0","263\0","262\0","259\0","258\0","257\0"};
const GFX_XCHAR *STR_Last="54";
const GFX_XCHAR *STR_Avg="25";
const GFX_XCHAR STR_Est[][11]={
                            "1.1 vs 0.9\0",
                            "1.2 vs 0.9\0",
                            "1.3 vs 0.9\0",
                            "1.4 vs 0.9\0",
                            "1.5 vs 0.9\0",
                            "1.6 vs 0.9\0",
                            "1.7 vs 0.9\0",
                            "1.8 vs 0.9\0",
                            "1.9 vs 0.9\0",
                            "2.0 vs 0.9\0",
                            "2.1 vs 0.9\0",
                            };

// style schemes
GFX_GOL_OBJ_SCHEME      SliderScheme;
GFX_GOL_OBJ_SCHEME      TextScheme1, TextScheme2, TextScheme3;
GFX_GOL_OBJ_SCHEME      ButtonScheme;
GFX_GOL_OBJ_SCHEME      demo3Scheme;

int16_t                 SliderValue;

GFX_GOL_SCROLLBAR       *pSlider;
GFX_GOL_STATICTEXT      *txt_Set_Temp;
GFX_GOL_STATICTEXT      *txt_Room_Temp;
GFX_GOL_STATICTEXT      *txt_RPM;
GFX_GOL_STATICTEXT      *txt_Energy;
GFX_GOL_STATICTEXT      *txt_Est;
GFX_GOL_PICTURECONTROL  *Pic_Fan;
GFX_GOL_BUTTON          *But_Down,*But_Up;

void Create_Components(void);
void UpdateSlider(void *pObj, uint16_t Value);
void UpdateImage(void *pObj, GFX_RESOURCE_HDR *pImage);
void UpdateText(void *pObj, GFX_XCHAR *pStr);

/**
 * Initial the Demo 3 scheme
 */
void APP_EPD_InitDemo3(void)
{

    // set slider style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&SliderScheme, WHITE, BLACK, WHITE);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&SliderScheme, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&SliderScheme, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&SliderScheme, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&SliderScheme, (GFX_RESOURCE_HDR*)&Verdana_Bold_12);
    GFX_GOL_SchemeBackgroundTypeSet(&SliderScheme, GFX_BACKGROUND_NONE);

    // set text scheme 1 style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&TextScheme1, BLACK, WHITE, BLACK);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&TextScheme1, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&TextScheme1, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&TextScheme1, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&TextScheme1, (GFX_RESOURCE_HDR*)&Verdana_Bold_16);
    GFX_GOL_SchemeBackgroundTypeSet(&TextScheme1, GFX_BACKGROUND_NONE);

    // set text scheme 2 style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&TextScheme2, BLACK, WHITE, BLACK);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&TextScheme2, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&TextScheme2, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&TextScheme2, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&TextScheme2, (GFX_RESOURCE_HDR*)&Verdana_Bold_36_number);
    GFX_GOL_SchemeBackgroundTypeSet(&TextScheme2, GFX_BACKGROUND_NONE);

    // set text scheme 3 style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&TextScheme3, BLACK, WHITE, BLACK);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&TextScheme3, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&TextScheme3, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&TextScheme3, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&TextScheme3, (GFX_RESOURCE_HDR*)&Verdana_12);
    GFX_GOL_SchemeBackgroundTypeSet(&TextScheme3, GFX_BACKGROUND_NONE);

    // set button scheme style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&ButtonScheme, BLACK, WHITE, WHITE);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&ButtonScheme, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&ButtonScheme, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&ButtonScheme, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&ButtonScheme, (GFX_RESOURCE_HDR*)&Verdana_Bold_12);
    GFX_GOL_SchemeBackgroundTypeSet(&ButtonScheme, GFX_BACKGROUND_NONE);

    // set style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&demo3Scheme, WHITE, BLACK, WHITE);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&demo3Scheme, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&demo3Scheme, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&demo3Scheme, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&demo3Scheme, (GFX_RESOURCE_HDR*)&Verdana_Bold_12);
    GFX_GOL_SchemeBackgroundTypeSet(&demo3Scheme, GFX_BACKGROUND_NONE);

}

/**
 * The Demo 3 show function
 */
void APP_EPD_CreateDemo3(void)
{
    GFX_GOL_ObjectListFree();
    SliderValue=5;

    //Create components on background
    Create_Components();

}

bool APP_EPD_DrawCallbackDemo3(void)
{
    static uint16_t imageCount = 0;
    GFX_RESOURCE_HDR *pImage;

    if (imageCount == 0)
    {
        pImage = (GFX_RESOURCE_HDR*)&Fan1;
        imageCount++;
    }
    else if (imageCount == 1)
    {
        pImage = (GFX_RESOURCE_HDR*)&Fan2;
        imageCount++;
    }
    else if (imageCount == 2)
    {
        pImage = (GFX_RESOURCE_HDR*)&Fan3;
        imageCount = 0;
    }

    UpdateImage(Pic_Fan, pImage);

    return true;

}

bool APP_EPD_MessageCallbackDemo3(  GFX_GOL_TRANSLATED_ACTION objectMessage,
                                    GFX_GOL_OBJ_HEADER *pObject,
                                    GFX_GOL_MESSAGE *pMessage)
{
    uint16_t objID;
    bool     updateStatus = false;
    objID = GFX_GOL_ObjectIDGet(pObject);
    
    switch (objID)
    {
        case ID_AC_Up:
            if(objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED)
            {
                SliderValue += 1;
                if (SliderValue >= DEMO3_SLIDER_MAX_VALUE)
                    SliderValue = DEMO3_SLIDER_MAX_VALUE;
                UpdateSlider(pSlider, SliderValue);
                UpdateText(txt_Set_Temp, (GFX_XCHAR *) STR_Set_Temp[SliderValue]);
                UpdateText(txt_RPM, (GFX_XCHAR *) STR_RPM[SliderValue]);
                UpdateText(txt_Energy, (GFX_XCHAR *) STR_Energy[SliderValue]);
                UpdateText(txt_Est, (GFX_XCHAR *) STR_Est[SliderValue]);
            }
            updateStatus = true;
            break;
        case ID_AC_Down:
            if(objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED)
            {
                SliderValue -= 1;
                if (SliderValue <= DEMO3_SLIDER_MIN_VALUE)
                    SliderValue = DEMO3_SLIDER_MIN_VALUE;
                UpdateSlider(pSlider, SliderValue);
                UpdateText(txt_Set_Temp, (GFX_XCHAR *) STR_Set_Temp[SliderValue]);
                UpdateText(txt_RPM, (GFX_XCHAR *) STR_RPM[SliderValue]);
                UpdateText(txt_Energy, (GFX_XCHAR *) STR_Energy[SliderValue]);
                UpdateText(txt_Est, (GFX_XCHAR *) STR_Est[SliderValue]);
            }
            updateStatus = true;
            break;

        default:
            break;
    }
    return (updateStatus);
}

/**
 * Creating components on background
 */
void Create_Components(void)
{
    // sequence of creation will also be the sequence when rendering.
    
    GFX_GOL_PictureControlCreate(
                    ID_AC_BG,
                    AC_BG_Pos_x,
                    AC_BG_Pos_y,
                    AC_BG_Pos_x+GLA_AC_BG_WIDTH,
                    AC_BG_Pos_y+GLA_AC_BG_HEIGHT,
                    GFX_GOL_PICTURECONTROL_DRAW_STATE,
                    1,
                    (void *)&GLA_AC_BG,
                    &demo3Scheme);    

    pSlider = GFX_GOL_ScrollBarCreate(
                    ID_AC_Slide,
                    Slide_Pos_x,
                    Slide_Pos_y,
                    Slide_Pos_x+Slide_Width,
                    Slide_Pos_y+Slide_High,
                    GFX_GOL_SCROLLBAR_DRAW_STATE |
                    GFX_GOL_SCROLLBAR_SLIDER_MODE_STATE,
                    DEMO3_SLIDER_MAX_VALUE, 1, SliderValue,
                    &SliderScheme);

    txt_Set_Temp = GFX_GOL_StaticTextCreate(
                    ID_AC_Set_Temp,
                    Set_Temp_pos_x,
                    Set_Temp_pos_y,
                    Set_Temp_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_Set_Temp[5],
                            TextScheme2.pFont) + 2,
                    Set_Temp_pos_y + GFX_TextStringHeightGet(TextScheme2.pFont),
                    GFX_GOL_STATICTEXT_DRAW_STATE,
                    (GFX_XCHAR *)STR_Set_Temp[5],
                    GFX_ALIGN_CENTER,
                    &TextScheme2);

    txt_Room_Temp = GFX_GOL_StaticTextCreate(
                    ID_AC_Room_Temp,
                    Set_Room_Temp_x,
                    Set_Room_Temp_y,
                    Set_Room_Temp_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_Room_Temp[0],
                            TextScheme2.pFont) + 2,
                    Set_Room_Temp_y + GFX_TextStringHeightGet(TextScheme2.pFont),
                    GFX_GOL_STATICTEXT_DRAW_STATE,
                    (GFX_XCHAR *)STR_Room_Temp[0],
                    GFX_ALIGN_CENTER,
                    &TextScheme2);

    txt_RPM = GFX_GOL_StaticTextCreate(
                    ID_AC_RPM,
                    RPM_pos_x,
                    RPM_pos_y,
                    RPM_pos_x+GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_RPM[5],
                            TextScheme1.pFont) + 2,
                    RPM_pos_y + GFX_TextStringHeightGet(TextScheme1.pFont),
                    GFX_GOL_STATICTEXT_DRAW_STATE,
                    (GFX_XCHAR *)STR_RPM[5],
                    GFX_ALIGN_CENTER,
                    &TextScheme1);

     txt_Energy = GFX_GOL_StaticTextCreate(
                    ID_AC_Energy,
                    Energy_pos_x,
                    Energy_pos_y,
                    Energy_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_Energy[5],
                            TextScheme1.pFont) + 2,
                    Energy_pos_y + GFX_TextStringHeightGet(TextScheme1.pFont),
                    GFX_GOL_STATICTEXT_DRAW_STATE,
                    (GFX_XCHAR *)STR_Energy[5],
                    GFX_ALIGN_CENTER,
                    &TextScheme1);
     
    GFX_GOL_StaticTextCreate(
                    ID_AC_Last,
                    Last_pos_x,
                    Last_pos_y,
                    Last_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_Last,
                            TextScheme1.pFont) + 2,
                    Last_pos_y+GFX_TextStringHeightGet(TextScheme1.pFont),
                    GFX_GOL_STATICTEXT_DRAW_STATE,
                    (GFX_XCHAR *)STR_Last,
                    GFX_ALIGN_CENTER,
                    &TextScheme1);

    GFX_GOL_StaticTextCreate(
                 ID_AC_Avg,
                 Avg_pos_x, 
                 Avg_pos_y, 
                 Avg_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_Avg,
                            TextScheme1.pFont) + 2,
                 Avg_pos_y + GFX_TextStringHeightGet(TextScheme1.pFont),
                 GFX_GOL_STATICTEXT_DRAW_STATE,
                 (GFX_XCHAR *)STR_Avg,
                 GFX_ALIGN_CENTER,
                 &TextScheme1);

     txt_Est = GFX_GOL_StaticTextCreate(
                ID_AC_Est,
                Est_pos_x, 
                Est_pos_y, 
                Est_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_Est[5],
                            TextScheme3.pFont) + 2,
                Est_pos_y + GFX_TextStringHeightGet(TextScheme3.pFont),
                GFX_GOL_STATICTEXT_DRAW_STATE,
                (GFX_XCHAR *)STR_Est[5],
                GFX_ALIGN_CENTER,
                &TextScheme3);

     But_Down = GFX_GOL_ButtonCreate(
                ID_AC_Down,                        
                But_Down_pos_x,
                But_Down_pos_y,
                But_Down_pos_x + GFX_TextStringWidthGet(
                            But_Down_Str,
                            ButtonScheme.pFont) + 2,
                But_Down_pos_y + GFX_TextStringHeightGet(ButtonScheme.pFont) + 5,
                3,                                  
                GFX_GOL_BUTTON_DRAW_STATE,          
                NULL, NULL,                         
                But_Down_Str,                       
                GFX_ALIGN_CENTER,
                &ButtonScheme );

     But_Up = GFX_GOL_ButtonCreate(
                ID_AC_Up,                           
                But_Up_pos_x,
                But_Up_pos_y,
                But_Up_pos_x+GFX_TextStringWidthGet(
                            But_Down_Str,
                            ButtonScheme.pFont) + 2,
                But_Up_pos_y+GFX_TextStringHeightGet(ButtonScheme.pFont) + 5,
                3,                                  
                GFX_GOL_BUTTON_DRAW_STATE,          
                NULL, NULL,                         
                But_Up_Str,                         
                GFX_ALIGN_CENTER,
                &ButtonScheme );

     Pic_Fan=GFX_GOL_PictureControlCreate(
                ID_AC_Fan,
                AC_Fan_Pos_x,
                AC_Fan_Pos_y,
                AC_Fan_Pos_x + Fan1_WIDTH - 1,
                AC_Fan_Pos_y + Fan1_HEIGHT - 1,
                GFX_GOL_PICTURECONTROL_DRAW_STATE,  
                1,                                  
                (void *)&Fan1,                      
                &demo3Scheme);                      
                 
}

/**
 * Update slider status
 * @param pObj the target slider to be updated
 * @param Value slider value
 */
void UpdateSlider(void *pObj, uint16_t Value)
{
    GFX_GOL_ScrollBarPositionSet(pObj, Value);
    GFX_GOL_ObjectStateSet(pObj, GFX_GOL_SCROLLBAR_DRAW_THUMB_STATE);
}

/**
 * Update text
 * @param pObj the target text to be updated
 * @param str the new string
 */
void UpdateText(void *pObj, GFX_XCHAR *pStr)
{
    GFX_GOL_StaticTextSet(pObj, pStr);
    GFX_GOL_ObjectStateSet(pObj, GFX_GOL_STATICTEXT_DRAW_STATE);
}

/**
 * Update image
 * @param pObj the target image to be updated
 * @param image the new image
 */
void UpdateImage(void *pObj, GFX_RESOURCE_HDR *pImage)
{
    GFX_GOL_PictureControlImageSet(pObj, pImage);
    GFX_GOL_ObjectStateSet(pObj, GFX_GOL_PICTURECONTROL_DRAW_STATE);
}


#endif

