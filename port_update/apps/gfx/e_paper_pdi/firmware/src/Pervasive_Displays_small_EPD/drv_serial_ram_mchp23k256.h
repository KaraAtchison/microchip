/**
*
* \brief The definition of serial RAM 23K256
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

#ifndef __DRV_SPI_RAM_MCHP23K256_H
#define __DRV_SPI_RAM_MCHP23K256_H

/************************************************************************
 * Section:  Includes
 ************************************************************************/
#include <stdint.h>
#include <string.h>
#include "system.h"
#include "driver/spi/drv_spi.h"

#define SRAMRead        0x03     //Read Command for SRAM
#define SRAMWrite       0x02     //Write Command for SRAM
#define SRAMRDSR        0x05     //Read the status register
#define SRAMWRSR        0x01     //Write the status register
#define SRAMByteMode    0x01
#define SRAMPageMode    0x81
#define	SRAMSeqMode     0x41
#define	SRAMPageSize    32

#define DRV_RAM_23K256_Enable()     (MCHP_23K256_CS_LAT = 0)
#define DRV_RAM_23K256_Disable()    (MCHP_23K256_CS_LAT = 1)

void DRV_RAM_23K256_Initialize(DRV_SPI_INIT_DATA *pInitData);
uint8_t DRV_RAM_23K256_ByteWrite(
                                uint16_t address,
                                uint8_t  WriteData);
uint8_t DRV_RAM_23K256_ByteRead(
                                uint16_t address);
uint8_t DRV_RAM_23K256_PageWrite(
                                uint16_t address,
                                uint8_t  *WriteData);
uint8_t DRV_RAM_23K256_PageRead(
                                uint16_t address,
                                uint8_t  *ReadData);
uint8_t DRV_RAM_23K256_SequentialWrite(
                                uint16_t address,
                                uint8_t  *WriteData,
                                uint16_t WriteCnt);
uint8_t DRV_RAM_23K256_SequentialRead(
                                uint16_t address,
                                uint8_t  *ReadData,
                                uint16_t ReadCnt);

#endif //__DRV_SPI_RAM_MCHP23K256_H
