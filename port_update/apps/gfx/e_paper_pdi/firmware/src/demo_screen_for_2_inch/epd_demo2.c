/**
* \file
*
* \brief The content layout and order of appearance of Demo 2 Bar Chart for 2" EPD
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
#include "epd_demo2.h"
#include "Pervasive_Displays_small_EPD.h"
#include "font_resources_epd_demo.h"
#include "image_resources_epd_2.0_inch_demo.h"



#if (USE_EPD_Type==EPD_200)
#define Barchart_Pos_x  0
#define Barchart_Pos_y  0
#define Bar_Origin_x    5
#define Bar_Origin_y    82
#define Bar_Width       8
#define Bar_Gap_Width   8

GFX_GOL_OBJ_SCHEME      demo2Scheme;

const uint8_t  barValue[][12]={
              {10,10,10,10,10,10,10,10,10,10,10,10},
              {20,20,20,20,20,20,20,20,20,20,20,20},
              {30,20,30,30,30,30,30,30,30,30,30,30},
              {40,20,40,40,40,40,40,40,40,40,40,40},
              {40,20,50,50,50,50,50,50,50,50,50,50},
              {40,20,50,60,60,60,60,60,60,60,60,60},
              {40,20,50,60,70,60,70,70,70,70,70,70},
              {40,20,50,60,70,60,80,80,80,80,80,80},
              {40,20,50,60,70,60,80,90,80,90,90,90},
              {40,20,50,60,70,60,80,90,80,100,100,100},
              {40,20,50,60,70,60,80,90,80,100,110,110},
              {40,20,50,60,70,60,80,90,80,100,110,120}
};
void Show_BG(void);
void Set_BarChart_Value(void);

/**
 * The Demo2 show function
 */
void Show_EPD_Demo2(void)
{

    GFX_GOL_ObjectListFree();
    GFX_ColorSet(WHITE);
    GFX_ScreenClear();
    Show_BG();
    if(GFX_GOL_ObjectListDraw())
        DRV_EPD_UpdateGlobal();
    Set_BarChart_Value();

}

/**
 * Show background image on EPD
 */
void Show_BG(void)
{

    // set style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&demo2Scheme, WHITE, BLACK, WHITE);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&demo2Scheme, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&demo2Scheme, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&demo2Scheme, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&demo2Scheme, (GFX_RESOURCE_HDR*)&Verdana_Bold_12);
    GFX_GOL_SchemeBackgroundTypeSet(&demo2Scheme, GFX_BACKGROUND_NONE);

    GFX_GOL_PictureControlCreate(
        ID_Barchart_BG,                        
        Barchart_Pos_x,
        Barchart_Pos_y,
        Barchart_Pos_x+GLA_barchart_BG_2_inch_WIDTH,
        Barchart_Pos_y+GLA_barchart_BG_2_inch_HEIGHT,
        GFX_GOL_PICTURECONTROL_DRAW_STATE,     
        1,                                     
        (void *)&GLA_barchart_BG_2_inch,       
        &demo2Scheme);                       
}

/**
 * Show bar chart increaing by defined barValue array
 */
void Set_BarChart_Value(void)
{
    int16_t x0,y0,x1,y1;
    int i,j;
 
    EPD_power_init(USE_EPD_Type);

    GFX_ColorSet(BLACK);
    for(j=0;j<12;j++)
    {
        for(i=1;i<13;i++)
        {    
            if(j==0 || (barValue[j-1][i-1] !=barValue[j][i-1]))
            {      
                 x1=Bar_Origin_x+(i*(Bar_Width+Bar_Gap_Width));
                 y1=Bar_Origin_y;
                 x0=x1-Bar_Width;        
                 y0=Bar_Origin_y-(barValue[j][i-1]/2);            
                 GFX_BarDraw(x0,y0,x1,y1);
            }
        }
        if(GFX_GOL_ObjectListDraw()){
              DRV_EPD_UpdatePartial();
        }
    }
   
     EPD_power_end();

}
#endif

