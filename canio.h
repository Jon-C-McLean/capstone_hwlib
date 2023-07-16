/**
 * @file canio.h
 * @author Jon McLean (joncmclean@proton.me)
 * 
 * @copyright Copyright (c) 2023 Jon McLean
 */

#ifndef CANIO_H_
#define CANIO_H_

#include <string.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "can_message.h"

typedef struct {
    struct sockaddr_can addr;
    struct ifreq ifr;
} can_internal_t;

typedef struct {
    char* bus;
    uint32_t bitrate;
    int s; // Socket file descriptor
    can_internal_t *internal;
} can_interface_t;

typedef enum {
    CAN_BUS_TYPE_PHYSICAL,
    CAN_BUS_TYPE_VIRTUAL,
} can_bus_type;

// Function Prototypes

void canio_create_interface(can_interface_t* interface, uint8_t busNumber, can_bus_type busType, uint32_t bitrate);
void canio_destroy_interface(can_interface_t* interface);
void canio_open_interface(can_interface_t* interface);
void canio_close_interface(can_interface_t* interface);

void canio_send_message(can_interface_t* interface, can_message_t* message);
// void canio_read_nonblocking(can_interface_t* interface, can_message_t* message);

#endif