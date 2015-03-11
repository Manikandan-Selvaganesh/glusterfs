/*
  Copyright (c) 2013 Red Hat, Inc. <http://www.redhat.com>
  This file is part of GlusterFS.

  This file is licensed to you under your choice of the GNU Lesser
  General Public License, version 3 or any later version (LGPLv3 or
  later), or the GNU General Public License, version 2 (GPLv2), in all
  cases as published by the Free Software Foundation.
*/

#ifndef _TRANSPORT_MESSAGES_H_
#define _TRANSPORT_MESSAGES_H_

#ifndef _CONFIG_H
#define _CONFIG_H
#include "config.h"
#endif

#include "glfs-message-id.h"

/* NOTE: Rules for message additions
 * 1) Each instance of a message is _better_ left with a unique message ID, even
 *    if the message format is the same. Reasoning is that, if the message
 *    format needs to change in one instance, the other instances are not
 *    impacted or the new change does not change the ID of the instance being
 *    modified.
 * 2) Addition of a message,
 *       - Should increment the GLFS_NUM_MESSAGES
 *       - Append to the list of messages defined, towards the end
 *       - Retain macro naming as glfs_msg_X (for redability across developers)
 * NOTE: Rules for message format modifications
 * 3) Check acorss the code if the message ID macro in question is reused
 *    anywhere. If reused then then the modifications should ensure correctness
 *    everywhere, or needs a new message ID as (1) above was not adhered to. If
 *    not used anywhere, proceed with the required modification.
 * NOTE: Rules for message deletion
 * 4) Check (3) and if used anywhere else, then cannot be deleted. If not used
 *    anywhere, then can be deleted, but will leave a hole by design, as
 *    addition rules specify modification to the end of the list and not filling
 *    holes.
 */

#define GLFS_TRANSPORT_BASE        GLFS_MSGID_COMP_RPC_TRANSPORT
#define GLFS_NUM_MESSAGES          92
#define GLFS_TRANSPORT_MSGID_END   (GLFS_TRANSPORT_BASE + GLFS_NUM_MESSAGES + 1)
/* Messages with message IDs */
#define glfs_msg_start_x GLFS_TRANSPORT_BASE, "Invalid: Start of messages"
/*------------*/
/* First slot is allocated for RDMA */

#define RDMA_MSG_REGISTER_MEM_FAILED                (GLFS_TRANSPORT_BASE + 1)

#define RDMA_MSG_POST_CREATION_FAILED               (GLFS_TRANSPORT_BASE + 2)

#define RDMA_MSG_DEREGISTER_ARENA_FAILED            (GLFS_TRANSPORT_BASE + 3)

#define RDMA_MSG_MR_ALOC_FAILED                     (GLFS_TRANSPORT_BASE + 4)

#define RDMA_MSG_PREREG_BUFFER_FAILED               (GLFS_TRANSPORT_BASE + 5)

#define RDMA_MSG_CQ_CREATION_FAILED                 (GLFS_TRANSPORT_BASE + 6)

#define RDMA_MSG_REQ_NOTIFY_CQ_REVQ_FAILED          (GLFS_TRANSPORT_BASE + 7)

#define RDMA_MSG_QUERY_DEVICE_FAILED                (GLFS_TRANSPORT_BASE + 8)

#define RDMA_MSG_SEND_CQ_FAILED                     (GLFS_TRANSPORT_BASE + 9)

#define RDMA_MSG_REQ_NOTIFY_CQ_SENDQ_FAILED         (GLFS_TRANSPORT_BASE + 10)

#define RDMA_MSG_SEND_COMP_CHAN_FAILED              (GLFS_TRANSPORT_BASE + 11)

#define RDMA_MSG_RECV_COMP_CHAN_FAILED              (GLFS_TRANSPORT_BASE + 12)

#define RDMA_MSG_ALOC_PROT_DOM_FAILED               (GLFS_TRANSPORT_BASE + 13)

#define RDMA_MSG_CRE_SRQ_FAILED                     (GLFS_TRANSPORT_BASE + 14)

#define RDMA_MSG_ALOC_POST_FAILED                   (GLFS_TRANSPORT_BASE + 15)

#define RDMA_MSG_SEND_COMP_THREAD_FAILED            (GLFS_TRANSPORT_BASE + 16)

#define RDMA_MSG_RECV_COMP_THREAD_FAILED            (GLFS_TRANSPORT_BASE + 17)

#define RDMA_MSG_ASYNC_EVENT_THEAD_FAILED           (GLFS_TRANSPORT_BASE + 18)

#define RDMA_MSG_GET_DEVICE_NAME_FAILED             (GLFS_TRANSPORT_BASE + 19)

#define RDMA_MSG_GET_IB_DEVICE_FAILED               (GLFS_TRANSPORT_BASE + 20)

#define RDMA_MSG_CREAT_INC_TRANS_FAILED             (GLFS_TRANSPORT_BASE + 21)

#define RDMA_MSG_CREAT_QP_FAILED                    (GLFS_TRANSPORT_BASE + 22)

#define RDMA_MSG_ACCEPT_FAILED                      (GLFS_TRANSPORT_BASE + 23)

#define RDMA_MSG_CONNECT_FAILED                     (GLFS_TRANSPORT_BASE + 24)

#define RDMA_MSG_ROUTE_RESOLVE_FAILED               (GLFS_TRANSPORT_BASE + 25)

#define RDMA_MSG_GET_DEVICE_FAILED                  (GLFS_TRANSPORT_BASE + 26)

#define RDMA_MSG_PEER_DISCONNECTED                  (GLFS_TRANSPORT_BASE + 27)

#define RDMA_MSG_GET_CM_EVENT_FAILED                (GLFS_TRANSPORT_BASE + 28)

#define RDMA_MSG_CM_EVENT_REJECTED                  (GLFS_TRANSPORT_BASE + 29)

#define RDMA_MSG_ENCODE_ERROR                       (GLFS_TRANSPORT_BASE + 30)

#define RDMA_MSG_CM_EVENT_DEVICE_REMOVED            (GLFS_TRANSPORT_BASE + 31)

#define RDMA_MSG_CM_UNHANDLED_EVENT                 (GLFS_TRANSPORT_BASE + 32)

#define RDMA_MSG_POST_SEND_FAILED                   (GLFS_TRANSPORT_BASE + 33)

#define RDMA_MSG_READ_CHUNK_VECTOR_FAILED           (GLFS_TRANSPORT_BASE + 34)

#define RDMA_MSG_WRITE_CHUNK_VECTOR_FAILED          (GLFS_TRANSPORT_BASE + 35)

#define RDMA_MSG_WRITE_REPLY_CHUNCK_CONFLICT        (GLFS_TRANSPORT_BASE + 36)

#define RDMA_MSG_CHUNK_COUNT_GREAT_MAX_SEGMENTS     (GLFS_TRANSPORT_BASE + 37)

#define RDMA_MSG_CREATE_READ_CHUNK_FAILED           (GLFS_TRANSPORT_BASE + 38)

#define RDMA_MSG_CREATE_WRITE_REPLAY_FAILED         (GLFS_TRANSPORT_BASE + 39)

#define RDMA_MSG_SEND_SIZE_GREAT_INLINE_THRESHOLD   (GLFS_TRANSPORT_BASE + 40)

#define RDMA_MSG_REG_ACCESS_LOCAL_WRITE_FAILED      (GLFS_TRANSPORT_BASE + 41)

#define RDMA_MSG_WRITE_PEER_FAILED                  (GLFS_TRANSPORT_BASE + 42)

#define RDMA_MSG_SEND_REPLY_FAILED                  (GLFS_TRANSPORT_BASE + 43)

#define RDMA_MSG_INVALID_CHUNK_TYPE                 (GLFS_TRANSPORT_BASE + 44)

#define RDMA_MSG_PROC_IOQ_ENTRY_FAILED              (GLFS_TRANSPORT_BASE + 45)

#define RDMA_MSG_NEW_IOQ_ENTRY_FAILED               (GLFS_TRANSPORT_BASE + 46)

#define RDMA_MSG_RPC_REPLY_CREATE_FAILED            (GLFS_TRANSPORT_BASE + 47)

#define RDMA_MSG_GET_READ_CHUNK_FAILED              (GLFS_TRANSPORT_BASE + 48)

#define RDMA_MSG_GET_WRITE_CHUNK_FAILED             (GLFS_TRANSPORT_BASE + 49)

#define RDMA_MSG_REPLY_INFO_ALLOC_FAILED            (GLFS_TRANSPORT_BASE + 50)

#define RDMA_MSG_RDMA_ERROR_RECEIVED                (GLFS_TRANSPORT_BASE + 51)

#define RDMA_MSG_GET_REQ_INFO_RPC_FAILED            (GLFS_TRANSPORT_BASE + 52)

#define RDMA_MSG_POLL_IN_NOTIFY_FAILED              (GLFS_TRANSPORT_BASE + 53)

#define RDMA_MSG_HEADER_DECODE_FAILED               (GLFS_TRANSPORT_BASE + 54)

#define RDMA_MSG_EVENT_SRQ_LIMIT_REACHED            (GLFS_TRANSPORT_BASE + 55)

#define RDMA_MSG_UNRECG_MQ_VALUE                    (GLFS_TRANSPORT_BASE + 56)

#define RDMA_MSG_BUFFER_ERROR                       (GLFS_TRANSPORT_BASE + 57)

#define RDMA_MSG_CREATE_CM_ID_FAILED                (GLFS_TRANSPORT_BASE + 58)

#define RDMA_MSG_GET_NAME_INFO_FAILED               (GLFS_TRANSPORT_BASE + 59)

#define RDMA_MSG_OPTION_SET_FAILED                  (GLFS_TRANSPORT_BASE + 60)

#define RDMA_MSG_LISTEN_FAILED                      (GLFS_TRANSPORT_BASE + 61)

#define RDMA_MSG_INIT_IB_DEVICE_FAILED              (GLFS_TRANSPORT_BASE + 62)

#define RDMA_MSG_WRITE_CLIENT_ERROR                 (GLFS_TRANSPORT_BASE + 63)

#define RDMA_MSG_CHUNKLIST_ERROR                    (GLFS_TRANSPORT_BASE + 64)

#define RDMA_MSG_INVALID_ENTRY                      (GLFS_TRANSPORT_BASE + 65)

#define RDMA_MSG_TRANSPORT_ERROR                    (GLFS_TRANSPORT_BASE + 66)

#define RDMA_MSG_READ_CLIENT_ERROR                  (GLFS_TRANSPORT_BASE + 67)

#define RDMA_MSG_RPC_ST_ERROR                       (GLFS_TRANSPORT_BASE + 68)

#define RDMA_MSG_PEER_READ_FAILED                   (GLFS_TRANSPORT_BASE + 69)

#define RDMA_MSG_POST_MISSING                       (GLFS_TRANSPORT_BASE + 70)

#define RDMA_MSG_PEER_REQ_FAILED                    (GLFS_TRANSPORT_BASE + 71)

#define RDMA_MSG_PEER_REP_FAILED                    (GLFS_TRANSPORT_BASE + 72)

#define RDMA_MSG_EVENT_ERROR                        (GLFS_TRANSPORT_BASE + 73)

#define RDMA_MSG_IBV_GET_CQ_FAILED                  (GLFS_TRANSPORT_BASE + 74)

#define RDMA_MSG_IBV_REQ_NOTIFY_CQ_FAILED           (GLFS_TRANSPORT_BASE + 75)

#define RDMA_MSG_RECV_ERROR                         (GLFS_TRANSPORT_BASE + 76)

#define RDMA_MSG_IBV_POLL_CQ_ERROR                  (GLFS_TRANSPORT_BASE + 77)

#define RDMA_MSG_RDMA_HANDLE_FAILED                 (GLFS_TRANSPORT_BASE + 78)

#define RDMA_MSG_CM_EVENT_FAILED                    (GLFS_TRANSPORT_BASE + 79)

#define RDMA_MSG_CLIENT_BIND_FAILED                 (GLFS_TRANSPORT_BASE + 80)

#define RDMA_MSG_RDMA_RESOLVE_ADDR_FAILED           (GLFS_TRANSPORT_BASE + 81)

#define RDMA_MSG_NW_ADDR_UNKNOWN                    (GLFS_TRANSPORT_BASE + 82)

#define RDMA_MSG_RDMA_BIND_ADDR_FAILED              (GLFS_TRANSPORT_BASE + 83)

#define RDMA_MSG_SEND_CLIENT_ERROR                  (GLFS_TRANSPORT_BASE + 84)

#define RDMA_MSG_ADDR_FAMILY_NOT_SPECIFIED          (GLFS_TRANSPORT_BASE + 85)

#define RDMA_MSG_UNKNOWN_ADDR_FAMILY                (GLFS_TRANSPORT_BASE + 86)

#define RDMA_MSG_REMOTE_HOST_ERROR                  (GLFS_TRANSPORT_BASE + 86)

#define RDMA_MSG_DNS_RESOL_FAILED                   (GLFS_TRANSPORT_BASE + 87)

#define RDMA_MSG_LISTEN_PATH_ERROR                  (GLFS_TRANSPORT_BASE + 88)

#define RDMA_MSG_CONNECT_PATH_ERROR                 (GLFS_TRANSPORT_BASE + 89)

#define RDMA_MSG_GET_ADDR_INFO_FAILED               (GLFS_TRANSPORT_BASE + 90)

#define RDMA_MSG_PORT_BIND_FAILED                   (GLFS_TRANSPORT_BASE + 91)

#define RDMA_MSG_INET_ERROR                         (GLFS_TRANSPORT_BASE + 92)
/*------------*/

#define TRANSPORT_MSG_END_X GLFS_MSGID_END, "Invalid: End of messages"

#endif /* !_TRANSPORT_MESSAGES_H_ */

