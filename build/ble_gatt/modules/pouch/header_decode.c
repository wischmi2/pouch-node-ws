/*
 * Generated using zcbor version 0.9.1
 * https://github.com/NordicSemiconductor/zcbor
 * Generated with a --default-max-qty of 3
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "zcbor_decode.h"
#include "cddl\header_decode.h"
#include "zcbor_print.h"

#if DEFAULT_MAX_QTY != 3
#error "The type file was generated with a different default_max_qty than this file"
#endif

#define log_result(state, result, func) do { \
	if (!result) { \
		zcbor_trace_file(state); \
		zcbor_log("%s error: %s\r\n", func, zcbor_error_str(zcbor_peek_error(state))); \
	} else { \
		zcbor_log("%s success\r\n", func); \
	} \
} while(0)

static bool decode_plaintext_info(zcbor_state_t *state, struct plaintext_info *result);
static bool decode_session_id_random(zcbor_state_t *state, struct zcbor_string *result);
static bool decode_session_id_sequential(zcbor_state_t *state, struct session_id_sequential *result);
static bool decode_session_info(zcbor_state_t *state, struct session_info *result);
static bool decode_saead_info(zcbor_state_t *state, struct saead_info *result);
static bool decode_encryption_info(zcbor_state_t *state, struct encryption_info *result);
static bool decode_pouch_header(zcbor_state_t *state, struct pouch_header *result);


static bool decode_plaintext_info(
		zcbor_state_t *state, struct plaintext_info *result)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((((zcbor_uint32_expect(state, (0))))
	&& ((zcbor_tstr_decode(state, (&(*result).id)))))));

	log_result(state, res, __func__);
	return res;
}

static bool decode_session_id_random(
		zcbor_state_t *state, struct zcbor_string *result)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((zcbor_list_start_decode(state) && ((((zcbor_bstr_decode(state, (&(*result))))
	&& ((((*result).len == 16)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false)))) || (zcbor_list_map_end_force_decode(state), false)) && zcbor_list_end_decode(state))));

	log_result(state, res, __func__);
	return res;
}

static bool decode_session_id_sequential(
		zcbor_state_t *state, struct session_id_sequential *result)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((zcbor_list_start_decode(state) && ((((zcbor_bstr_decode(state, (&(*result).tag)))
	&& ((((*result).tag.len == 8)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false)))
	&& ((zcbor_uint64_decode(state, (&(*result).seq))))) || (zcbor_list_map_end_force_decode(state), false)) && zcbor_list_end_decode(state))));

	log_result(state, res, __func__);
	return res;
}

static bool decode_session_info(
		zcbor_state_t *state, struct session_info *result)
{
	zcbor_log("%s\r\n", __func__);
	bool int_res;

	bool res = (((zcbor_list_start_decode(state) && ((((zcbor_union_start_code(state) && (int_res = ((((decode_session_id_random(state, (&(*result).session_id_random_m)))) && (((*result).id_choice = session_info_id_session_id_random_m_c), true))
	|| (zcbor_union_elem_code(state) && (((decode_session_id_sequential(state, (&(*result).session_id_sequential_m)))) && (((*result).id_choice = session_info_id_session_id_sequential_m_c), true)))), zcbor_union_end_code(state), int_res)))
	&& ((((zcbor_uint_decode(state, &(*result).initiator_choice, sizeof((*result).initiator_choice)))) && ((((((*result).initiator_choice == session_info_initiator_device_m_c) && ((1)))
	|| (((*result).initiator_choice == session_info_initiator_server_m_c) && ((1)))) || (zcbor_error(state, ZCBOR_ERR_WRONG_VALUE), false)))))
	&& ((((zcbor_uint_decode(state, &(*result).algorithm_choice, sizeof((*result).algorithm_choice)))) && ((((((*result).algorithm_choice == session_info_algorithm_aes_gcm_m_c) && ((1)))
	|| (((*result).algorithm_choice == session_info_algorithm_chacha20_poly1305_m_c) && ((1)))) || (zcbor_error(state, ZCBOR_ERR_WRONG_VALUE), false)))))
	&& ((zcbor_uint32_decode(state, (&(*result).max_block_size_log)))
	&& ((((*result).max_block_size_log <= UINT8_MAX)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false)))
	&& ((zcbor_bstr_decode(state, (&(*result).cert_ref)))
	&& ((((*result).cert_ref.len == 6)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false)))) || (zcbor_list_map_end_force_decode(state), false)) && zcbor_list_end_decode(state))));

	log_result(state, res, __func__);
	return res;
}

static bool decode_saead_info(
		zcbor_state_t *state, struct saead_info *result)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((((zcbor_uint32_expect(state, (1))))
	&& ((decode_session_info(state, (&(*result).session))))
	&& ((zcbor_uint32_decode(state, (&(*result).pouch_id)))
	&& ((((*result).pouch_id <= UINT16_MAX)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false))))));

	log_result(state, res, __func__);
	return res;
}

static bool decode_encryption_info(
		zcbor_state_t *state, struct encryption_info *result)
{
	zcbor_log("%s\r\n", __func__);
	bool int_res;

	bool res = (((zcbor_list_start_decode(state) && ((((zcbor_union_start_code(state) && (int_res = ((((decode_plaintext_info(state, (&(*result).plaintext_info_m)))) && (((*result).Union_choice = encryption_info_union_plaintext_info_m_c), true))
	|| (zcbor_union_elem_code(state) && (((decode_saead_info(state, (&(*result).saead_info_m)))) && (((*result).Union_choice = encryption_info_union_saead_info_m_c), true)))), zcbor_union_end_code(state), int_res)))) || (zcbor_list_map_end_force_decode(state), false)) && zcbor_list_end_decode(state))));

	log_result(state, res, __func__);
	return res;
}

static bool decode_pouch_header(
		zcbor_state_t *state, struct pouch_header *result)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((zcbor_list_start_decode(state) && ((((zcbor_uint32_decode(state, (&(*result).version)))
	&& ((((*result).version <= UINT8_MAX)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false)))
	&& ((decode_encryption_info(state, (&(*result).encryption_info_m))))) || (zcbor_list_map_end_force_decode(state), false)) && zcbor_list_end_decode(state))));

	log_result(state, res, __func__);
	return res;
}



int cbor_decode_pouch_header(
		const uint8_t *payload, size_t payload_len,
		struct pouch_header *result,
		size_t *payload_len_out)
{
	zcbor_state_t states[8];

	return zcbor_entry_function(payload, payload_len, (void *)result, payload_len_out, states,
		(zcbor_decoder_t *)decode_pouch_header, sizeof(states) / sizeof(zcbor_state_t), 1);
}
