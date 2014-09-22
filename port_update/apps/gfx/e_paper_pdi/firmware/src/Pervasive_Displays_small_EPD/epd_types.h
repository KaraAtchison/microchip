/* 
 * File:   epd_types.h
 * Author: c13522
 *
 * Created on July 29, 2014, 3:46 PM
 */

#ifndef EPD_TYPES_H
#define	EPD_TYPES_H

#include <stdint.h>
#include "system.h"

#ifdef	__cplusplus
extern "C" {
#endif

typedef  unsigned int EInt;
/**
 * \brief Developer needs to create an external function if wants to read memory */
typedef void (*EPD_read_memory_handler) (   EInt memory_address,
                                            uint8_t *target_buffer,
                                            uint8_t byte_length);

/**
 * \brief Support 1.44", 2" and 2.7" three type EPD */
//typedef enum
//{
//    EPD_144 = 0,
//    EPD_200 = 1,
//    EPD_270 = 2,
//} EPD_TYPES;

#define DELAY_US_CONSTANT (SYS_CLK_FrequencyInstructionGet()/1000000L)
#define DELAY_MS_CONSTANT (SYS_CLK_FrequencyInstructionGet()/1000L)

#define delay_us(x) __delay32(x*DELAY_US_CONSTANT)  // delays x us
#define delay_ms(x) __delay32(x*DELAY_MS_CONSTANT)  // delays x ms


#ifdef	__cplusplus
}
#endif

#endif	/* EPD_TYPES_H */

