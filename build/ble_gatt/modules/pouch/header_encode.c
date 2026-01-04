/*
 * Generated using zcbor version 0.9.1
 * https://github.com/NordicSemiconductor/zcbor
 * Generated with a --default-max-qty of 3
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "zcbor_encode.h"
#include "cddl\header_encode.h"
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

static bool encode_plaintext_info(zcbor_state_t *state, const struct plaintext_info *input);
static bool encode_session_id_random(zcbor_state_t *state, const struct zcbor_string *input);
static bool encode_session_id_sequential(zcbor_state_t *state, const struct session_id_sequential *input);
static bool encode_session_info(zcbor_state_t *state, const struct session_info *input);
static bool encode_saead_info(zcbor_state_t *state, const struct saead_info *input);
static bool encode_encryption_info(zcbor_state_t *state, const struct encryption_info *input);
static bool encode_pouch_header(zcbor_state_t *state, const struct pouch_header *input);


static bool encode_plaintext_info(
		zcbor_state_t *state, const struct plaintext_info *input)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((((zcbor_uint32_put(state, (0))))
	&& ((zcbor_tstr_encode(state, (&(*input).id)))))));

	log_result(state, res, __func__);
	return res;
}

static bool encode_session_id_random(
		zcbor_state_t *state, const struct zcbor_string *input)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((zcbor_list_start_encode(state, 1) && (((((((*input).len == 16)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false))
	&& (zcbor_bstr_encode(state, (&(*input)))))) || (zcbor_list_map_end_force_encode(state), false)) && zcbor_list_end_encode(state, 1))));

	log_result(state, res, __func__);
	return res;
}

static bool encode_session_id_sequential(
		zcbor_state_t *state, const struct session_id_sequential *input)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((zcbor_list_start_encode(state, 2) && (((((((*input).tag.len == 8)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false))
	&& (zcbor_bstr_encode(state, (&(*input).tag))))
	&& ((zcbor_uint64_encode(state, (&(*input).seq))))) || (zcbor_list_map_end_force_encode(state), false)) && zcbor_list_end_encode(state, 2))));

	log_result(state, res, __func__);
	return res;
}

static bool encode_session_info(
		zcbor_state_t *state, const struct session_info *input)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((zcbor_list_start_encode(state, 5) && ((((((*input).id_choice == session_info_id_session_id_random_m_c) ? ((encode_session_id_random(state, (&(*input).session_id_random_m))))
	: (((*input).id_choice == session_info_id_session_id_sequential_m_c) ? ((encode_session_id_sequential(state, (&(*input).session_id_sequential_m))))
	: false)))
	&& ((((*input).initiator_choice == session_info_initiator_device_m_c) ? ((zcbor_uint32_put(state, (0))))
	: (((*input).initiator_choice == session_info_initiator_server_m_c) ? ((zcbor_uint32_put(state, (1))))
	: false)))
	&& ((((*input).algorithm_choice == session_info_algorithm_aes_gcm_m_c) ? ((zcbor_uint32_put(state, (2))))
	: (((*input).algorithm_choice == session_info_algorithm_chacha20_poly1305_m_c) ? ((zcbor_uint32_put(state, (1))))
	: false)))
	&& (((((*input).max_block_size_log <= UINT8_MAX)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false))
	&& (zcbor_uint32_encode(state, (&(*input).max_block_size_log))))
	&& (((((*input).cert_ref.len == 6)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false))
	&& (zcbor_bstr_encode(state, (&(*input).cert_ref))))) || (zcbor_list_map_end_force_encode(state), false)) && zcbor_list_end_encode(state, 5))));

	log_result(state, res, __func__);
	return res;
}

static bool encode_saead_info(
		zcbor_state_t *state, const struct saead_info *input)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((((zcbor_uint32_put(state, (1))))
	&& ((encode_session_info(state, (&(*input).session))))
	&& (((((*input).pouch_id <= UINT16_MAX)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false))
	&& (zcbor_uint32_encode(state, (&(*input).pouch_id)))))));

	log_result(state, res, __func__);
	return res;
}

static bool encode_encryption_info(
		zcbor_state_t *state, const struct encryption_info *input)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((zcbor_list_start_encode(state, 3) && ((((((*input).Union_choice == encryption_info_union_plaintext_info_m_c) ? ((encode_plaintext_info(state, (&(*input).plaintext_info_m))))
	: (((*input).Union_choice == encryption_info_union_saead_info_m_c) ? ((encode_saead_info(state, (&(*input).saead_info_m))))
	: false)))) || (zcbor_list_map_end_force_encode(state), false)) && zcbor_list_end_encode(state, 3))));

	log_result(state, res, __func__);
	return res;
}

static bool encode_pouch_header(
		zcbor_state_t *state, const struct pouch_header *input)
{
	zcbor_log("%s\r\n", __func__);

	bool res = (((zcbor_list_start_encode(state, 2) && (((((((*input).version <= UINT8_MAX)) || (zcbor_error(state, ZCBOR_ERR_WRONG_RANGE), false))
	&& (zcbor_uint32_encode(state, (&(*input).version))))
	&& ((encode_encryption_info(state, (&(*input).encryption_info_m))))) || (zcbor_list_map_end_force_encode(state), false)) && zcbor_list_end_encode(state, 2))));

	log_result(state, res, __func__);
	return res;
}



int cbor_encode_pouch_header(
		uint8_t *payload, size_t payload_len,
		const struct pouch_header *input,
		size_t *payload_len_out)
{
	zcbor_state_t states[8];

	return zcbor_entry_function(payload, payload_len, (void *)input, payload_len_out, states,
		(zcbor_decoder_t *)encode_pouch_header, sizeof(states) / sizeof(zcbor_state_t), 1);
}
