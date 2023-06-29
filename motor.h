/**
 * @file motor.h
 * @author Jon McLean
 * 
 * @copyright Copyright (c) 2023 Jon McLean
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <stdint.h>

typedef enum {
    MOTOR_AK80_64 = 0U,
    MOTOR_AK10_9
} motor_type_t;

typedef struct {
    float pos;
    float vel;
    float torque;
    float kp;
    float kd;
    motor_type_t motor;
    uint8_t motorId;
} motor_pid_t;

typedef struct {
    float pos;
    float vel;
    float torque;
    motor_type_t motor;
    uint8_t motorId;
} motor_feedback_t;

#endif