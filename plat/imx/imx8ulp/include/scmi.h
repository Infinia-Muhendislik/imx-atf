/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _IMX8_SCMI_H
#define _IMX8_SCMI_H

#include <stdint.h>

#define SCMI_SHMEM_CHANNEL_ERROR	BIT_32(1)
#define SCMI_SHMEM_CHANNEL_FREE		BIT_32(0)

#define SCMI_SHMEM_FLAG_INTR_ENABLED	BIT_32(0)

struct scmi_shared_mem {
        uint32_t rsvd;
        uint32_t status;
        uint32_t rsvd1[2];
        uint32_t flags;
        uint32_t length;
        uint32_t header;
        uint8_t payload[0];
};

/* Corresponding to msg_payload */
struct response {
	uint32_t status;
	uint32_t data[0];
};

enum scmi_std_protocol {
	SCMI_PROTOCOL_BASE = 0x10,
	SCMI_PROTOCOL_POWER_DOMAIN = 0x11,
	SCMI_PROTOCOL_SYS_POWER = 0x12,
	SCMI_PROTOCOL_PERF_DOMAIN = 0x13,
	SCMI_PROTOCOL_CLK = 0x14,
	SCMI_PROTOCOL_SENSOR = 0x15,
	SCMI_PROTOCOL_RESET_DOMAIN = 0x16,
};

#define MSG_ID(m)	((m) & 0xff)
#define MSG_TYPE(m)	(((m) >> 8) & 0x3)
#define MSG_PRO_ID(m)	(((m) >> 10) & 0xff)
#define MSG_TOKEN(m)	(((m) >> 18) & 0x3ff)

enum {
	SCMI_POWER_DOMAIN_PROTOCOL	= 0x11,
	SCMI_SYS_PWR_DOMAIN_PROTOCOL	= 0x12,
	SCMI_PER_DOMAIN_PROTOCOL	= 0x13,
	SCMI_CLK_DOMAIN_PROTOCOL	= 0x14,
	SCMI_SENSOR_PROTOCOL		= 0x15,
};

#define PROTOCOL_VERSION			0
#define PROTOCOL_ATTRIBUTES			1
#define PROTOCOL_MESSAGE_ATTRIBUTES		2
#define BASE_DISCOVER_VENDOR			3
#define BASE_DISCOVER_SUB_VENDOR		4
#define BASE_DISCOVER_IMPLEMENTATION_VERSION	5
#define BASE_DISCOVER_LIST_PROTOCOLS		6
#define BASE_DISCOVER_AGENT			7
#define BASE_NOTIFY_ERRORS			8
#define BASE_SET_DEVICE_PERMISSIONS		9
#define BASE_SET_PROTOCOL_PERMISSIONS		0xA
#define BASE_RESET_AGENT_CONFIGURATION		0xB

enum {
	SCMI_RET_SUCCESS = 0,
	SCMI_RET_NOT_SUPPORTED = -1,
	SCMI_RET_INVALID_PARAMETERS = -2,
	SCMI_RET_DENIED = -3,
	SCMI_RET_NOT_FOUND = -4,
	SCMI_RET_OUT_OF_RANGE = -5,
	SCMI_RET_BUSY = -6,
	SCMI_RET_COMMS_ERROR = -7,
	SCMI_RET_GENERIC_ERROR = -8,
	SCMI_RET_HARDWARE_ERROR = -9,
	SCMI_RET_PROTOCOL_ERROR = -10,
};

#define POWER_DOMAIN_ATTRIBUTES		3
#define POWER_DOMAIN_SUPPORT_NOTIFICATION	BIT(31)
#define POWER_DOMAIN_SUPPORT_ASYNCHRONOUS	BIT(30)
#define POWER_DOMAIN_SUPPORT_SYNCHRONOUS	BIT(29)

#define POWER_STATE_SET			4
#define POWER_STATE_GET			5
#define POWER_STATE_NOTIFY		6
#define	POWER_STATE_CHANGE_REQUESTED_NOTIFY	7

int scmi_power_domain_handler(uint32_t msg_id, void *shmem);


#define PERFORMANCE_DOMAIN_ATTRIBUTES		3
#define PERFORMANCE_DESCRIBE_LEVELS		4
#define PERFORMANCE_LIMITS_SET			5
#define PERFORMANCE_LIMITS_GET			6
#define PERFORMANCE_LEVEL_SET			7
#define PERFORMANCE_LEVEL_GET			8
#define PERFORMANCE_NOTIFY_LIMITS		9
#define PERFORMANCE_NOTIFY_LEVEL		0xA
#define PERFORMANCE_DESCRIBE_FAST_CHANNEL	0xB

int scmi_perf_domain_handler(uint32_t msg_id, void *shmem);

#define SENSOR_DESCRIPTION_GET			0x003
#define SENSOR_CONFIG_SET			0x004
#define SENSOR_TRIP_POINT_SET			0x005
#define SENSOR_READING_GET			0x006

int scmi_sensor_handler(uint32_t msg_id, void *shmem);

#define SMC_SHMEM_BASE	0x2201f000

#endif
