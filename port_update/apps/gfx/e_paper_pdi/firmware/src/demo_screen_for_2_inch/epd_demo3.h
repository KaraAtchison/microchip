/**
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

#ifndef EPD_DEMO3_H
#define	EPD_DEMO3_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ID_AC_BG                    210
#define ID_AC_Slide                 211
#define ID_AC_Set_Temp              212
#define ID_AC_Room_Temp             213
#define ID_AC_Down                  214
#define ID_AC_Up                    215
#define ID_AC_RPM                   216
#define ID_AC_Energy                217
#define ID_AC_Last                  218
#define ID_AC_Avg                   219
#define ID_AC_Est                   220
#define ID_AC_Fan                   221

#define DEMO3_SLIDER_MAX_VALUE      10
#define DEMO3_SLIDER_MIN_VALUE      0

void APP_EPD_InitDemo3(void);
void APP_EPD_CreateDemo3(void);
bool APP_EPD_MessageCallbackDemo3(  GFX_GOL_TRANSLATED_ACTION objectMessage,
                                    GFX_GOL_OBJ_HEADER *pObject,
                                    GFX_GOL_MESSAGE *pMessage);
bool APP_EPD_DrawCallbackDemo3(void);

#ifdef	__cplusplus
}
#endif

#endif   /* EPD_DEMO3_H */
