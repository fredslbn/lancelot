/*
 * Copyright (c) 2017 MediaTek Inc.
 * Author: Dennis YC Hsieh <dennis-yc.hsieh@mediatek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _DT_BINDINGS_GCE_MT6765_H
#define _DT_BINDINGS_GCE_MT6765_H

/* assign timeout 0 also means default */
#define CMDQ_NO_TIMEOUT		0xffffffff
#define CMDQ_TIMEOUT_DEFAULT	1000

/* GCE thread priority */
#define CMDQ_THR_PRIO_LOWEST	0
#define CMDQ_THR_PRIO_1		1
#define CMDQ_THR_PRIO_2		2
#define CMDQ_THR_PRIO_3		3
#define CMDQ_THR_PRIO_4		4
#define CMDQ_THR_PRIO_5		5
#define CMDQ_THR_PRIO_6		6
#define CMDQ_THR_PRIO_HIGHEST	7

/* CPR count in 32bit register */
#define GCE_CPR_COUNT		1312

/* GCE subsys table */
#define SUBSYS_1300XXXX		0
#define SUBSYS_1400XXXX		1
#define SUBSYS_1401XXXX		2
#define SUBSYS_1402XXXX		3
#define SUBSYS_1502XXXX		4
#define SUBSYS_1880XXXX		5
#define SUBSYS_1881XXXX		6
#define SUBSYS_1882XXXX		7
#define SUBSYS_1883XXXX		8
#define SUBSYS_1884XXXX		9
#define SUBSYS_1000XXXX		10
#define SUBSYS_1001XXXX		11
#define SUBSYS_1002XXXX		12
#define SUBSYS_1003XXXX		13
#define SUBSYS_1004XXXX		14
#define SUBSYS_1005XXXX		15
#define SUBSYS_1020XXXX		16
#define SUBSYS_1028XXXX		17
#define SUBSYS_1700XXXX		18
#define SUBSYS_1701XXXX		19
#define SUBSYS_1702XXXX		20
#define SUBSYS_1703XXXX		21
#define SUBSYS_1800XXXX		22
#define SUBSYS_1801XXXX		23
#define SUBSYS_1802XXXX		24
#define SUBSYS_1804XXXX		25
#define SUBSYS_1805XXXX		26
#define SUBSYS_1808XXXX		27
#define SUBSYS_180aXXXX		28
#define SUBSYS_180bXXXX		29

/* GCE hardware events */
#define CMDQ_EVENT_MDP_RDMA0_SOF		0
#define CMDQ_EVENT_MDP_CCORR0_SOF		1
#define CMDQ_EVENT_MDP_RSZ0_SOF			2
#define CMDQ_EVENT_MDP_RSZ1_SOF			3
#define CMDQ_EVENT_MDP_WDMA_SOF			4
#define CMDQ_EVENT_MDP_WROT0_SOF		5
#define CMDQ_EVENT_MDP_TDSHP0_SOF		6
#define CMDQ_EVENT_DISP_OVL0_SOF		7
#define CMDQ_EVENT_DISP_2L_OVL0_SOF		8
#define CMDQ_EVENT_DISP_RDMA0_SOF		9
#define CMDQ_EVENT_DISP_WDMA0_SOF		10
#define CMDQ_EVENT_DISP_COLOR0_SOF		11
#define CMDQ_EVENT_DISP_CCORR0_SOF		12
#define CMDQ_EVENT_DISP_AAL0_SOF		13
#define CMDQ_EVENT_DISP_GAMMA0_SOF		14
#define CMDQ_EVENT_DISP_DITHER0_SOF		15
#define CMDQ_EVENT_DISP_DSI0_SOF		16
#define CMDQ_EVENT_DISP_RSZ0_SOF		17
#define CMDQ_EVENT_IMG_DL_RELAY_SOF		18
#define CMDQ_EVENT_DISP_PWM0_SOF		19
#define CMDQ_EVENT_MDP_RDMA0_EOF		20
#define CMDQ_EVENT_MDP_CCORR0_FRAME_DONE	21
#define CMDQ_EVENT_MDP_RSZ0_EOF			22
#define CMDQ_EVENT_MDP_RSZ1_EOF			23
#define CMDQ_EVENT_MDP_WROT0_W_EOF		24
#define CMDQ_EVENT_MDP_WDMA_EOF			25
#define CMDQ_EVENT_MDP_TDSHP0_EOF		26
#define CMDQ_EVENT_DISP_OVL0_EOF		27
#define CMDQ_EVENT_DISP_2L_OVL0_EOF		28
#define CMDQ_EVENT_DISP_RSZ0_EOF		29
#define CMDQ_EVENT_DISP_RDMA0_EOF		30
#define CMDQ_EVENT_DISP_WDMA0_EOF		31
#define CMDQ_EVENT_DISP_COLOR0_EOF		32
#define CMDQ_EVENT_DISP_CCORR0_EOF		33
#define CMDQ_EVENT_DISP_AAL0_EOF		34
#define CMDQ_EVENT_DISP_GAMMA0_EOF		35
#define CMDQ_EVENT_DISP_DITHER0_EOF		36
#define CMDQ_EVENT_DISP_DSI0_EOF		37
#define CMDQ_EVENT_MUTEX0_STREAM_EOF		130
#define CMDQ_EVENT_MUTEX1_STREAM_EOF		131
#define CMDQ_EVENT_MUTEX2_STREAM_EOF		132
#define CMDQ_EVENT_MUTEX3_STREAM_EOF		133
#define CMDQ_EVENT_MUTEX4_STREAM_EOF		134
#define CMDQ_EVENT_MUTEX5_STREAM_EOF		135
#define CMDQ_EVENT_MUTEX6_STREAM_EOF		136
#define CMDQ_EVENT_MUTEX7_STREAM_EOF		137
#define CMDQ_EVENT_MUTEX8_STREAM_EOF		138
#define CMDQ_EVENT_MUTEX9_STREAM_EOF		139
#define CMDQ_EVENT_DISP_RDMA0_UNDERRUN		140
#define CMDQ_EVENT_DSI0_TE			141
#define CMDQ_EVENT_DSI0_IRQ_EVENT		142
#define CMDQ_EVENT_DSI0_DONE_EVENT		143
#define CMDQ_EVENT_DISP_WDMA0_RST_DONE		147
#define CMDQ_EVENT_MDP_WDMA_RST_DONE		148
#define CMDQ_EVENT_MDP_WROT0_RST_DONE		149
#define CMDQ_EVENT_MDP_RDMA0_RST_DONE		151
#define CMDQ_EVENT_DISP_OVL0_RST_DONE		152
#define CMDQ_EVENT_DIP_CQ_THREAD0_EOF		257
#define CMDQ_EVENT_DIP_CQ_THREAD1_EOF		258
#define CMDQ_EVENT_DIP_CQ_THREAD2_EOF		259
#define CMDQ_EVENT_DIP_CQ_THREAD3_EOF		260
#define CMDQ_EVENT_DIP_CQ_THREAD4_EOF		261
#define CMDQ_EVENT_DIP_CQ_THREAD5_EOF		262
#define CMDQ_EVENT_DIP_CQ_THREAD6_EOF		263
#define CMDQ_EVENT_DIP_CQ_THREAD7_EOF		264
#define CMDQ_EVENT_DIP_CQ_THREAD8_EOF		265
#define CMDQ_EVENT_DIP_CQ_THREAD9_EOF		266
#define CMDQ_EVENT_DIP_CQ_THREAD10_EOF		267
#define CMDQ_EVENT_DIP_CQ_THREAD11_EOF		268
#define CMDQ_EVENT_DIP_CQ_THREAD12_EOF		269
#define CMDQ_EVENT_DIP_CQ_THREAD13_EOF		270
#define CMDQ_EVENT_DIP_CQ_THREAD14_EOF		271
#define CMDQ_EVENT_DIP_CQ_THREAD15_EOF		272
#define CMDQ_EVENT_DIP_CQ_THREAD16_EOF		273
#define CMDQ_EVENT_DIP_CQ_THREAD17_EOF		274
#define CMDQ_EVENT_DIP_CQ_THREAD18_EOF		275
#define CMDQ_EVENT_DVE_EOF			276
#define CMDQ_EVENT_WMF_EOF			277
#define CMDQ_EVENT_RSC_EOF			278
#define CMDQ_EVENT_VENC_EOF			289
#define CMDQ_EVENT_JPEG_ENC_EOF			290
#define CMDQ_EVENT_JPEG_DEC_EOF			291
#define CMDQ_EVENT_VENC_MB_DONE			292
#define CMDQ_EVENT_VENC_128BYTE_CNT_DONE	293


/* CMDQ sw tokens
 * Following definitions are gce sw token which may use by clients
 * event operation API.
 * Note that token 512 to 639 may set secure
 */

/* end of hw event and begin of sw token */
#define CMDQ_MAX_HW_EVENT				512

/* Config thread notify trigger thread */
#define CMDQ_SYNC_TOKEN_CONFIG_DIRTY			640
/* Trigger thread notify config thread */
#define CMDQ_SYNC_TOKEN_STREAM_EOF			641
/* Block Trigger thread until the ESD check finishes. */
#define CMDQ_SYNC_TOKEN_ESD_EOF				642
#define CMDQ_SYNC_TOKEN_STREAM_BLOCK			643
/* check CABC setup finish */
#define CMDQ_SYNC_TOKEN_CABC_EOF			644

/* Notify normal CMDQ there are some secure task done
 * MUST NOT CHANGE, this token sync with secure world
 */
#define CMDQ_SYNC_SECURE_THR_EOF			647

/* CMDQ use sw token */
#define CMDQ_SYNC_TOKEN_USER_0				649
#define CMDQ_SYNC_TOKEN_USER_1				650
#define CMDQ_SYNC_TOKEN_POLL_MONITOR			651
#define CMDQ_SYNC_TOKEN_TPR_LOCK			652

/* ISP sw token */
#define CMDQ_SYNC_TOKEN_MSS				665
#define CMDQ_SYNC_TOKEN_MSF				666

/* GPR access tokens (for HW register backup)
 * There are 15 32-bit GPR, 3 GPR form a set
 * (64-bit for address, 32-bit for value)
 * MUST NOT CHANGE, these tokens sync with MDP
 */
#define CMDQ_SYNC_TOKEN_GPR_SET_0			700
#define CMDQ_SYNC_TOKEN_GPR_SET_1			701
#define CMDQ_SYNC_TOKEN_GPR_SET_2			702
#define CMDQ_SYNC_TOKEN_GPR_SET_3			703
#define CMDQ_SYNC_TOKEN_GPR_SET_4			704

/* Resource lock event to control resource in GCE thread */
#define CMDQ_SYNC_RESOURCE_WROT0			710
#define CMDQ_SYNC_RESOURCE_WROT1			711

/* event for gpr timer, used in sleep and poll with timeout */
#define CMDQ_TOKEN_GPR_TIMER_R0				994
#define CMDQ_TOKEN_GPR_TIMER_R1				995
#define CMDQ_TOKEN_GPR_TIMER_R2				996
#define CMDQ_TOKEN_GPR_TIMER_R3				997
#define CMDQ_TOKEN_GPR_TIMER_R4				998
#define CMDQ_TOKEN_GPR_TIMER_R5				999
#define CMDQ_TOKEN_GPR_TIMER_R6				1000
#define CMDQ_TOKEN_GPR_TIMER_R7				1001
#define CMDQ_TOKEN_GPR_TIMER_R8				1002
#define CMDQ_TOKEN_GPR_TIMER_R9				1003
#define CMDQ_TOKEN_GPR_TIMER_R10			1004
#define CMDQ_TOKEN_GPR_TIMER_R11			1005
#define CMDQ_TOKEN_GPR_TIMER_R12			1006
#define CMDQ_TOKEN_GPR_TIMER_R13			1007
#define CMDQ_TOKEN_GPR_TIMER_R14			1008
#define CMDQ_TOKEN_GPR_TIMER_R15			1009

#define CMDQ_EVENT_MAX					0x3FF
/* CMDQ sw tokens END */

#endif
