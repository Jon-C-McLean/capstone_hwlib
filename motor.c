/**
 * @file motor.c
 * @author Jon McLean (joncmclean@proton.me)
 * 
 * @copyright Copyright (c) 2023 Jon McLean
 */

#include "motor.h"

// MARK: Private Function Prototypes
uint16_t float_to_uint(float x, float xMin, float xMax, uint8_t bits);
float uint_to_float(uint16_t xInt, float xMin, float xMax, uint8_t bits);

// MARK: Function Definitions

uint16_t float_to_uint(float x, float xMin, float xMax, uint8_t bits) { // TODO: Validate
    float xRange = xMax - xMin;
    float xNorm = (x - xMin) / xRange;
    uint16_t xInt = (uint16_t)(xNorm * (float)((1 << bits) - 1));

    return xInt;
}

float uint_to_float(uint16_t xInt, float xMin, float xMax, uint8_t bits) { // TODO: Validate
    float xRange = xMax - xMin;
    float xNorm = (float)xInt / (float)((1 << bits) - 1);
    float x = (xNorm * xRange) + xMin;

    return x;
}

void create_motor_mit_frame(motor_pid_t *pid, can_message_t *frame) {
    
}