/*****************************************************************************
  AUTO-GENERATED CODE:  Graphics Resource Converter version: 4.01.00

  Company:
      Microchip Technology, Inc.
 
  File Name:
     image_resources_epd_2.0_inch_demo_reference.c
 
  Summary:
      This file is generated by the Microchip's Graphics Resource Converter.
  Description:
      This file is generated by the Graphics Resource Converter containing
      resources such as images and fonts that can be used by Microchip's
      Graphics Library, which is part of the MLA.
 *****************************************************************************/

// DOM-IGNORE-BEGIN
/*****************************************************************************
  Software License Agreement

  Copyright(c) 2013 Microchip Technology Inc.  All rights reserved.
  Microchip licenses to you the right to use, modify, copy and distribute
  Software only when embedded on a Microchip microcontroller or digital
  signal controller that is integrated into your product or third party
  product (pursuant to the sublicense terms in the accompanying license
  agreement).
 
  You should refer to the license agreement accompanying this Software
  for additional information regarding your rights and obligations.
 
  SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
  OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
  PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
  OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
  BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
  DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
  INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
  COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
  CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
  OR OTHER SIMILAR COSTS.
 *****************************************************************************/
// DOM-IGNORE-END

/*****************************************************************************
 * SECTION:  Includes
 *****************************************************************************/
#include <gfx/gfx.h>
#include <stdint.h>

/*****************************************************************************
 * SECTION:  Graphics Library Format Check
 *****************************************************************************/
#ifndef GFX_RESOURCE_FORMAT_VERSION
    #if(GRAPHICS_LIBRARY_VERSION != 0x0400)
    #warning "It is suggested to use Graphics Library version 4.00 or later with this version of GRC."
    #endif
#elif(GFX_RESOURCE_FORMAT_VERSION != 0x0100)
#warning "It is suggested to use Graphics Library with the resource format version 1.00 with this version of GRC."
#endif

/*****************************************************************************
 * SECTION:  Graphics Bitmap Padding Check
 *****************************************************************************/
#ifdef GFX_CONFIG_IMAGE_PADDING_DISABLE
#error These bitmap resources have been converted with padding of the horizontal lines, but GFX_CONFIG_IMAGE_PADDING_DISABLE is defined in system_config.h.
#endif


/*****************************************************************************
 * SECTION:  Graphics Configuration: Bitmap Check
 *****************************************************************************/

#ifdef GFX_CONFIG_IMAGE_FLASH_DISABLE
#error The GFX_CONFIG_IMAGE_FLASH_DISABLE is defined in system_config.h header file.
#endif


/*****************************************************************************
 * SECTION:  BITMAPS
 *****************************************************************************/

/*********************************
 * Bitmap Structure
 * Label: GLA_barchart_BG_2_inch
 * Description:  200x96 pixels, 1-bits per pixel
 ***********************************/
#if defined (GFX_CONFIG_IMAGE_PACKED_ENABLE) && (__XC16_VERSION__ >= 1011)
extern uint8_gfx_image_prog __GLA_barchart_BG_2_inch[] __attribute__((section("grc_images")));
#else
extern uint8_gfx_image_prog __GLA_barchart_BG_2_inch[] __attribute__((section("grc_images"), aligned(2)));
#endif

const GFX_RESOURCE_HDR GLA_barchart_BG_2_inch =
{
    .type = (GFX_RESOURCE_MEMORY_FLASH | GFX_RESOURCE_TYPE_MCHP_MBITMAP | GFX_RESOURCE_COMP_NONE),
    .ID = 0,
    .resource.image.location.progByteAddress = (uint8_gfx_image_prog *) __GLA_barchart_BG_2_inch,
    .resource.image.width = 200,
    .resource.image.height = 96,
    .resource.image.parameter1.compressedSize = 0,
    .resource.image.parameter2.rawSize = 2408,
    .resource.image.colorDepth = 1,
    .resource.image.type = 0x00,
    .resource.image.paletteID = 0x0000
};

/*********************************
 * Bitmap Structure
 * Label: GLA_front_menu_BG_2_inch
 * Description:  200x96 pixels, 1-bits per pixel
 ***********************************/
#if defined (GFX_CONFIG_IMAGE_PACKED_ENABLE) && (__XC16_VERSION__ >= 1011)
extern uint8_gfx_image_prog __GLA_front_menu_BG_2_inch[] __attribute__((section("grc_images")));
#else
extern uint8_gfx_image_prog __GLA_front_menu_BG_2_inch[] __attribute__((section("grc_images"), aligned(2)));
#endif

const GFX_RESOURCE_HDR GLA_front_menu_BG_2_inch =
{
    .type = (GFX_RESOURCE_MEMORY_FLASH | GFX_RESOURCE_TYPE_MCHP_MBITMAP | GFX_RESOURCE_COMP_NONE),
    .ID = 0,
    .resource.image.location.progByteAddress = (uint8_gfx_image_prog *) __GLA_front_menu_BG_2_inch,
    .resource.image.width = 200,
    .resource.image.height = 96,
    .resource.image.parameter1.compressedSize = 0,
    .resource.image.parameter2.rawSize = 2408,
    .resource.image.colorDepth = 1,
    .resource.image.type = 0x00,
    .resource.image.paletteID = 0x0000
};

/*********************************
 * Bitmap Structure
 * Label: GLA_ECG_BG_2_inch
 * Description:  200x96 pixels, 1-bits per pixel
 ***********************************/
#if defined (GFX_CONFIG_IMAGE_PACKED_ENABLE) && (__XC16_VERSION__ >= 1011)
extern uint8_gfx_image_prog __GLA_ECG_BG_2_inch[] __attribute__((section("grc_images")));
#else
extern uint8_gfx_image_prog __GLA_ECG_BG_2_inch[] __attribute__((section("grc_images"), aligned(2)));
#endif

const GFX_RESOURCE_HDR GLA_ECG_BG_2_inch =
{
    .type = (GFX_RESOURCE_MEMORY_FLASH | GFX_RESOURCE_TYPE_MCHP_MBITMAP | GFX_RESOURCE_COMP_NONE),
    .ID = 0,
    .resource.image.location.progByteAddress = (uint8_gfx_image_prog *) __GLA_ECG_BG_2_inch,
    .resource.image.width = 200,
    .resource.image.height = 96,
    .resource.image.parameter1.compressedSize = 0,
    .resource.image.parameter2.rawSize = 2408,
    .resource.image.colorDepth = 1,
    .resource.image.type = 0x00,
    .resource.image.paletteID = 0x0000
};

/*********************************
 * Bitmap Structure
 * Label: GLA_HVAC_BG_2_inch
 * Description:  200x96 pixels, 1-bits per pixel
 ***********************************/
#if defined (GFX_CONFIG_IMAGE_PACKED_ENABLE) && (__XC16_VERSION__ >= 1011)
extern uint8_gfx_image_prog __GLA_HVAC_BG_2_inch[] __attribute__((section("grc_images")));
#else
extern uint8_gfx_image_prog __GLA_HVAC_BG_2_inch[] __attribute__((section("grc_images"), aligned(2)));
#endif

const GFX_RESOURCE_HDR GLA_HVAC_BG_2_inch =
{
    .type = (GFX_RESOURCE_MEMORY_FLASH | GFX_RESOURCE_TYPE_MCHP_MBITMAP | GFX_RESOURCE_COMP_NONE),
    .ID = 0,
    .resource.image.location.progByteAddress = (uint8_gfx_image_prog *) __GLA_HVAC_BG_2_inch,
    .resource.image.width = 200,
    .resource.image.height = 96,
    .resource.image.parameter1.compressedSize = 0,
    .resource.image.parameter2.rawSize = 2408,
    .resource.image.colorDepth = 1,
    .resource.image.type = 0x00,
    .resource.image.paletteID = 0x0000
};

/*********************************
 * Bitmap Structure
 * Label: ECG_2_inch
 * Description:  190x61 pixels, 1-bits per pixel
 ***********************************/
#if defined (GFX_CONFIG_IMAGE_PACKED_ENABLE) && (__XC16_VERSION__ >= 1011)
extern uint8_gfx_image_prog __ECG_2_inch[] __attribute__((section("grc_images")));
#else
extern uint8_gfx_image_prog __ECG_2_inch[] __attribute__((section("grc_images"), aligned(2)));
#endif

const GFX_RESOURCE_HDR ECG_2_inch =
{
    .type = (GFX_RESOURCE_MEMORY_FLASH | GFX_RESOURCE_TYPE_MCHP_MBITMAP | GFX_RESOURCE_COMP_NONE),
    .ID = 0,
    .resource.image.location.progByteAddress = (uint8_gfx_image_prog *) __ECG_2_inch,
    .resource.image.width = 190,
    .resource.image.height = 61,
    .resource.image.parameter1.compressedSize = 0,
    .resource.image.parameter2.rawSize = 1472,
    .resource.image.colorDepth = 1,
    .resource.image.type = 0x00,
    .resource.image.paletteID = 0x0000
};

/*********************************
 * Bitmap Structure
 * Label: Fan1
 * Description:  53x53 pixels, 1-bits per pixel
 ***********************************/
#if defined (GFX_CONFIG_IMAGE_PACKED_ENABLE) && (__XC16_VERSION__ >= 1011)
extern uint8_gfx_image_prog __Fan1[] __attribute__((section("grc_images")));
#else
extern uint8_gfx_image_prog __Fan1[] __attribute__((section("grc_images"), aligned(2)));
#endif

const GFX_RESOURCE_HDR Fan1 =
{
    .type = (GFX_RESOURCE_MEMORY_FLASH | GFX_RESOURCE_TYPE_MCHP_MBITMAP | GFX_RESOURCE_COMP_NONE),
    .ID = 0,
    .resource.image.location.progByteAddress = (uint8_gfx_image_prog *) __Fan1,
    .resource.image.width = 53,
    .resource.image.height = 53,
    .resource.image.parameter1.compressedSize = 0,
    .resource.image.parameter2.rawSize = 376,
    .resource.image.colorDepth = 1,
    .resource.image.type = 0x00,
    .resource.image.paletteID = 0x0000
};

/*********************************
 * Bitmap Structure
 * Label: Fan2
 * Description:  53x53 pixels, 1-bits per pixel
 ***********************************/
#if defined (GFX_CONFIG_IMAGE_PACKED_ENABLE) && (__XC16_VERSION__ >= 1011)
extern uint8_gfx_image_prog __Fan2[] __attribute__((section("grc_images")));
#else
extern uint8_gfx_image_prog __Fan2[] __attribute__((section("grc_images"), aligned(2)));
#endif

const GFX_RESOURCE_HDR Fan2 =
{
    .type = (GFX_RESOURCE_MEMORY_FLASH | GFX_RESOURCE_TYPE_MCHP_MBITMAP | GFX_RESOURCE_COMP_NONE),
    .ID = 0,
    .resource.image.location.progByteAddress = (uint8_gfx_image_prog *) __Fan2,
    .resource.image.width = 53,
    .resource.image.height = 53,
    .resource.image.parameter1.compressedSize = 0,
    .resource.image.parameter2.rawSize = 376,
    .resource.image.colorDepth = 1,
    .resource.image.type = 0x00,
    .resource.image.paletteID = 0x0000
};

/*********************************
 * Bitmap Structure
 * Label: Fan3
 * Description:  53x53 pixels, 1-bits per pixel
 ***********************************/
#if defined (GFX_CONFIG_IMAGE_PACKED_ENABLE) && (__XC16_VERSION__ >= 1011)
extern uint8_gfx_image_prog __Fan3[] __attribute__((section("grc_images")));
#else
extern uint8_gfx_image_prog __Fan3[] __attribute__((section("grc_images"), aligned(2)));
#endif

const GFX_RESOURCE_HDR Fan3 =
{
    .type = (GFX_RESOURCE_MEMORY_FLASH | GFX_RESOURCE_TYPE_MCHP_MBITMAP | GFX_RESOURCE_COMP_NONE),
    .ID = 0,
    .resource.image.location.progByteAddress = (uint8_gfx_image_prog *) __Fan3,
    .resource.image.width = 53,
    .resource.image.height = 53,
    .resource.image.parameter1.compressedSize = 0,
    .resource.image.parameter2.rawSize = 376,
    .resource.image.colorDepth = 1,
    .resource.image.type = 0x00,
    .resource.image.paletteID = 0x0000
};

/*********************************
 * Bitmap Structure
 * Label: heart0
 * Description:  14x13 pixels, 1-bits per pixel
 ***********************************/
#if defined (GFX_CONFIG_IMAGE_PACKED_ENABLE) && (__XC16_VERSION__ >= 1011)
extern uint8_gfx_image_prog __heart0[] __attribute__((section("grc_images")));
#else
extern uint8_gfx_image_prog __heart0[] __attribute__((section("grc_images"), aligned(2)));
#endif

const GFX_RESOURCE_HDR heart0 =
{
    .type = (GFX_RESOURCE_MEMORY_FLASH | GFX_RESOURCE_TYPE_MCHP_MBITMAP | GFX_RESOURCE_COMP_NONE),
    .ID = 0,
    .resource.image.location.progByteAddress = (uint8_gfx_image_prog *) __heart0,
    .resource.image.width = 14,
    .resource.image.height = 13,
    .resource.image.parameter1.compressedSize = 0,
    .resource.image.parameter2.rawSize = 32,
    .resource.image.colorDepth = 1,
    .resource.image.type = 0x00,
    .resource.image.paletteID = 0x0000
};

/*********************************
 * Bitmap Structure
 * Label: heart1
 * Description:  14x13 pixels, 1-bits per pixel
 ***********************************/
#if defined (GFX_CONFIG_IMAGE_PACKED_ENABLE) && (__XC16_VERSION__ >= 1011)
extern uint8_gfx_image_prog __heart1[] __attribute__((section("grc_images")));
#else
extern uint8_gfx_image_prog __heart1[] __attribute__((section("grc_images"), aligned(2)));
#endif

const GFX_RESOURCE_HDR heart1 =
{
    .type = (GFX_RESOURCE_MEMORY_FLASH | GFX_RESOURCE_TYPE_MCHP_MBITMAP | GFX_RESOURCE_COMP_NONE),
    .ID = 0,
    .resource.image.location.progByteAddress = (uint8_gfx_image_prog *) __heart1,
    .resource.image.width = 14,
    .resource.image.height = 13,
    .resource.image.parameter1.compressedSize = 0,
    .resource.image.parameter2.rawSize = 32,
    .resource.image.colorDepth = 1,
    .resource.image.type = 0x00,
    .resource.image.paletteID = 0x0000
};

