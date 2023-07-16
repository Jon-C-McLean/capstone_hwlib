/**
 * @file canio.c
 * @author Jon McLean (joncmclean@proton.me)
 * 
 * @copyright Copyright (c) 2023 Jon McLean
 */

#include "canio.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void canio_create_interface(can_interface_t* interface, uint8_t busNumber, can_bus_type busType, uint32_t bitrate) {
    assert(interface != NULL && "Interface pointer cannot be NULL");
    printf("wtf");
    char* busName;

    switch(busType) {
        case CAN_BUS_TYPE_VIRTUAL:
            busName = "vcan";
            break;
        case CAN_BUS_TYPE_PHYSICAL:
        default:
            busName = "can";
            break;
    };

    ssize_t interfaceSize = snprintf(NULL, 0, "%s%d", busName, busNumber)+1;
    char* interfaceId = malloc(interfaceSize);
    snprintf(interfaceId, interfaceSize, "%s%d", busName, busNumber);

    interface->bus = interfaceId;
    interface->bitrate = bitrate;
    interface->s = -1;
}

void canio_destroy_interface(can_interface_t* interface) {
    if(interface->bus != NULL) {
        free(interface->bus);
    }
}

void canio_open_interface(can_interface_t* interface) {
    int res = interface->s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(res < 0) {
        fprintf(stderr, "Error while opening socket: %d\r\n", res);
        exit(EXIT_FAILURE);
    }

    strcpy(interface->internal->ifr.ifr_name, interface->bus);
    ioctl(interface->s, SIOCGIFINDEX, &interface->internal->ifr);

    memset(&interface->internal->addr, 0, sizeof(interface->internal->addr));
    interface->internal->addr.can_family = AF_CAN;
    interface->internal->addr.can_ifindex = interface->internal->ifr.ifr_ifindex;

    res = bind(interface->s, (struct sockaddr*)&interface->internal->addr, sizeof(interface->internal->addr));
    if(res < 0) {
        fprintf(stderr, "Error while binding socket: %d\r\n", res);
        exit(EXIT_FAILURE);
    }
}

void canio_close_interface(can_interface_t* interface) {
    if(interface->s != -1) {
        int res = close(interface->s);

        if(res < 0) {
            fprintf(stderr, "Error while closing socket: %d\r\n", res);
            exit(EXIT_FAILURE);
        }
    }
}

void canio_send_message(can_interface_t* interface, can_message_t* message) {
    struct can_frame frame;
    frame.can_id = message->id;
    frame.can_dlc = message->dlc;
    
    frame.data[0] = message->dataByte0;
    frame.data[1] = message->dataByte1;
    frame.data[2] = message->dataByte2;
    frame.data[3] = message->dataByte3;
    frame.data[4] = message->dataByte4;
    frame.data[5] = message->dataByte5;
    frame.data[6] = message->dataByte6;
    frame.data[7] = message->dataByte7;

    int res = write(interface->s, &frame, sizeof(frame));
    if(res != sizeof(struct can_frame)) {
        fprintf(stderr, "Error while sending message: %d\r\n", res);
        exit(EXIT_FAILURE);
    }
}