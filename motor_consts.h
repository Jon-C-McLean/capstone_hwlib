/**
 * @file motor_consts.h
 * @author Jon McLean (joncmclean@proton.me)
 * 
 * @brief This file contains PID min/max values for the AK80-64 and AK10-9 motors.
 * 
 * @copyright Copyright (c) 2023 Jon McLean 
 */

#ifndef MOTOR_CONSTS_H_
#define MOTOR_CONSTS_H_

typedef struct {
    float posMax;
    float posMin;
    float velMax;
    float velMin;
    float torqueMax;
    float torqueMin;
    float kpMax;
    float kpMin;
    float kdMax;
    float kdMin;
    float kt;
    float ratio;
} motor_params_t;

static const motor_params_t AK80_64_Params = {
    .posMax = 12.5,
    .posMin = -12.5,
    .velMax = 8.0,
    .velMin = -8.0,
    .torqueMax = 144.0,
    .torqueMin = -144.0,
    .kpMax = 500.0,
    .kpMin = 0.0,
    .kdMax = 5.0,
    .kdMin = 0.0,
    .kt = 0.119,
    .ratio = 6.0,
};

static const motor_params_t AK10_9_Params = {
    .posMax = 12.5,
    .posMin = -12.5,
    .velMax = 50.0,
    .velMin = -50.0,
    .torqueMax = 65.0,
    .torqueMin = -65.0,
    .kpMax = 500.0,
    .kpMin = 0.0,
    .kdMax = 5.0,
    .kdMin = 0.0,
    .kt = 0.16,
    .ratio = 9.0,
};

#endif