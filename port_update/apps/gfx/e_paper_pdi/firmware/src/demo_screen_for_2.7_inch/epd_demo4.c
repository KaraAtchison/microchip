/**
* \file
*
* \brief The content layout and order of appearance of Demo4: Medical for 2.7" EPD
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
#include "epd_demo4.h"
#include "Pervasive_Displays_small_EPD.h"
#include "font_resources_epd_demo.h"
#include "image_resources_epd_2.7_inch_demo.h"


#if (USE_EPD_Type==EPD_270)
#define GLA_ECG_Pos_X       0
#define GLA_ECG_Pos_Y       0
#define ECG_Image_Pos_X     3
#define ECG_Image_Pos_Y     10
#define ECG_Heart_Pos_X     243
#define ECG_Heart_Pos_Y     143

#define High_gap            17
#define ECG_PR_pos_x        45
#define ECG_PR_pos_y        106
#define ECG_QRS_pos_x       ECG_PR_pos_x
#define ECG_QRS_pos_y       ECG_PR_pos_y+High_gap
#define ECG_QT_pos_x        ECG_PR_pos_x
#define ECG_QT_pos_y        ECG_QRS_pos_y+High_gap
#define ECG_RR_pos_x        ECG_PR_pos_x
#define ECG_RR_pos_y        ECG_QT_pos_y+High_gap

#define ECG_Peak_pos_x      168
#define ECG_Peak_pos_y      117 
#define ECG_Yst_pos_x       216
#define ECG_Yst_pos_y       ECG_Peak_pos_y

#define ECG_Temp_pos_x      95
#define ECG_Temp_pos_y      110

#define ECG_SYS_pos_x       95
#define ECG_SYS_pos_y       147
#define ECG_DIA_pos_x       143
#define ECG_DIA_pos_y       ECG_SYS_pos_y
#define ECG_PUL_pos_x       195
#define ECG_PUL_pos_y       ECG_SYS_pos_y

#define ECG_Appear_Pixels   15
#define ECG_Demo_Count      17

const GFX_XCHAR STR_PR[][5]={"0.18\0","0.19\0","0.17\0"};
const GFX_XCHAR STR_QRS[][5]={"0.09\0","0.10\0","0.11\0"};
const GFX_XCHAR STR_QT[][5]={"0.40\0","0.38\0","0.37\0"};
const GFX_XCHAR STR_RR[][5]={"0.65\0","0.63\0","0.68\0"};

const GFX_XCHAR STR_Peak[][5]={"99.1\0","99.2\0","98.6\0"};
const GFX_XCHAR STR_Yst[][5]={"98.3\0","98.1\0","98.7\0"};

const GFX_XCHAR STR_Temp[][5]={"98.7\0","99.2\0","98.1\0"};
const GFX_XCHAR STR_SYS[][5]={"118\0","119\0","117\0"};
const GFX_XCHAR STR_DIA[][4]={"78\0","79\0","78\0"};
const GFX_XCHAR STR_PUL[][4]={"70\0","71\0","72\0"};

GFX_GOL_OBJ_SCHEME          TextScheme4, TextScheme5;
GFX_GOL_OBJ_SCHEME          demo4Scheme;

GFX_GOL_STATICTEXT          *txt_PR;
GFX_GOL_STATICTEXT          *txt_QRS;
GFX_GOL_STATICTEXT          *txt_QT;
GFX_GOL_STATICTEXT          *txt_RR;
GFX_GOL_STATICTEXT          *txt_Temp_F;
GFX_GOL_STATICTEXT          *txt_Peak;
GFX_GOL_STATICTEXT          *txt_Yst;
GFX_GOL_STATICTEXT          *txt_SYS;
GFX_GOL_STATICTEXT          *txt_DIA;
GFX_GOL_STATICTEXT          *txt_PUL;
GFX_GOL_PICTURECONTROL      *Pic_heart;

void Create_ECG_Components(void);
void show_ECG_BG(void);
void Show_ECG_Image(void);
void Demo4_Activity(int Select_index);

/**
 * Initial the Demo 4 scheme
 */
void APP_EPD_InitDemo4(void)
{

    // set style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&demo4Scheme, WHITE, BLACK, WHITE);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&demo4Scheme, WHITE, WHITE, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&demo4Scheme, WHITE);

    // set the emboss colors and size 
    GFX_GOL_SchemeEmbossSet(&demo4Scheme, WHITE, WHITE, 0);

    GFX_GOL_SchemeFontSet(&demo4Scheme, (GFX_RESOURCE_HDR*)&Verdana_12);
    GFX_GOL_SchemeBackgroundTypeSet(&demo4Scheme, GFX_BACKGROUND_NONE);


    // set text scheme 4 style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&TextScheme4, BLACK, BLACK, WHITE);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&TextScheme4, BLACK, BLACK, BLACK);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&TextScheme4, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&TextScheme4, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&TextScheme4, (GFX_RESOURCE_HDR*)&Verdana_Bold_14);
    GFX_GOL_SchemeBackgroundTypeSet(&TextScheme4, GFX_BACKGROUND_NONE);


    // set text scheme 5 style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&TextScheme5, BLACK, WHITE, BLACK);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&TextScheme5, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&TextScheme5, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&TextScheme5, BLACK, BLACK, 0);

    GFX_GOL_SchemeFontSet(&TextScheme5, (GFX_RESOURCE_HDR*)&Verdana_12);
    GFX_GOL_SchemeBackgroundTypeSet(&TextScheme5, GFX_BACKGROUND_NONE);

}

/**
 * The Demo 4 show function
 */
void APP_EPD_CreateDemo4(void)
{
    GFX_GOL_ObjectListFree();
    show_ECG_BG();
    Show_ECG_Image();

    // Draw components on background
    Create_ECG_Components();

}

bool APP_EPD_DrawCallbackDemo4(void)
{
    static uint16_t selectIndex = 0;


    if (selectIndex < ECG_Demo_Count)
    {
        Demo4_Activity(selectIndex);
        selectIndex++;
    }
    else
    {
        GFX_ColorSet(WHITE);
        GFX_RectangleFillDraw(  ECG_Image_Pos_X,
                                ECG_Image_Pos_Y,
                                GFX_MaxXGet() - ECG_Image_Pos_X,
                                ECG_Image_Pos_Y + ECG_HEIGHT);
        selectIndex = 0;
    }

    return true;

}


/**
 * Show background image on EPD
 */
void show_ECG_BG(void)
{   
    GFX_GOL_PictureControlCreate(
        ID_GLA_ECG_BG,                      
        GLA_ECG_Pos_X,
        GLA_ECG_Pos_Y,
        GLA_ECG_BG_WIDTH + GLA_ECG_Pos_X,
        GLA_ECG_BG_HEIGHT + GLA_ECG_Pos_Y,
        GFX_GOL_PICTURECONTROL_DRAW_STATE,
        1,                                  
        (GFX_RESOURCE_HDR*)&GLA_ECG_BG,
        (GFX_GOL_OBJ_SCHEME*)&demo4Scheme);
}

/**
 * Creating components on background
 */
void Create_ECG_Components(void)
{
    txt_PR = GFX_GOL_StaticTextCreate(
        ID_ECG_PR,
        ECG_PR_pos_x, 
        ECG_PR_pos_y, 
        ECG_PR_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_PR[0],
                            TextScheme5.pFont) + 2,
        ECG_PR_pos_y + GFX_TextStringHeightGet(TextScheme5.pFont),
        GFX_GOL_STATICTEXT_DRAW_STATE,
        (GFX_XCHAR *)STR_PR[0],
        GFX_ALIGN_CENTER,
        (GFX_GOL_OBJ_SCHEME*)&TextScheme5);

    txt_QRS = GFX_GOL_StaticTextCreate(
        ID_ECG_QRS,
        ECG_QRS_pos_x, 
        ECG_QRS_pos_y, 
        ECG_QRS_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_QRS[0],
                            TextScheme5.pFont) + 2,
        ECG_QRS_pos_y+GFX_TextStringHeightGet(TextScheme5.pFont),
        GFX_GOL_STATICTEXT_DRAW_STATE,
        (GFX_XCHAR *)STR_QRS[0],
        GFX_ALIGN_CENTER,
        (GFX_GOL_OBJ_SCHEME*)&TextScheme5);

    txt_QT = GFX_GOL_StaticTextCreate(
        ID_ECG_QT,
        ECG_QT_pos_x, 
        ECG_QT_pos_y, 
        ECG_QT_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_QT[0],
                            TextScheme5.pFont) + 2,
        ECG_QT_pos_y + GFX_TextStringHeightGet(TextScheme5.pFont),
        GFX_GOL_STATICTEXT_DRAW_STATE,
        (GFX_XCHAR *)STR_QT[0],
        GFX_ALIGN_CENTER,
        (GFX_GOL_OBJ_SCHEME*)&TextScheme5);

    txt_RR = GFX_GOL_StaticTextCreate(
        ID_ECG_RR,
        ECG_RR_pos_x, 
        ECG_RR_pos_y, 
        ECG_RR_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_RR[0],
                            TextScheme5.pFont) + 2,
        ECG_RR_pos_y + GFX_TextStringHeightGet(TextScheme5.pFont),
        GFX_GOL_STATICTEXT_DRAW_STATE,
        (GFX_XCHAR *)STR_RR[0],
        GFX_ALIGN_CENTER,
        (GFX_GOL_OBJ_SCHEME*)&TextScheme5);

    txt_Peak = GFX_GOL_StaticTextCreate(
        ID_ECG_Peak,
        ECG_Peak_pos_x, 
        ECG_Peak_pos_y, 
        ECG_Peak_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_Peak[0],
                            TextScheme5.pFont) + 2,
        ECG_Peak_pos_y + GFX_TextStringHeightGet(TextScheme5.pFont),
        GFX_GOL_STATICTEXT_DRAW_STATE,
        (GFX_XCHAR *)STR_Peak[0],
        GFX_ALIGN_CENTER,
        (GFX_GOL_OBJ_SCHEME*)&TextScheme5);

    txt_Yst = GFX_GOL_StaticTextCreate(
        ID_ECG_Yst,
        ECG_Yst_pos_x,
        ECG_Yst_pos_y,
        ECG_Yst_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_Yst[0],
                            TextScheme5.pFont) + 2,
        ECG_Yst_pos_y + GFX_TextStringHeightGet(TextScheme5.pFont),
        GFX_GOL_STATICTEXT_DRAW_STATE,
        (GFX_XCHAR *)STR_Yst[0],
        GFX_ALIGN_CENTER,
        (GFX_GOL_OBJ_SCHEME*)&TextScheme5);

    txt_SYS = GFX_GOL_StaticTextCreate(
        ID_ECG_SYS,
        ECG_SYS_pos_x,
        ECG_SYS_pos_y,
        ECG_SYS_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_SYS[0],
                            TextScheme4.pFont) + 2,
        ECG_SYS_pos_y + GFX_TextStringHeightGet(TextScheme4.pFont),
        GFX_GOL_STATICTEXT_DRAW_STATE,
        (GFX_XCHAR *)STR_SYS[0],
        GFX_ALIGN_CENTER,
        (GFX_GOL_OBJ_SCHEME*)&TextScheme4);

    txt_DIA = GFX_GOL_StaticTextCreate(
        ID_ECG_DIA,
        ECG_DIA_pos_x,
        ECG_DIA_pos_y,
        ECG_DIA_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_DIA[0],
                            TextScheme4.pFont) + 2,
        ECG_DIA_pos_y + GFX_TextStringHeightGet(TextScheme4.pFont),
        GFX_GOL_STATICTEXT_DRAW_STATE,
        (GFX_XCHAR *)STR_DIA[0],
        GFX_ALIGN_CENTER,
        (GFX_GOL_OBJ_SCHEME*)&TextScheme4);

     txt_PUL = GFX_GOL_StaticTextCreate(
        ID_ECG_PUL,
        ECG_PUL_pos_x,
        ECG_PUL_pos_y,
        ECG_PUL_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_PUL[0],
                            TextScheme4.pFont) + 2,
        ECG_PUL_pos_y + GFX_TextStringHeightGet(TextScheme4.pFont),
        GFX_GOL_STATICTEXT_DRAW_STATE, 
        (GFX_XCHAR *)STR_PUL[0],
        GFX_ALIGN_CENTER,
        (GFX_GOL_OBJ_SCHEME*)&TextScheme4);

     txt_Temp_F = GFX_GOL_StaticTextCreate(
        ID_ECG_TEMP,
        ECG_Temp_pos_x,
        ECG_Temp_pos_y,
        ECG_Temp_pos_x + GFX_TextStringWidthGet(
                            (GFX_XCHAR *)STR_Temp[0],
                            TextScheme4.pFont) + 2,
        ECG_Temp_pos_y + GFX_TextStringHeightGet(TextScheme4.pFont),
        GFX_GOL_STATICTEXT_DRAW_STATE,
        (GFX_XCHAR *)STR_Temp[0],
        GFX_ALIGN_CENTER,
        (GFX_GOL_OBJ_SCHEME*)&TextScheme4);
}

/**
 * Show ECG image on top of background
 */
void Show_ECG_Image(void)
{

    Pic_heart = GFX_GOL_PictureControlCreate(
        ID_ECG_Heart,                      
        ECG_Heart_Pos_X,
        ECG_Heart_Pos_Y,
        heart0_WIDTH + ECG_Heart_Pos_X,
        heart0_HEIGHT + ECG_Heart_Pos_Y,
        GFX_GOL_PICTURECONTROL_DRAW_STATE,
        1,                                 
        (GFX_RESOURCE_HDR*)&heart0,
        (GFX_GOL_OBJ_SCHEME*)&demo4Scheme);
}

/**
 * Update the heart image
 * @param pObj the target image to be updated
 * @param image the new image
 */
void Update_Heart_Image(GFX_GOL_PICTURECONTROL *pObj, GFX_RESOURCE_HDR *pImage)
{
    GFX_GOL_PictureControlImageSet(pObj, pImage);
    GFX_GOL_ObjectStateSet(pObj, GFX_GOL_PICTURECONTROL_DRAW_STATE);
}

/**
 * Sequential appearance of the ECG image from left to right
 * @param pObj the target image to be updated
 * @param x_pos the x position
 * @param xoffset the x offset of image
 * @param width per appeared pixels
 */
void Update_ECG_Image(  GFX_RESOURCE_HDR *pImage,
                        int16_t x_pos,
                        int16_t xoffset,
                        uint16_t width)
{
    GFX_STATUS status;

    status = GFX_ImagePartialDraw(
                            x_pos + ECG_Image_Pos_X,
                            ECG_Image_Pos_Y,
                            xoffset,
                            0,
                            width,
                            ECG_HEIGHT,
                            pImage
                        );
}

/**
 * Update text
 * @param pObj the target text to be updated
 * @param str the new string
 */
void Update_Text(void *pObj, GFX_XCHAR * str)
{
    GFX_GOL_StaticTextSet(pObj, str);
    GFX_GOL_ObjectStateSet(pObj, GFX_GOL_STATICTEXT_DRAW_STATE);
}

/**
 * The order of appearance of demo4: ECG medical
 * @param Select_index demo step
 */
void Demo4_Activity(int Select_index) {

    Update_ECG_Image((GFX_RESOURCE_HDR *) & ECG,
            (Select_index * ECG_Appear_Pixels),
            (Select_index * ECG_Appear_Pixels),
            ECG_Appear_Pixels);

    switch (Select_index) {
        case 0:
        case 1:
        case 2:
            break;

        case 3:
            Update_Heart_Image(Pic_heart, (void *) &heart1);
            break;

        case 4:
            Update_Heart_Image(Pic_heart, (void *) &heart0);
            Update_Text(txt_PR, (GFX_XCHAR *) STR_PR[1]);
            break;

        case 5:
            Update_Text(txt_DIA, (GFX_XCHAR *) STR_DIA[1]);
            Update_Text(txt_SYS, (GFX_XCHAR *) STR_SYS[1]);
            break;

        case 6:
            Update_Text(txt_QRS, (GFX_XCHAR *) STR_QRS[1]);
            break;

        case 7:
            Update_Text(txt_QT, (GFX_XCHAR *) STR_QT[1]);
            Update_Text(txt_PUL, (GFX_XCHAR *) STR_PUL[1]);
            break;

        case 8:
            Update_Text(txt_RR, (GFX_XCHAR *) STR_RR[1]);
            break;

        case 9:
            Update_Heart_Image(Pic_heart, (void *) &heart1);
            break;

        case 10:
            Update_Heart_Image(Pic_heart, (void *) &heart0);
            Update_Text(txt_PR, (GFX_XCHAR *) STR_PR[2]);
            break;

        case 11:
            Update_Text(txt_Temp_F, (GFX_XCHAR *) STR_Temp[1]);
            Update_Text(txt_Peak, (GFX_XCHAR *) STR_Peak[1]);
            Update_Text(txt_SYS, (GFX_XCHAR *) STR_SYS[2]);
            break;

        case 12:
            Update_Text(txt_DIA, (GFX_XCHAR *) STR_DIA[2]);
            Update_Text(txt_QRS, (GFX_XCHAR *) STR_QRS[2]);
            break;

        case 13:
            Update_Text(txt_QT, (GFX_XCHAR *) STR_QT[2]);
            break;

        case 14:
            Update_Text(txt_RR, (GFX_XCHAR *) STR_RR[2]);
            Update_Text(txt_PUL, (GFX_XCHAR *) STR_PUL[2]);
            break;

        case 15:
            Update_Heart_Image(Pic_heart, (void *) &heart1);
            break;

        case 16:
            Update_Text(txt_Temp_F, (GFX_XCHAR *) STR_Temp[2]);
            Update_Text(txt_Yst, (GFX_XCHAR *) STR_Yst[1]);
            Update_Heart_Image(Pic_heart, (void *) &heart0);
            break;

        case 17:
            break;
    }
}
#endif

