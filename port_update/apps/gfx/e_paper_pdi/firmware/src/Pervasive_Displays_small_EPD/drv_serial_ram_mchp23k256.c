/**
*
* \brief The driver of serial RAM 23K256
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

//#define USE_AND_OR /* To enable AND_OR mask setting */

#include "drv_serial_ram_mchp23k256.h"

static DRV_SPI_INIT_DATA spiInitData;

void DRV_RAM_23K256_Initialize(DRV_SPI_INIT_DATA *pInitData)
{
    DRV_SPI_Initialize(pInitData);
    memcpy(&spiInitData, pInitData, sizeof(DRV_SPI_INIT_DATA));

    DRV_RAM_23K256_Disable();
}

static inline __attribute__((__always_inline__)) void DRV_RAM_23K256_StatusRegisterWrite(
                                uint8_t RegValue)
{
    DRV_RAM_23K256_Enable();

    DRV_SPI_Put(spiInitData.channel, SRAMWRSR);
    DRV_SPI_Put(spiInitData.channel, RegValue);

    DRV_RAM_23K256_Disable();
}

static inline __attribute__((__always_inline__)) uint8_t DRV_RAM_23K256_StatusRegisterRead(void)
{
    uint8_t ReadData = 0;

    DRV_RAM_23K256_Enable();

    DRV_SPI_Put(spiInitData.channel, SRAMRDSR);
    ReadData = DRV_SPI_Get(spiInitData.channel);

    DRV_RAM_23K256_Disable();

    return ReadData;
}

static inline __attribute__((__always_inline__)) void DRV_RAM_23K256_CommandSet(
                                uint16_t address,
                                uint8_t  RWCmd)
{
    DRV_SPI_Put(spiInitData.channel, RWCmd);

    // Send High byte of address to SRAM
    DRV_SPI_Put(spiInitData.channel, (uint8_t)(address >> 8));

    // Send Low byte of address to SRAM
    DRV_SPI_Put(spiInitData.channel, (uint8_t)(address));
}

uint8_t DRV_RAM_23K256_ByteWrite(
                                uint16_t address,
                                uint8_t  WriteData)
{
    while(!DRV_SPI_Lock(spiInitData.channel));
    DRV_SPI_Initialize((DRV_SPI_INIT_DATA *)&spiInitData);

    DRV_RAM_23K256_StatusRegisterWrite(SRAMByteMode);
    DRV_RAM_23K256_Enable();

    // Send Write command to SRAM along with address
    DRV_RAM_23K256_CommandSet(address, SRAMWrite);

    // Send Data to be written to SRAM
    DRV_SPI_Put(spiInitData.channel, WriteData);

    DRV_RAM_23K256_Disable();

    DRV_SPI_Unlock(spiInitData.channel);

    return (0);
}

uint8_t DRV_RAM_23K256_ByteRead(
                                uint16_t address)
{
    unsigned char ReadData;

    while(!DRV_SPI_Lock(spiInitData.channel));
    DRV_SPI_Initialize((DRV_SPI_INIT_DATA *)&spiInitData);

    DRV_RAM_23K256_StatusRegisterWrite(SRAMByteMode);
    DRV_RAM_23K256_Enable();

    // Send Read command to SRAM along with address
    DRV_RAM_23K256_CommandSet(address, SRAMRead);

    // Send dummy data so SRAM can put desired Data read from SRAM
    ReadData = DRV_SPI_Get(spiInitData.channel);

    DRV_RAM_23K256_Disable();

    DRV_SPI_Unlock(spiInitData.channel);

    return(ReadData);
}

uint8_t DRV_RAM_23K256_PageWrite(
                                uint16_t address,
                                uint8_t  *WriteData)
{

    uint8_t WriteCnt;

    while(!DRV_SPI_Lock(spiInitData.channel));
    DRV_SPI_Initialize((DRV_SPI_INIT_DATA *)&spiInitData);

    DRV_RAM_23K256_StatusRegisterWrite(SRAMPageMode);

    // Send Write command to SRAM along with address
    DRV_RAM_23K256_Enable();
    DRV_RAM_23K256_CommandSet(address, SRAMWrite);
#if 0
    for(WriteCnt = 0; WriteCnt < SRAMPageSize; WriteCnt++)
    {
        DRV_SPI_Put(spiInitData.channel, *WriteData++);
    }
#else
    DRV_SPI_PutBuffer(spiInitData.channel, WriteData, SRAMPageSize);
#endif
    DRV_RAM_23K256_Disable();
    
    DRV_SPI_Unlock(spiInitData.channel);
    return(WriteCnt);
}

uint8_t DRV_RAM_23K256_PageRead(
                                uint16_t address,
                                uint8_t  *ReadData)
{

    uint8_t ReadCnt;

    while(!DRV_SPI_Lock(spiInitData.channel));
    DRV_SPI_Initialize((DRV_SPI_INIT_DATA *)&spiInitData);

    DRV_RAM_23K256_StatusRegisterWrite(SRAMPageMode);

    // Send Read command to SRAM along with address
    DRV_RAM_23K256_Enable();
    DRV_RAM_23K256_CommandSet(address, SRAMRead);
#if 0
    for(ReadCnt = 0; ReadCnt < SRAMPageSize; ReadCnt++)
    {
        *ReadData++ = DRV_SPI_Get(spiInitData.channel);
    }
#else
    DRV_SPI_GetBuffer(spiInitData.channel, ReadData, SRAMPageSize);
#endif
    DRV_RAM_23K256_Disable();

    DRV_SPI_Unlock(spiInitData.channel);
    return(ReadCnt);
}

uint8_t DRV_RAM_23K256_SequentialWrite(
                                uint16_t address,
                                uint8_t  *WriteData,
                                uint16_t WriteCnt)
{
    while(!DRV_SPI_Lock(spiInitData.channel));
    DRV_SPI_Initialize((DRV_SPI_INIT_DATA *)&spiInitData);

    DRV_RAM_23K256_StatusRegisterWrite(SRAMSeqMode);

    // Send Write command to SRAM along with address
    DRV_RAM_23K256_Enable();
    DRV_RAM_23K256_CommandSet(address, SRAMWrite);

#if 0
    for( ; WriteCnt > 0; WriteCnt--)
    {
        DRV_SPI_Put(spiInitData.channel, *WriteData++);

    }
#else
    DRV_SPI_PutBuffer(spiInitData.channel, WriteData, WriteCnt);
#endif
    DRV_RAM_23K256_Disable();

    DRV_SPI_Unlock(spiInitData.channel);
    return(0);
}

uint8_t DRV_RAM_23K256_SequentialRead(
                                uint16_t address,
                                uint8_t  *ReadData,
                                uint16_t ReadCnt)
{

    while(!DRV_SPI_Lock(spiInitData.channel));
    DRV_SPI_Initialize((DRV_SPI_INIT_DATA *)&spiInitData);

    DRV_RAM_23K256_StatusRegisterWrite(SRAMSeqMode);

    // Send Read command to SRAM along with address
    DRV_RAM_23K256_Enable();
    DRV_RAM_23K256_CommandSet(address, SRAMRead);
#if 0
    for( ; ReadCnt > 0; ReadCnt--)
    {
        *ReadData++ = DRV_SPI_Get(spiInitData.channel);
    }
#else
    DRV_SPI_GetBuffer(spiInitData.channel, ReadData, ReadCnt);
#endif
    DRV_RAM_23K256_Disable();
    
    DRV_SPI_Unlock(spiInitData.channel);
    return(0);
}


