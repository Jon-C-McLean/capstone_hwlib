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

void create_motor_mit_frame(motor_t *motor, motor_pid_t *pid, can_message_t *frame) {
    motor_params_t *params;

    switch(motor->type) {
        case MOTOR_AK80_64:
            params = &AK80_64_Params;
        case MOTOR_AK10_9:
        default:
            params = &AK80_64_Params;
    };

    float fixedPos = fminf(fmaxf(pid->pos, params->posMin), params->posMax);
    float fixedVel = fminf(fmaxf(pid->vel, params->velMin), params->velMax);
    float fixedTorque = fminf(fmaxf(pid->torque, params->torqueMin), params->torqueMax);
    float fixedKp = fminf(fmaxf(pid->kp, params->kpMin), params->kpMax);
    float fixedKd = fminf(fmaxf(pid->kd, params->kdMin), params->kdMax);

    uint16_t unsignedPos = float_to_uint(fixedPos, params->posMin, params->posMax, 16);
    uint16_t unsignedVel = float_to_uint(fixedVel, params->velMin, params->velMax, 12);
    uint16_t unsignedTorque = float_to_uint(fixedTorque, params->torqueMin, params->torqueMax, 12);
    uint16_t unsignedKp = float_to_uint(fixedKp, params->kpMin, params->kpMax, 12);
    uint16_t unsignedKd = float_to_uint(fixedKd, params->kdMin, params->kdMax, 12);

    frame->id = motor->id;
    frame->dlc = 8;
    frame->rtr = 0;
    
    frame->dataByte0 = (unsignedPos >> 8);
    frame->dataByte1 = (unsignedPos & 0xFF);
    
    frame->dataByte2 = (unsignedVel >> 4);
    frame->dataByte3 = ((unsignedVel & 0xF) << 4)|(unsignedKp >> 8);
    frame->dataByte4 = (unsignedKp & 0xFF);
    frame->dataByte5 = (unsignedKd >> 4);
    frame->dataByte6 = ((unsignedKd & 0xF) << 4)|(unsignedTorque >> 8);
    frame->dataByte7 = (unsignedTorque & 0xFF);
}