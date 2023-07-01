/**
 * @file can_message.h
 * @author Jon McLean (joncmclean@proton.me)
 * 
 * @copyright Copyright (c) 2023 Jon McLean
 */

#ifndef CAN_FRAME_H_
#define CAN_FRAME_H_

#include <stdint.h>

#if defined(__CC_ARM)
    #pragma anon_unions
#endif

typedef struct {
    struct {
        uint32_t id: 11; // Standard Frame ID
    };
    union {
        struct {
            uint32_t word0;
            uint32_t word1;
        };
        struct { // Assumes system endianess
            uint8_t dataByte3;
            uint8_t dataByte2;
            uint8_t dataByte1;
            uint8_t dataByte0;
            uint8_t dataByte7;
            uint8_t dataByte6;
            uint8_t dataByte5;
            uint8_t dataByte4;
        };
    };
} can_message_t;

#endif