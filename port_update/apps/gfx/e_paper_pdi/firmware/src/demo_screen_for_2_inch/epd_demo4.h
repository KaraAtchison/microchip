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

#ifndef EPD_DEMO4_H
#define	EPD_DEMO4_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ID_GLA_ECG_BG               221
#define ID_ECG_PR                   222
#define ID_ECG_QT                   223
#define ID_ECG_QRS                  224
#define ID_ECG_RR                   225
#define ID_ECG_Image                226
#define ID_ECG_TEMP                 227
#define ID_ECG_Peak                 228
#define ID_ECG_Yst                  229
#define ID_ECG_SYS                  230
#define ID_ECG_DIA                  231
#define ID_ECG_PUL                  232
#define ID_ECG_Heart                233
#define ID_PDI_Logo                 234

void APP_EPD_CreateDemo4(void);
void APP_EPD_InitDemo4(void);

#ifdef	__cplusplus
}
#endif

#endif    /* EPD_DEMO4_H */
