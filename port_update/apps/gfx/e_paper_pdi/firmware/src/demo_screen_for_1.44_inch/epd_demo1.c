/**
*
* \brief Draw concentric square and circle of Demo 1 for 1.44" EPD
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
#include <p24Fxxxx.h>
#include <libpic30.h>
#include "system_config.h"
#include "Pervasive_Displays_small_EPD.h"
#include "resources_epd_demo.h"

#if (USE_EPD_Type==EPD_144)
#define Demo_EPD_horizontal      COG_parameters[USE_EPD_Type].horizontal_size*8
#define Demo_EPD_vertical        COG_parameters[USE_EPD_Type].vertical_size
#define Draw_Interval  5    //interval of drawing each concentric square or circle

/**
 * Clean EPD screen by partial update
 */
void clean_Screen(void)
{
    GFX_ColorSet(BLACK);
    GFX_ScreenClear();
    if(GFX_GOL_ObjectListDraw())
    {
        DRV_EPD_UpdatePartial();
    }

    GFX_ColorSet(WHITE); 
    GFX_ScreenClear();
    if(GFX_GOL_ObjectListDraw())
    {
        DRV_EPD_UpdatePartial();
    }
}

/**
 * Draw square on EPD by partial update
 * @param index the top/left position
 * @param color square color
 */
void Draw_Bevel(int index,uint8_t color)
{
    GFX_ColorSet(color);
    GFX_RectangleRoundDraw(index,index,Demo_EPD_horizontal-index,Demo_EPD_vertical-index,0);
    if(GFX_GOL_ObjectListDraw())
    {
        DRV_EPD_UpdatePartial();
    }
}


/**
 * Draw concentric square between Draw_Interval,
 * Appear(Black) and disappear(white)
 */
void Draw_Bevel_Screen(void)
{
     int i,cnt;
     cnt=(Demo_EPD_vertical/(Draw_Interval*2));

     EPD_power_init(USE_EPD_Type);
   
     for(i=1;i<(cnt+1);i++)
     {
       Draw_Bevel((i*Draw_Interval),BLACK);
     }
     /*
     for(i=cnt;i>0;i--)
     {
      Draw_Bevel((i*Draw_Interval),WHITE);
     }
      */
}

/**
 * Draw circle on EPD by partial update
 * @param index the radius of the arc
 * @param color square color
 */
void Draw_Arc(int index,uint8_t color)
{
    GFX_ColorSet(color);
    //DrawArc((Demo_EPD_horizontal/2),(Demo_EPD_vertical/2),index,index,0,360);
    GFX_CircleDraw((Demo_EPD_horizontal>>1),(Demo_EPD_vertical>>1),index);

    if(GFX_GOL_ObjectListDraw())
    {
        DRV_EPD_UpdatePartial();
    }
}

/**
 * Draw concentric circle between Draw_Interval,
 */
void Draw_Arc_Screen(void)
{
     int i,cnt;
     cnt=(Demo_EPD_vertical/(Draw_Interval*2));
     clean_Screen();
     for(i=cnt;i>0;i--)
     {
         Draw_Arc((i*Draw_Interval),BLACK);
     }
  
     EPD_power_end();

}

/**
 * The Demo1 show function
 */
void Show_EPD_Demo1(void)
{
    GFX_GOL_ObjectListFree();
    GFX_ColorSet(WHITE);
    GFX_ScreenClear(); 
    if(GFX_GOL_ObjectListDraw())
        DRV_EPD_UpdateGlobal();
    Draw_Bevel_Screen();
    Draw_Arc_Screen();
}

#endif 


