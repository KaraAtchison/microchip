/**
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

#ifndef EPD_DEMO_HOME_H
#define	EPD_DEMO_HOME_H

#include <stdlib.h>

#ifdef	__cplusplus
extern "C" {
#endif
typedef struct
{
    int16_t x;
    int16_t y;
    int16_t right;
    int16_t bottom;
}Object_pos_t;

/** States of the demo application's state machine. */
typedef enum
{
    EPD_Init,
    EPD_DEMO_CREATE_HOME,
    EPD_DEMO_SHOW_HOME,
    EPD_DEMO_CREATE_GLOBAL_IMAGE,
    EPD_DEMO_SHOW_GLOBAL_IMAGE,
    EPD_CREATE_DEMO1,
    EPD_SHOW_DEMO1,
    EPD_CREATE_DEMO2,
    EPD_SHOW_DEMO2,
    EPD_CREATE_DEMO3,
    EPD_SHOW_DEMO3,
    EPD_CREATE_DEMO4,
    EPD_SHOW_DEMO4,
//    EPD_DEMO5,
    EPD_Power_End,
    CHANGE_DEMO_MODE,
    EPD_DEMO_NONE
} DEMO_STATES;

#define ID_Logo                     200
#define ID_Microchip_Logo           201
#define ID_HOME_TITLE1              202
#define ID_HOME_TITLE2              203

#define ID_BUTTON1                  204
#define ID_BUTTON2                  205
#define ID_BUTTON3                  206
#define ID_BUTTON4                  207
#define ID_BUTTON5                  208
#define ID_PDI_Logo                 234


//void Show_Home(uint8_t index_select,uint8_t IsShowButton);
//void EPD_Demo_Home_Init(void);

void APP_EPD_DemoHomeInit(void);
void APP_EPD_CreateHomeScreen(void);
void APP_EPD_CreateGlobalImageScreen(void);


#ifdef	__cplusplus
}
#endif

#endif   /* EPD_DEMO_HOME_H */

