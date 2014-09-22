/**
 *
* \brief The content layout and order of appearance of Demo4: Medical for 1.44" EPD
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
#define GLA_ECG_Pos_X       0
#define GLA_ECG_Pos_Y       0
#define ECG_Image_Pos_X     6
#define ECG_Image_Pos_Y     3
#define ECG_Heart_Pos_X     109
#define ECG_Heart_Pos_Y     78

#define High_gap            20
#define ECG_PR_pos_x        30
#define ECG_PR_pos_y        4

#define ECG_QRS_pos_x       ECG_PR_pos_x+65
#define ECG_QRS_pos_y       ECG_PR_pos_y

#define ECG_QT_pos_x        ECG_PR_pos_x
#define ECG_QT_pos_y        ECG_PR_pos_y+20

#define ECG_RR_pos_x        ECG_QT_pos_x+65
#define ECG_RR_pos_y        ECG_QT_pos_y


#define ECG_Temp_pos_x      3
#define ECG_Temp_pos_y      50

#define ECG_SYS_pos_x       25
#define ECG_SYS_pos_y       75

#define ECG_DIA_pos_x       ECG_SYS_pos_x+53
#define ECG_DIA_pos_y       ECG_SYS_pos_y

#define ECG_PUL_pos_x       ECG_Temp_pos_x+75
#define ECG_PUL_pos_y       ECG_Temp_pos_y

#define ECG_Appear_Pixels   19
#define ECG_Demo_Count      10

const XCHAR STR_PR[][5]={"0.18\0","0.19\0","0.17\0"};
const XCHAR STR_QRS[][5]={"0.09\0","0.10\0","0.11\0"};
const XCHAR STR_QT[][5]={"0.40\0","0.38\0","0.37\0"};
const XCHAR STR_RR[][5]={"0.65\0","0.63\0","0.68\0"};

const XCHAR STR_Peak[][5]={"99.1\0","99.2\0","98.6\0"};
const XCHAR STR_Yst[][5]={"98.3\0","98.1\0","98.7\0"};

const XCHAR STR_Temp[][5]={"98.7\0","99.2\0","98.1\0"};
const XCHAR STR_SYS[][5]={"118\0","119\0","117\0"};
const XCHAR STR_DIA[][4]={"78\0","79\0","78\0"};
const XCHAR STR_PUL[][4]={"70\0","71\0","72\0"};
GOL_SCHEME   *pTextScheme4,*pTextScheme5;

STATICTEXT   *txt_PR;
STATICTEXT   *txt_QRS;
STATICTEXT   *txt_QT;
STATICTEXT   *txt_RR;
STATICTEXT   *txt_Temp_F;
STATICTEXT   *txt_Peak;
STATICTEXT   *txt_Yst;
STATICTEXT   *txt_SYS;
STATICTEXT   *txt_DIA;
STATICTEXT   *txt_PUL;
PICTURE      *Pic_heart;


void Create_ECG_Components(void);
void show_ECG_BG(void);
void Show_ECG_Image(void);
void Demo4_Activity(int Select_index);

/**
 * Initial the Demo 4 scheme
 */
void EPD_Demo4_init(void)
{
    pTextScheme4 = GOLCreateScheme(); 		// create alternative style scheme
    pTextScheme4->TextColor0 =BLACK ;
    pTextScheme4->CommonBkColor=WHITE;
    pTextScheme4->pFont =(void *) &Verdana_Bold_14;
    
    pTextScheme5 = GOLCreateScheme(); 		// create alternative style scheme
    pTextScheme5->TextColor0 =BLACK ;
    pTextScheme5->CommonBkColor=WHITE;
    pTextScheme5->pFont =(void *) &Verdana_Bold_10;
}

/**
 * The Demo 4 show function
 */
void Show_EPD_Demo4(void)
{
  int i;
  GFX_GOL_ObjectListFree();
  GFX_ColorSet(WHITE);
  GFX_ScreenClear();
  show_ECG_BG();
  Show_ECG_Image();
  Create_ECG_Components();  //Draw components on background
  if(GFX_GOL_ObjectListDraw())DRV_EPD_UpdateGlobal();

  //start changing the values by partial update
  EPD_power_init(USE_EPD_Type);
  for(i=0;i<ECG_Demo_Count;i++)
      Demo4_Activity(i);
 
  EPD_power_end();
}

/**
 * Show background image on EPD
 */
void show_ECG_BG(void)
{
   PictCreate
        (ID_GLA_ECG_BG,                      // ID
         GLA_ECG_Pos_X,
         GLA_ECG_Pos_Y,
         GLA_ECG_BG_144inch_WIDTH+GLA_ECG_Pos_X,
         GLA_ECG_BG_144inch_HEIGHT+GLA_ECG_Pos_Y, // dimension
         PICT_DRAW,                        // will be dislayed, has frame
         1,                                // scale factor is x1
         (void *)&GLA_ECG_BG_144inch,                      // bitmap
         NULL 
         );                                // default GOL scheme
}

/**
 * Creating components on background
 */
void Create_ECG_Components(void)
{
     txt_PR=StCreate
                (ID_ECG_PR,
                 ECG_PR_pos_x, 
                 ECG_PR_pos_y, 
                 ECG_PR_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_PR[0],pTextScheme5->pFont)+2,
                 ECG_PR_pos_y+GFX_TextStringHeightGet(pTextScheme5->pFont),
                 ST_DRAW,
                 (XCHAR *)STR_PR[0],
                 pTextScheme5
                 );   
    txt_QRS=StCreate
                (ID_ECG_QRS,
                 ECG_QRS_pos_x, 
                 ECG_QRS_pos_y, 
                 ECG_QRS_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_QRS[0],pTextScheme5->pFont)+2,
                 ECG_QRS_pos_y+GFX_TextStringHeightGet(pTextScheme5->pFont),
                 ST_DRAW,
                 (XCHAR *)STR_QRS[0],
                 pTextScheme5 
                 );  
    
     txt_QT=StCreate
                (ID_ECG_QT,
                 ECG_QT_pos_x, 
                 ECG_QT_pos_y, 
                 ECG_QT_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_QT[0],pTextScheme5->pFont)+2,
                 ECG_QT_pos_y+GFX_TextStringHeightGet(pTextScheme5->pFont),
                 ST_DRAW,
                 (XCHAR *)STR_QT[0],
                 pTextScheme5 
                 );  
      txt_RR=StCreate
                (ID_ECG_RR,
                 ECG_RR_pos_x, 
                 ECG_RR_pos_y, 
                 ECG_RR_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_RR[0],pTextScheme5->pFont)+2,
                 ECG_RR_pos_y+GFX_TextStringHeightGet(pTextScheme5->pFont),
                 ST_DRAW,
                 (XCHAR *)STR_RR[0],
                 pTextScheme5 
                 );       
                
     txt_Temp_F=StCreate
                (ID_ECG_TEMP,
                 ECG_Temp_pos_x, 
                 ECG_Temp_pos_y, 
                 ECG_Temp_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_Temp[0],pTextScheme4->pFont)+2,
                 ECG_Temp_pos_y+GFX_TextStringHeightGet(pTextScheme4->pFont),
                 ST_DRAW,
                 (XCHAR *)STR_Temp[0],
                 pTextScheme4 
                 );                
    txt_SYS=StCreate
                (ID_ECG_SYS,
                 ECG_SYS_pos_x, 
                 ECG_SYS_pos_y, 
                 ECG_SYS_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_SYS[0],pTextScheme4->pFont)+2,
                 ECG_SYS_pos_y+GFX_TextStringHeightGet(pTextScheme4->pFont)-2,
                 ST_DRAW,
                 (XCHAR *)STR_SYS[0],
                 pTextScheme4 
                 ); 

       txt_DIA=StCreate
                (ID_ECG_DIA,
                 ECG_DIA_pos_x, 
                 ECG_DIA_pos_y, 
                 ECG_DIA_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_DIA[0],pTextScheme4->pFont)+2,
                 ECG_DIA_pos_y+GFX_TextStringHeightGet(pTextScheme4->pFont)-2,
                 ST_DRAW,
                 (XCHAR *)STR_DIA[0],
                 pTextScheme4 
                 );       
     txt_PUL=StCreate
                (ID_ECG_PUL,
                 ECG_PUL_pos_x, 
                 ECG_PUL_pos_y, 
                 ECG_PUL_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_PUL[0],pTextScheme4->pFont)+2,
                 ECG_PUL_pos_y+GFX_TextStringHeightGet(pTextScheme4->pFont)-2,
                 ST_DRAW,
                 (XCHAR *)STR_PUL[0],
                 pTextScheme4 
                 );
  
                 
     
}

/**
 * Show Heart image
 */
void Show_ECG_Image(void)
{
 
  Pic_heart=PictCreate
        (ID_ECG_Heart,                      // ID
         ECG_Heart_Pos_X,
         ECG_Heart_Pos_Y,
         heart0_WIDTH+ECG_Heart_Pos_X,
         heart0_HEIGHT+ECG_Heart_Pos_Y, // dimension
         PICT_DRAW,                        // will be dislayed, has frame
         1,                                // scale factor is x1
         (void *)&heart0,                      // bitmap
         NULL 
         );   
}

/**
 * Update the heart image
 * @param pObj the target image to be updated
 * @param image the new image
 */
void Update_Heart_Image(PICTURE *pObj,void *image)
{
    GFX_GOL_PictureControlImageSet(pObj,image);
    GFX_GOL_PictureControlDraw(pObj);
}


/**
 * Update text
 * @param pObj the target text to be updated
 * @param str the new string
 */
void Update_Text(void *pObj,XCHAR * str)
{
    StSetText(pObj,str);
    StDraw(pObj);
}

/**
 * The order of appearance of demo4: ECG medical
 * @param Select_index demo step
 */
void Demo4_Activity(int Select_index)
{
    
    switch(Select_index)
    {
        case 0:

            break;
        case 1:

            break;
        case 2:

            break;
        case 3:
            Update_Heart_Image(Pic_heart,(void *)&heart1);
            break;
        case 4:
            Update_Heart_Image(Pic_heart,(void *)&heart0);
            Update_Text(txt_PR,(XCHAR *)STR_PR[1]);
            break;
        case 5:
            Update_Text(txt_DIA,(XCHAR *)STR_DIA[1]);
            Update_Text(txt_SYS,(XCHAR *)STR_SYS[1]);
            break;
        case 6:
            Update_Text(txt_QRS,(XCHAR *)STR_QRS[1]);
            break;
        case 7:
            Update_Text(txt_QT,(XCHAR *)STR_QT[1]);
            Update_Text(txt_PUL,(XCHAR *)STR_PUL[1]);

            break;
        case 8:
            Update_Text(txt_Temp_F,(XCHAR *)STR_Temp[1]);
            Update_Text(txt_RR,(XCHAR *)STR_RR[1]);
            break;
        case 9:
            Update_Heart_Image(Pic_heart,(void *)&heart1);
            break;
        case 10:
            Update_Heart_Image(Pic_heart,(void *)&heart0);
            Update_Text(txt_PR,(XCHAR *)STR_PR[2]);
            break;
        case 11:
            Update_Text(txt_Temp_F,(XCHAR *)STR_Temp[2]);
            Update_Text(txt_Peak,(XCHAR *)STR_Peak[1]);
            Update_Text(txt_SYS,(XCHAR *)STR_SYS[2]);
            break;
        case 12:
            Update_Text(txt_DIA,(XCHAR *)STR_DIA[2]);
            Update_Text(txt_QRS,(XCHAR *)STR_QRS[2]);
            break;
        case 13:
           Update_Text(txt_QT,(XCHAR *)STR_QT[2]);
            break;
        case 14:
            Update_Text(txt_RR,(XCHAR *)STR_RR[2]);
            Update_Text(txt_PUL,(XCHAR *)STR_PUL[2]);
            break;
        case 15:
            Update_Heart_Image(Pic_heart,(void *)&heart1);
            break;
        case 16:
            Update_Text(txt_Temp_F,(XCHAR *)STR_Temp[2]);
            Update_Text(txt_Yst,(XCHAR *)STR_Yst[1]);
            Update_Heart_Image(Pic_heart,(void *)&heart0);
            break;
        case 17:

            break;
        case 18:
            Update_Heart_Image(Pic_heart,(void *)&heart1);
            break;
        case 19:
            Update_Text(txt_Temp_F,(XCHAR *)STR_Temp[0]);
            Update_Text(txt_Yst,(XCHAR *)STR_Yst[0]);
            Update_Heart_Image(Pic_heart,(void *)&heart0);
            break;
      }

      if(GFX_GOL_ObjectListDraw())
      {
           DRV_EPD_UpdatePartial();
      }
  
}
#endif

