/*
 * Generated using zcbor version 0.9.1
 * https://github.com/NordicSemiconductor/zcbor
 * Generated with a --default-max-qty of 3
 */

#ifndef HEADER_DECODE_H__
#define HEADER_DECODE_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "cddl\header_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#if DEFAULT_MAX_QTY != 3
#error "The type file was generated with a different default_max_qty than this file"
#endif


int cbor_decode_pouch_header(
		const uint8_t *payload, size_t payload_len,
		struct pouch_header *result,
		size_t *payload_len_out);


#ifdef __cplusplus
}
#endif

#endif /* HEADER_DECODE_H__ */
