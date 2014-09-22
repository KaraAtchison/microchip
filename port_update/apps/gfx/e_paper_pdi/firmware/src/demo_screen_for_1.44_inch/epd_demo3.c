/**
*
* \brief The content layout and order of appearance of Demo 3 HVAC for 1.44" EPD
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
#include <stdbool.h>

#include "gfx/gfx.h"
#include "system_config.h"

#include <p24Fxxxx.h>
#include <libpic30.h>
#include "Pervasive_Displays_small_EPD.h"
#include "resources_epd_demo.h"
#if (USE_EPD_Type==EPD_144)

#define AC_BG_Pos_x         0
#define AC_BG_Pos_y         0

#define AC_Fan_Pos_x        146
#define AC_Fan_Pos_y        2

#define Slide_Pos_x         42
#define Slide_Pos_y         43
#define Slide_Width         45
#define Slide_High          16

#define But_Down_pos_x      1
#define But_Down_pos_y      Slide_Pos_y
#define But_Down_Str        (XCHAR *)"DOWN"

#define But_Up_pos_x        89
#define But_Up_pos_y        But_Down_pos_y
#define But_Up_Str          (XCHAR *)"UP"

#define Set_Temp_pos_x      2
#define Set_Temp_pos_y      8

#define Set_Room_Temp_x     72
#define Set_Room_Temp_y     Set_Temp_pos_y

#define RPM_pos_x           63
#define RPM_pos_y           78

#define Energy_pos_x        70
#define Energy_pos_y        63


const XCHAR STR_Set_Temp[][3]={
                                "27\0",  //27
                                "26\0",  //26
                                "25\0",  //25
                                "26\0",  //26
                              };
const XCHAR STR_Room_Temp[][3]={
                                "28\0",//28
                                "27\0",//27
                                "26\0",//26
                                "27\0",//27
                                };
const XCHAR STR_RPM[][5]={"1240\0","1263\0","1285\0","1292\0","1318\0","1346\0","1359\0","1340\0","1311\0","1295\0"};
const XCHAR STR_Energy[][4]={"254\0","255\0","256\0","258\0","259\0","261\0","263\0","262\0","259\0","259\0"};

// style schemes
GFX_GOL_OBJ_SCHEME      SliderScheme;
GFX_GOL_OBJ_SCHEME      TextScheme1, TextScheme2;
GFX_GOL_OBJ_SCHEME      ButtonScheme;
//GOL_SCHEME   *pSliderScheme;
//GOL_SCHEME   *pTextScheme1,*pTextScheme2;
//GOL_SCHEME   *pButtonScheme;


uint16_t     SliderValue;

SLIDER       *pSlider;
STATICTEXT   *txt_Set_Temp;
STATICTEXT   *txt_Room_Temp;
STATICTEXT   *txt_RPM;
STATICTEXT   *txt_Energy;
BUTTON       *But_Down,*But_Up;
void show_AC_BG(void);
void Create_Components(void);
void Demo_Activity(int Select_index);

/**
 * Initial the Demo 3 scheme
 */
void EPD_Demo3_init(void)
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

    GFX_GOL_SchemeFontSet(&SliderScheme, (GFX_RESOURCE_HDR*)&Verdana_12);
    GFX_GOL_SchemeBackgroundTypeSet(&SliderScheme, GFX_BACKGROUND_NONE);

    
    //pSliderScheme = GOLCreateScheme(); 		// create alternative style scheme
    //pSliderScheme->Color0 =WHITE;
    //pSliderScheme->EmbossDkColor=BLACK;
    //pSliderScheme->EmbossLtColor=BLACK;
    //pSliderScheme->TextColor0=WHITE ;
    //pSliderScheme->CommonBkColor=WHITE ;
    //pSliderScheme->ColorDisabled=WHITE ;

    // set text scheme 1 style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&TextScheme1, BLACK, WHITE, BLACK);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&TextScheme1, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&TextScheme1, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&TextScheme1, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&TextScheme1, (GFX_RESOURCE_HDR*)&Verdana_Bold_14);
    GFX_GOL_SchemeBackgroundTypeSet(&TextScheme1, GFX_BACKGROUND_NONE);


    
    //pTextScheme1 = GOLCreateScheme(); 		// create alternative style scheme
    //pTextScheme1->TextColor0 =BLACK ;
    //pTextScheme1->CommonBkColor=WHITE;
    //pTextScheme1->pFont =(void *) &Verdana_Bold_14;

    // set text scheme 2 style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&TextScheme2, BLACK, WHITE, BLACK);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&TextScheme2, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&TextScheme2, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&TextScheme2, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&TextScheme2, (GFX_RESOURCE_HDR*)&Verdana_Bold_28);
    GFX_GOL_SchemeBackgroundTypeSet(&TextScheme2, GFX_BACKGROUND_NONE);


    //pTextScheme2 = GOLCreateScheme(); 		// create alternative style scheme
    //pTextScheme2->TextColor0 =BLACK ;
    //pTextScheme2->CommonBkColor=WHITE;
    //pTextScheme2->pFont =(void *) &Verdana_Bold_28;

    // set button scheme style scheme
    // set text colors (text color 0, text color 1 and disabled text color)
    GFX_GOL_SchemeTextColorSet(&ButtonScheme, BLACK, WHITE, WHITE);

    // set color0, color1 and disable color
    GFX_GOL_SchemeColorSet(&ButtonScheme, WHITE, BLACK, WHITE);

    // set the common background color
    GFX_GOL_SchemeBackgroundColorSet(&ButtonScheme, WHITE);

    // set the emboss colors and size
    GFX_GOL_SchemeEmbossSet(&ButtonScheme, BLACK, BLACK, 1);

    GFX_GOL_SchemeFontSet(&ButtonScheme, (GFX_RESOURCE_HDR*)&Verdana_Bold_10);
    GFX_GOL_SchemeBackgroundTypeSet(&ButtonScheme, GFX_BACKGROUND_NONE);


//    pButtonScheme = GOLCreateScheme(); 		// create alternative style scheme
//    pButtonScheme->CommonBkColor=WHITE;
//    pButtonScheme->TextColor0 =BLACK;
//    pButtonScheme->Color0=WHITE;
//    pButtonScheme->TextColor1=WHITE;
//    pButtonScheme->Color1=BLACK;
//    pButtonScheme->EmbossLtColor=BLACK;
//    pButtonScheme->EmbossDkColor=BLACK;
//    pButtonScheme->TextColorDisabled=WHITE;
//    pButtonScheme->ColorDisabled=WHITE;
//    pButtonScheme->pFont =(void *)&Verdana_Bold_10;
}

/**
 * The Demo 3 show function
 */
void Show_EPD_Demo3(void)
{
    int i;
    GFX_GOL_ObjectListFree();
    GFX_ColorSet(WHITE);
    GFX_ScreenClear();
    SliderValue=50;
    show_AC_BG();    
    Create_Components();  //Draw components on background
    if(GFX_GOL_ObjectListDraw())DRV_EPD_UpdateGlobal();

    //start changing the values by partial update
    EPD_power_init(USE_EPD_Type);
    for(i=1;i<13;i++)Demo_Activity(i);
    EPD_power_end();

}

/**
 * Show background image on EPD
 */
void show_AC_BG(void)
{
    PictCreate
        (ID_AC_BG,                      // ID
         AC_BG_Pos_x,
         AC_BG_Pos_y,
         AC_BG_Pos_x+GLA_HVAC_BG_144inch_WIDTH,
         AC_BG_Pos_y+GLA_HVAC_BG_144inch_HEIGHT, // dimension
         PICT_DRAW,                        // will be dislayed, has frame
         1,                                // scale factor is x1
         (void *)&GLA_HVAC_BG_144inch,         // bitmap
         NULL 
         );                                // default GOL scheme
    
}

/**
 * Creating components on background
 */
void Create_Components(void)
{
     txt_Set_Temp=StCreate
                (ID_AC_Set_Temp,
                 Set_Temp_pos_x, 
                 Set_Temp_pos_y, 
                 Set_Temp_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_Set_Temp[0],pTextScheme2->pFont)+2,
                 Set_Temp_pos_y+GFX_TextStringHeightGet(pTextScheme2->pFont),
                 ST_DRAW,
                 (XCHAR *)STR_Set_Temp[0],
                 pTextScheme2 
                 );   
    txt_Room_Temp=StCreate
                (ID_AC_Room_Temp,
                 Set_Room_Temp_x, 
                 Set_Room_Temp_y, 
                 Set_Room_Temp_x+GFX_TextStringWidthGet((XCHAR *)STR_Room_Temp[0],pTextScheme2->pFont)+2,
                 Set_Room_Temp_y+GFX_TextStringHeightGet(pTextScheme2->pFont),
                 ST_DRAW,
                 (XCHAR *)STR_Room_Temp[0],
                 pTextScheme2 
                 );  
   
    pSlider=SldCreate(ID_AC_Slide,
		Slide_Pos_x,
                Slide_Pos_y,
                Slide_Pos_x+Slide_Width,
                Slide_Pos_y+Slide_High,
		SLD_DRAW,
		100, 1, SliderValue,
		pSliderScheme);
    But_Down=BtnCreate
                (ID_AC_Down,             // ID
                 But_Down_pos_x,
                 But_Down_pos_y,
                 But_Down_pos_x+GFX_TextStringWidthGet(But_Down_Str,pButtonScheme->pFont),
                 But_Down_pos_y+GFX_TextStringHeightGet(pButtonScheme->pFont)+2,
                 3,               // dimension and radius
                 BTN_DRAW,        // will be displayed after creation
                 NULL, // bitmap
                 But_Down_Str,   // text
                 pButtonScheme ); 
    But_Up=BtnCreate
                (ID_AC_Up,             // ID
                 But_Up_pos_x,
                 But_Up_pos_y,
                 But_Up_pos_x+GFX_TextStringWidthGet(But_Down_Str,pButtonScheme->pFont),
                 But_Up_pos_y+GFX_TextStringHeightGet(pButtonScheme->pFont)+2,
                 3,               // dimension and radius
                 BTN_DRAW,        // will be displayed after creation
                 NULL, // bitmap
                 But_Up_Str,   // text
                 pButtonScheme ); 
   
    
     txt_RPM=StCreate
                (ID_AC_RPM,
                 RPM_pos_x, 
                 RPM_pos_y, 
                 RPM_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_RPM[0],pTextScheme1->pFont)+2,
                 RPM_pos_y+GFX_TextStringHeightGet(pTextScheme1->pFont),
                 ST_DRAW,
                 (XCHAR *)STR_RPM[0],
                 pTextScheme1 
                 );   
      
     txt_Energy=StCreate
                (ID_AC_Energy,
                 Energy_pos_x, 
                 Energy_pos_y, 
                 Energy_pos_x+GFX_TextStringWidthGet((XCHAR *)STR_Energy[0],pTextScheme1->pFont)+2,
                 Energy_pos_y+GFX_TextStringHeightGet(pTextScheme1->pFont),
                 ST_DRAW,
                 (XCHAR *)STR_Energy[0],
                 pTextScheme1 
                 );  
   
}

/**
 * Update button status
 * @param pObj the target button to be updated
 * @param isPRESSED Pressed button or not
 */
void UpdateButton(void *pObj,bool isPRESSED)
{
    if(isPRESSED) GFX_GOL_ObjectStateSet(pObj, BTN_PRESSED);
    else  ClrState(pObj, BTN_PRESSED);
    BtnDraw(pObj);
}

/**
 * Update slider status
 * @param pObj the target slider to be updated
 * @param Value slider value
 */
void UpdateSlider(void *pObj,WORD Value)
{
    GFX_GOL_ScrollBarPositionSet(pObj, Value);
    GFX_GOL_ObjectStateSet(pObj, SLD_DRAW_THUMB);
    GFX_GOL_ScrollBarDraw(pObj);
}

/**
 * Update text
 * @param pObj the target text to be updated
 * @param str the new string
 */
void UpdateText(void *pObj,XCHAR * str)
{
    StSetText(pObj,str);
    StDraw(pObj);
}

/**
 * Update image
 * @param pObj the target image to be updated
 * @param image the new image
 */
void UpdateImage(void *pObj,void *image)
{
    GFX_GOL_PictureControlImageSet(pObj,image);
    GFX_GOL_PictureControlDraw(pObj);
}

/**
 * The order of appearance of demo3: HVAC
 * @param Select_index demo step
 */
void Demo_Activity(int Select_index)
{

  switch(Select_index)
  {
    case 0:
           
        break;
    case 1:
        UpdateButton(But_Down, true);
        break;
    case 2:
        UpdateButton(But_Down, false);
        SliderValue-=10;
        UpdateSlider(pSlider, SliderValue);       
        UpdateText(txt_RPM,(XCHAR *)STR_RPM[1]);
        UpdateText(txt_Energy,(XCHAR *)STR_Energy[1]);       
        break;
    case 3:
        UpdateText(txt_Set_Temp,(XCHAR *)STR_Set_Temp[1]);
        UpdateText(txt_RPM,(XCHAR *)STR_RPM[2]);
        UpdateText(txt_Energy,(XCHAR *)STR_Energy[2]);        
        break;
    case 4:
        UpdateText(txt_RPM,(XCHAR *)STR_RPM[3]);
        UpdateText(txt_Energy,(XCHAR *)STR_Energy[3]);        
        break;
    case 5:
        UpdateButton(But_Down, true);
        UpdateText(txt_Room_Temp,(XCHAR *)STR_Room_Temp[1]);        
        break; 
    case 6:
        UpdateButton(But_Down, false);
        SliderValue-=10;
        UpdateSlider(pSlider, SliderValue);       
        UpdateText(txt_RPM,(XCHAR *)STR_RPM[4]);
        UpdateText(txt_Energy,(XCHAR *)STR_Energy[4]);       
        break;  
    case 7:
        UpdateText(txt_Set_Temp,(XCHAR *)STR_Set_Temp[2]); 
        UpdateText(txt_RPM,(XCHAR *)STR_RPM[5]);
        UpdateText(txt_Energy,(XCHAR *)STR_Energy[5]);        
        break; 
    case 8:
        UpdateText(txt_RPM,(XCHAR *)STR_RPM[6]);
        UpdateText(txt_Energy,(XCHAR *)STR_Energy[6]);        
        break; 
    case 9:
        UpdateButton(But_Up, true);  
        UpdateText(txt_Room_Temp,(XCHAR *)STR_Room_Temp[2]);       
        break; 
    case 10:
         UpdateButton(But_Up, false);
        SliderValue+=10;
        UpdateSlider(pSlider, SliderValue);       
        UpdateText(txt_RPM,(XCHAR *)STR_RPM[7]);
        UpdateText(txt_Energy,(XCHAR *)STR_Energy[7]);       
        break; 
    case 11:
        UpdateText(txt_Set_Temp,(XCHAR *)STR_Set_Temp[3]); 
        UpdateText(txt_RPM,(XCHAR *)STR_RPM[8]);
        UpdateText(txt_Energy,(XCHAR *)STR_Energy[8]);        
        break; 
    case 12:
        UpdateText(txt_RPM,(XCHAR *)STR_RPM[9]);
        UpdateText(txt_Energy,(XCHAR *)STR_Energy[9]);       
        break;         

  }
  
  if(GFX_GOL_ObjectListDraw())
  {
     DRV_EPD_UpdatePartial();
  }
}

#endif

