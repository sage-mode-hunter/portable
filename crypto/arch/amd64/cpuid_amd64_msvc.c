/*
 * Copyright (c) 2026 Kartik Naik <kartik@bugqore.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stddef.h>
#include <stdint.h>

#include <intrin.h>

#include "crypto_arch.h"

void
crypto_cpuid(uint32_t eax, uint32_t *out_eax, uint32_t *out_ebx,
    uint32_t *out_ecx, uint32_t *out_edx)
{
	int regs[4];

	__cpuidex(regs, (int)eax, 0);

	if (out_eax != NULL)
		*out_eax = (uint32_t)regs[0];
	if (out_ebx != NULL)
		*out_ebx = (uint32_t)regs[1];
	if (out_ecx != NULL)
		*out_ecx = (uint32_t)regs[2];
	if (out_edx != NULL)
		*out_edx = (uint32_t)regs[3];
}

void
crypto_xgetbv(uint32_t ecx, uint32_t *out_eax, uint32_t *out_edx)
{
	uint64_t xcr;

	xcr = _xgetbv(ecx);

	if (out_eax != NULL)
		*out_eax = (uint32_t)xcr;
	if (out_edx != NULL)
		*out_edx = (uint32_t)(xcr >> 32);
}
