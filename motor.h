/**
 * @file motor.h
 * @author Jon McLean
 * 
 * @copyright Copyright (c) 2023 Jon McLean
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <stdint.h>
#include <math.h>

#include "motor_consts.h"
#include "can_message.h"

typedef enum {
    MOTOR_AK80_64 = 0U,
    MOTOR_AK10_9 = 1U,
} motor_type_t;

typedef struct {
    motor_type_t type;
    uint8_t id;
} motor_t;

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


// MARK: Function prototypes

/**
 * @brief Creates a CAN message for the specified motor using MIT control
 * 
 * @param pid MIT control values
 * @param frame Output CAN frame
 */
void create_motor_mit_frame(motor_pid_t *pid, can_message_t *frame);

/**
 * @brief Parses the provided CAN message into positional feedback
 * 
 * @param frame Provided motor CAN frame
 * @param feedback Parsed feedback
 */
void parse_motor_feedback_frame(can_message_t *frame, motor_feedback_t *feedback);

#endif