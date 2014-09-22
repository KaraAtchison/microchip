/**
* \file
*
* \brief The content layout and order of appearance of Demo Home menu for 1.44" EPD
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

#include "resources_epd_demo.h"
#include "Pervasive_Displays_small_EPD.h"
#if (USE_EPD_Type==EPD_144)
#define Logo_Pos_X  0
#define Logo_Pos_Y  0
#define Microchip_Logo_Pos_X  10
#define Microchip_Logo_Pos_Y  110
#define Home_Title1_Pos_X  3
#define Home_Title1_Pos_Y  1
#define Home_Title2_Pos_X  1
#define Home_Title2_Pos_Y  17
#define Home_Title1_Str    (XCHAR *)"EPD demonstration with"
#define Home_Title2_Str    (XCHAR *)"Microchip Graphic Library"

#define Button_pos_x       19
#define Button_pos_y       29

#define Button1_pos_x      Button_pos_x
#define Button1_pos_y      Button_pos_y
#define Button1_Str        (XCHAR *)"Square,Circle"

#define Button2_pos_x      Button1_pos_x
#define Button2_pos_y      Button1_pos_y+17
#define Button2_Str        (XCHAR *)"Bar Chart" 

#define Button3_pos_x      Button2_pos_x
#define Button3_pos_y      Button2_pos_y+17
#define Button3_Str        (XCHAR *)"HVAC Panel"

#define Button4_pos_x      Button3_pos_x
#define Button4_pos_y      Button3_pos_y+17
#define Button4_Str        (XCHAR *)"Medical ECG " 

#define Button5_pos_x      Button_pos_x
#define Button5_pos_y      Button4_pos_y+5
#define Button5_Str        (XCHAR *)" Medical ECG      "

GOL_SCHEME   *pScheme;
GOL_SCHEME   *pScheme2;
void Show_Button(void);
void Show_Menu_BG(void);
void Update_Home_Button(uint8_t index_select);
void EPD_Demo_Home_Init(void)
{
    pScheme = GOLCreateScheme(); 		// create alternative style scheme
    pScheme->TextColor0 =BLACK ;
    pScheme->CommonBkColor=WHITE;
    pScheme->pFont =(void *) &Verdana_Bold_14;

    pScheme2 = GOLCreateScheme(); 		// create alternative style scheme
    pScheme2->TextColor0 =BLACK;
    pScheme2->Color0=WHITE;
    pScheme2->TextColor1=WHITE;
    pScheme2->Color1=BLACK;
    pScheme2->CommonBkColor=WHITE;
    pScheme2->EmbossLtColor=BLACK;
    pScheme2->EmbossDkColor=BLACK;
    pScheme2->TextColorDisabled=WHITE;
    pScheme2->ColorDisabled=WHITE;
    pScheme2->pFont =(void *)&Verdana_12;    
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
    GFX_ScreenClear();  // clear screen of EPD
    Show_Menu_BG(); 
    Show_Button();  // layout buttons
	
    if(GFX_GOL_ObjectListDraw())
        DRV_EPD_UpdateGlobal();  //show Demo_home screen
    if(IsShowButton)
        Update_Home_Button(index_select);  //show pressed button if IsShowButton
}

/**
 * Show front menu background image on EPD
 */
void Show_Menu_BG(void)
{
    PictCreate
        (ID_Logo,
         Logo_Pos_X,
         Logo_Pos_Y,
         GLA_front_menu_BG_144inch_WIDTH+Logo_Pos_X,
         GLA_front_menu_BG_144inch_HEIGHT+Logo_Pos_Y, // dimension
         PICT_DRAW,                         // will be dislayed, has frame
         1,                                 // scale factor is x1
         (void *)&GLA_front_menu_BG_144inch,  // bitmap
         NULL 
         ); // default GOL scheme  
         
}

/**
 * Show pressed button effect
 * @param index_select Button index to press
 */
void Update_Home_Button(uint8_t index_select)
{
   BUTTON * Button=NULL;
    switch(index_select)
     {   
        case 0:
            break;
        case 1:
            Button=(BUTTON *)GOLFindObject(ID_BUTTON1);
            break;
        case 2:
            Button=(BUTTON *)GOLFindObject(ID_BUTTON2);
            break;
        case 3:
            Button=(BUTTON *)GOLFindObject(ID_BUTTON3);
            break;
        case 4:
            Button=(BUTTON *)GOLFindObject(ID_BUTTON4);
            break;             
     }
    if(Button!=NULL) GFX_GOL_ObjectStateSet(Button,BTN_PRESSED);
    BtnDraw(Button);
    
    EPD_power_init(USE_EPD_Type);

    if(GFX_GOL_ObjectListDraw())DRV_EPD_UpdatePartial();
   
    EPD_power_end();   
}

/**
 * Layout buttons on EPD
 */
void Show_Button(void)
{
   // BUTTON *B_Button1,*B_Button2,*B_Button3,*B_Button4,*B_Button5;
      SHORT Button_Width,Button_High;   
      Button_Width=GFX_TextStringWidthGet(Button1_Str,pScheme2->pFont)+8;
      Button_High=GFX_TextStringHeightGet(pScheme2->pFont)-1;
      BtnCreate
                (ID_BUTTON1,                // ID
                 Button1_pos_x,
                 Button1_pos_y,
                 Button1_pos_x+Button_Width,
                 Button1_pos_y+Button_High,
                 3,                         // dimension and radius
                 BTN_DRAW | BTN_TEXTLEFT,   // will be displayed after creation
                 NULL,                      // bitmap
                 Button1_Str,               // text
                 pScheme2 );  
     
      BtnCreate
                (ID_BUTTON2,                // ID
                 Button2_pos_x,
                 Button2_pos_y,
                 Button2_pos_x+Button_Width,
                 Button2_pos_y+Button_High,
                 3,                         // dimension and radius
                 BTN_DRAW | BTN_TEXTLEFT,   // will be displayed after creation
                 NULL,                      // bitmap
                 Button2_Str,               // text
                 pScheme2 );  
      
      BtnCreate
                (ID_BUTTON3,                // ID
                 Button3_pos_x,
                 Button3_pos_y,
                 Button3_pos_x+Button_Width,
                 Button3_pos_y+Button_High,
                 3,                         // dimension and radius
                 BTN_DRAW | BTN_TEXTLEFT,   // will be displayed after creation
                 NULL,                      // bitmap
                 Button3_Str,               // text
                 pScheme2 ); 
       BtnCreate
                (ID_BUTTON4,                // ID
                 Button4_pos_x,
                 Button4_pos_y,
                 Button4_pos_x+Button_Width,
                 Button4_pos_y+Button_High,
                 3,                         // dimension and radius
                 BTN_DRAW | BTN_TEXTLEFT,   // will be displayed after creation
                 NULL,                      // bitmap
                 Button4_Str,               // text
                 pScheme2 ); 
                
}
#endif
