/*
 * Generated using zcbor version 0.9.1
 * https://github.com/NordicSemiconductor/zcbor
 * Generated with a --default-max-qty of 3
 */

#ifndef HEADER_TYPES_H__
#define HEADER_TYPES_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <zcbor_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Which value for --default-max-qty this file was created with.
 *
 *  The define is used in the other generated file to do a build-time
 *  compatibility check.
 *
 *  See `zcbor --help` for more information about --default-max-qty
 */
#define DEFAULT_MAX_QTY 3

struct plaintext_info {
	struct zcbor_string id;
};

struct session_id_sequential {
	struct zcbor_string tag;
	uint64_t seq;
};

struct session_info {
	union {
		struct zcbor_string session_id_random_m;
		struct session_id_sequential session_id_sequential_m;
	};
	enum {
		session_info_id_session_id_random_m_c,
		session_info_id_session_id_sequential_m_c,
	} id_choice;
	enum {
		session_info_initiator_device_m_c = 0,
		session_info_initiator_server_m_c = 1,
	} initiator_choice;
	enum {
		session_info_algorithm_aes_gcm_m_c = 2,
		session_info_algorithm_chacha20_poly1305_m_c = 1,
	} algorithm_choice;
	uint32_t max_block_size_log;
	struct zcbor_string cert_ref;
};

struct saead_info {
	struct session_info session;
	uint32_t pouch_id;
};

struct encryption_info {
	union {
		struct plaintext_info plaintext_info_m;
		struct saead_info saead_info_m;
	};
	enum {
		encryption_info_union_plaintext_info_m_c,
		encryption_info_union_saead_info_m_c,
	} Union_choice;
};

struct pouch_header {
	uint32_t version;
	struct encryption_info encryption_info_m;
};

#ifdef __cplusplus
}
#endif

#endif /* HEADER_TYPES_H__ */
