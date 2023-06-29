/**
 * @file can_frame.h
 * @author Jon McLean (joncmclean@proton.me)
 * 
 * @copyright Copyright (c) 2023 Jon McLean
 */

#ifndef CAN_FRAME_H_
#define CAN_FRAME_H_

#include <stdint.h>

typedef struct {
    uint8_t id;
    uint8_t data[8];
    uint8_t dlc;
    // TODO: Add flags
} can_message_t;

#endif