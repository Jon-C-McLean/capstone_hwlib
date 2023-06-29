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

#define AK80_64_P_MIN -12.5
#define AK80_64_P_MAX 12.5
#define AK80_64_V_MIN -8.0
#define AK80_64_V_MAX 8.0
#define AK80_64_T_MIN -144.0
#define AK80_64_T_MAX 144.0
#define AK80_64_KP_MIN 0.0
#define AK80_64_KP_MAX 500.0
#define AK80_64_KD_MIN 0.0
#define AK80_64_KD_MAX 5.0
#define AK80_64_KT 0.119
#define AK80_64_RATIO 6.0
#define AK80_64_DIRECTION 1

#define AK10_9_P_MIN -12.5
#define AK10_9_P_MAX 12.5
#define AK10_9_V_MIN -50.0
#define AK10_9_V_MAX 50.0
#define AK10_9_T_MIN -65.0
#define AK10_9_T_MAX 65.0
#define AK10_9_KP_MIN 0.0
#define AK10_9_KP_MAX 500.0
#define AK10_9_KD_MIN 0.0
#define AK10_9_KD_MAX 5.0
#define AK10_9_KT 0.16
#define AK10_9_RATIO 9.0
#define AK10_9_DIRECTION 1

#endif