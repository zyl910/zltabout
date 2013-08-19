//Copyright (c) 2000-2013 zyl910 <zyl910hero@gmail.com>
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

/** @addtogroup GROUP_ZYLLIBC	zyllibc
 * @{
 */

/** @addtogroup GROUP_ZLTABOUT	zltabout
 * @{
 */

/**
 * @file	zltabout_c.c
 * @brief	[source file] zltabout: C mode (C模式的zltabout) .
 * @since	@ref GROUP_ZLTABOUT 1.0
 */

#include <stddef.h>

#include "zltabout_c.h"

void zltabout_c_outvfA(ZLTOUTTYPEA sout, int indent, const char* fmt, va_list argptr) {
	int i;
	for(i=0; i<indent; ++i) {
		fputc('\t', sout);
	}
	if (NULL!=fmt) {
		vfprintf(sout, fmt, argptr);
	}
}

void zltabout_c_outvfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, va_list argptr) {
	int i;
	for(i=0; i<indent; ++i) {
		fputwc(L'\t', sout);
	}
	if (NULL!=fmt) {
		vfwprintf(sout, fmt, argptr);
	}
}

void zltabout_c_outfA(ZLTOUTTYPEA sout, int indent, const char* fmt, ...) {
	va_list argptr;
	va_start(argptr, fmt);
	zltabout_c_outvfA(sout, indent, fmt, argptr);
	va_end(argptr);
}

void zltabout_c_outfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, ...) {
	va_list argptr;
	va_start(argptr, fmt);
	zltabout_c_outvfW(sout, indent, fmt, argptr);
	va_end(argptr);
}

/** @} */	// @addtogroup GROUP_ZLTABOUT
/** @} */	// @addtogroup GROUP_ZYLLIBC