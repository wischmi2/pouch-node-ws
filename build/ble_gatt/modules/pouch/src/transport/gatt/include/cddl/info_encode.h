/*
 * Generated using zcbor version 0.9.1
 * https://github.com/NordicSemiconductor/zcbor
 * Generated with a --default-max-qty of 3
 */

#ifndef INFO_ENCODE_H__
#define INFO_ENCODE_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "cddl\info_encode_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#if DEFAULT_MAX_QTY != 3
#error "The type file was generated with a different default_max_qty than this file"
#endif


int cbor_encode_pouch_gatt_info(
		uint8_t *payload, size_t payload_len,
		const struct pouch_gatt_info *input,
		size_t *payload_len_out);


#ifdef __cplusplus
}
#endif

#endif /* INFO_ENCODE_H__ */
