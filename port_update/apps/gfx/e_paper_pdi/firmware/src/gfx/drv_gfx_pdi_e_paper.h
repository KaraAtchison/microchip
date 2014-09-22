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

#ifndef EPD_H
#define	EPD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "system_config.h"
#include "drv_serial_ram_mchp23k256.h"
#include "epd_types.h"

/** 
 * Using 2.7" as maximum supported size. 2.7" resolution is 264*176.
 * 264/8=33Bytes per line(total 176 lines), but use 64Bytes as a base for future
 * supporting larger size image.
 * 64*176=11264 Bytes --> 12K Bytes per default image size  */
//#define _epd_image_size     (long)4*1024*3  //12k
//#define _epd_page_size()    (_epd_image_size/32)    //memory access per page=32 bytes
//#define getAddress(page)    (long)(_epd_image_size*page)

#define _epd_image_size     (uint32_t)4*1024*3  //12k
#define _epd_page_size()    (_epd_image_size >> 5)    //memory access per page=32 bytes
#define getAddress(page)    (uint32_t)(_epd_image_size*page)

// Serial RAM macros
#define DRV_EPD_SRAMWriteByte(address, data)                    DRV_RAM_23K256_ByteWrite(address, data)
#define DRV_EPD_SRAMReadByte(address)                           DRV_RAM_23K256_ByteRead(address);
#define DRV_EPD_SRAMWritePage(address, data)                    DRV_RAM_23K256_PageWrite(address, data)
#define DRV_EPD_SRAMReadPage(address, data)                     DRV_RAM_23K256_PageRead(address, data)
#define DRV_EPD_SRAMReadSequential(address, buffer, length)     DRV_RAM_23K256_SequentialRead(address, buffer, length)

void SetEPDImageindex(uint8_t image_size);
void DRV_EPD_UpdateGlobal(void);
void DRV_EPD_PowerUp(void);
void DRV_EPD_PowerDown(void);
void DRV_EPD_UpdatePartial(void);
void DRV_EPD_SRAMHandleRead(EInt memory_address,uint8_t *target_buffer,
                              uint8_t byte_length);
#ifdef	__cplusplus
}
#endif

#endif	/* EPD_H */

