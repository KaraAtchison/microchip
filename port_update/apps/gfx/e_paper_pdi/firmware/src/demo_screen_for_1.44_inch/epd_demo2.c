/**
* \file
*
* \brief The content layout and order of appearance of Demo 2 Bar Chart for 1.44" EPD
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
#define Barchart_Pos_x  0
#define Barchart_Pos_y  0
#define Bar_Origin_x    7
#define Bar_Origin_y    82
#define Bar_Width       8
#define Bar_Gap_Width   8
const uint8_t  barValue[][9]={
              {10,10,10,10,10,10,10},
              {20,20,20,20,20,20,20},
              {30,20,30,30,30,30,30},
              {40,20,40,40,40,40,40},
              {40,20,50,50,50,50,50},
              {40,20,50,60,60,60,60},
              {40,20,50,60,70,70,70},
              {40,20,50,60,70,80,80},
              {40,20,50,60,70,80,90}
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
    Show_BG();  //Show background first using global update
    if(GFX_GOL_ObjectListDraw())
        DRV_EPD_UpdateGlobal();

    //Show bar chart by partial update
    Set_BarChart_Value();
}

/**
 * Show background image on EPD
 */
void Show_BG(void)
{
   PictCreate
        (ID_Barchart_BG,                      // ID
         Barchart_Pos_x,
         Barchart_Pos_y,
         Barchart_Pos_x+GLA_barchart_BG_144inch_WIDTH,
         Barchart_Pos_y+GLA_barchart_BG_144inch_HEIGHT, // dimension
         PICT_DRAW,                        // will be dislayed, has frame
         1,                                // scale factor is x1
         (void *)&GLA_barchart_BG_144inch,         // bitmap
         NULL 
         );                                // default GOL scheme
    
}

/**
 * Show bar chart increaing by defined barValue array
 */
void Set_BarChart_Value(void)
{
    SHORT x0,y0,x1,y1;
    int i,j;
 
    EPD_power_init(USE_EPD_Type);

    GFX_ColorSet(BLACK);
    for(j=0;j<9;j++)
    {
        for(i=1;i<8;i++)
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

