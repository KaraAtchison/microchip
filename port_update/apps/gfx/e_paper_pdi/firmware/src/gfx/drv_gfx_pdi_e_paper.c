/**
*
* \brief The EPD driver for Microchip Graphic Library
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

#include <string.h>
#include "system_config.h"
#include <libpic30.h>
#include "drv_gfx_pdi_e_paper.h"
#include "driver/gfx/drv_gfx_display.h"
#include "gfx/gfx_primitive.h"
#include "Pervasive_Displays_small_EPD.h"

#ifdef GFX_USE_DISPLAY_CONTROLLER_EPD

uint16_t cur_image_index=0;
uint32_t previous_image_address, new_image_address;

static uint8_t bkdata=0xff;

#define	_BV(bit)   (1 << (bit)) /**< left shift 1 bit */

#ifndef BLACK
        #define BLACK	0
#endif
#ifndef WHITE
        #define WHITE	1
#endif

// *****************************************************************************
/*  Function:
    void DRV_GFX_Initialize(void)

    Summary:
        Initialize the graphics display driver.

    Description:
        This function initializes the graphics display driver. This
        function will be called by the application.

*/
// *****************************************************************************
void DRV_GFX_Initialize(void)
{

    uint32_t i;
    uint8_t ImgData[32];

    //Sets 32 bytes of the block of memory pointed by ImgData to 0xFF
    for(i = 0; i < 32; i++)
    {
        ImgData[i]=0xFF;
    }
    
    //Write 0xFF to SRAM
    for(i = 0; i < 1024; i++)
    {
        DRV_EPD_SRAMWritePage((i*32), ImgData);
    }
  
    cur_image_index=0;
    new_image_address=getAddress(cur_image_index);
    previous_image_address=getAddress((cur_image_index+1));
}

// *****************************************************************************
/*  Function:
    GFX_STATUS GFX_PixelPut(
                    uint16_t    x,
                    uint16_t    y)

    Summary:
        Draw the pixel on the given position.

    Description:
        This routine draws the pixel on the given position.
        The color used is the color set by the last call to
        GFX_ColorSet().

        If position is not on the frame buffer, then the behavior
        is undefined. If color is not set, before this function
        is called, the output is undefined.

*/
// *****************************************************************************
GFX_STATUS GFX_PixelPut(uint16_t x, uint16_t y)
{

    uint32_t    address;
    uint8_t     PixelBit, sdata;

    PixelBit  = (7 - (x & 0x7));
    address   = (uint32_t)(y*(DISP_HOR_RESOLUTION >> 3)) + (x >> 3);

    //address page offset
    address  += new_image_address;

    bkdata    = DRV_EPD_SRAMReadByte(address);

    if(GFX_ColorGet() == BLACK)  {
        sdata = (bkdata & (~_BV(PixelBit)));
    }else
    {
        sdata=(bkdata | _BV(PixelBit));
    }

    if(sdata != bkdata)
    {
        DRV_EPD_SRAMWriteByte(address, sdata);
        bkdata = sdata;
    }
}

// *****************************************************************************
/*  Function:
    GFX_COLOR GFX_PixelGet(
                    uint16_t    x,
                    uint16_t    y)

    Summary:
        Gets color of the pixel on the given position.

    Description:
        This routine gets the pixel on the given position.

        If position is not on the frame buffer, then the behavior
        is undefined.

*/
// *****************************************************************************
GFX_COLOR GFX_PixelGet(uint16_t x, uint16_t y)
{
    // NOTE: This is currently not supported
    //       and will always return 1.

    return 1;

}

// *****************************************************************************
/*
    <GROUP driver_rendering_functions>

    Function:
        GFX_STATUS_BITS GFX_RenderStatusGet()

    Summary:
        This function returns the driver's status on rendering.

    Description:
        This function returns the driver's rendering status. Valid values
        returned are GFX_STATUS_BUSY_BIT or GFX_STATUS_READY_BIT
        (see GFX_STATUS_BITS).

*/
// *****************************************************************************
GFX_STATUS_BIT GFX_RenderStatusGet(void)
{
    return GFX_STATUS_READY_BIT;
}


// *****************************************************************************
/*  Function:
    GFX_STATUS GFX_ScreenClear(void)

    Summary:
        Clears the screen to the currently set color (GFX_ColorSet()).

    Description:
        This function clears the screen with the current color and sets
        the line cursor position to (0, 0).

        If color is not set, before this function is called, the output
        is undefined.

        If the function returns GFX_STATUS_FAILURE, clearing is not
        yet finished. Application must call the function again to continue
        the clearing.

*/
// *****************************************************************************
GFX_STATUS GFX_ScreenClear(void)
{
    uint32_t    i;
    uint8_t     tmp = 0xFF;
    uint8_t     ImgData[32];

    // SpiRAM_Init();
    if(GFX_ColorGet() == BLACK)
        tmp = 0x00;

    for(i = 0; i < 32; i++)
    {
        ImgData[i] = tmp;
    }
    for(i = 0; i< _epd_page_size(); i++)
    {
        DRV_EPD_SRAMWritePage((i*32), ImgData);
    }

    GFX_LinePositionSet(0, 0);

}

/**
 * Store the last updated image to Previous image
 */
void DRV_EPD_StoreScreen(void){

    uint32_t i;
    uint8_t ImgData[32];
    // SpiRAM_Init();
    for(i = 0; i < _epd_page_size(); i++)
    {
        DRV_EPD_SRAMReadPage((i*32), ImgData);
        DRV_EPD_SRAMWritePage((i*32)+previous_image_address,ImgData);
    }
}

/**
 * Read image data from SRAM
 * @param memory_address start address of memory to read
 * @param target_buffer the buffer of read data
 * @param byte_length the total length to read
 */
void DRV_EPD_SRAMHandleRead(    EInt memory_address,
                                uint8_t *target_buffer,
                                uint8_t byte_length)
{
    DRV_EPD_SRAMReadSequential( memory_address,
                                target_buffer,
                                byte_length);
}

/**
 * EPD global update function
 */
void DRV_EPD_UpdateGlobal(void)
{
    EPD_display_global( USE_EPD_Type,
                        previous_image_address,
                        new_image_address,
                        DRV_EPD_SRAMHandleRead);

    DRV_EPD_StoreScreen();
}

/**
 * EPD power on and initialization
 */
void DRV_EPD_PowerUp(void)
{
    if (EPD_PowerStatusGet() != true)
        EPD_power_init(USE_EPD_Type);
}

/**
 * EPD power down
 */
void DRV_EPD_PowerDown(void)
{
    if (EPD_PowerStatusGet() != false)
        EPD_power_end();
}

/**
 * EPD partial update function
 */
void DRV_EPD_UpdatePartial(void)
{
    EPD_display_partial(USE_EPD_Type,
                        previous_image_address,
                        new_image_address,
                        DRV_EPD_SRAMHandleRead);
    DRV_EPD_StoreScreen();
}

void DRV_GFX_UpdateBiStableScreen(bool fullScreen)
{
    if (fullScreen == true)
        DRV_EPD_UpdateGlobal();
    else
    {
        DRV_EPD_PowerUp();
        DRV_EPD_UpdatePartial();
        DRV_EPD_PowerDown();
    }

}


#endif

