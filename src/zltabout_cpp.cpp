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
 * @file	zltabout_cpp.cpp
 * @brief	[source file] zltabout: C++ mode (C++模式的zltabout) .
 * @since	@ref GROUP_ZLTABOUT 1.0
 *
 * ## Input macros (输入配置性宏)
 *
 * Macros:
 * * @ref ZLTABOUT_CPP_CRT_SECURE: Security Enhancements in the CRT.
 *
 */

#include <memory.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>

#include "zltabout_cpp.hpp"

#define ZLTABOUT_CPP_BUFSIZE	4096	//!< buffer size.

/** @def ZLTABOUT_CPP_CRT_SECURE
 * [#if] Security Enhancements in the CRT.
 */
#ifndef ZLTABOUT_CPP_CRT_SECURE
	#if defined(_MSC_VER) && (_MSC_VER>=1400)	// VC2005
		#define ZLTABOUT_CPP_CRT_SECURE	1
	#else
		#define ZLTABOUT_CPP_CRT_SECURE	0
	#endif	// #if defined(_MSC_VER) && (_MSC_VER>=1400)	// VC2005
#endif	// #ifndef ZLTABOUT_CPP_CRT_SECURE


int zltabout_cpp_outcA(ZLTOUTTYPEA sout, char ch) {
	int rt = EOF;
	if (NULL!=sout) {
		sout->put(ch);
		if ( !(sout->eof()) ) rt=(int)1;
	}
	return rt;
}

wint_t zltabout_cpp_outcW(ZLTOUTTYPEW sout, wchar_t ch) {
	wint_t rt = WEOF;
	if (NULL!=sout) {
		sout->put(ch);
		if ( !(sout->eof()) ) rt=(wint_t)1;
	}
	return rt;
}

void zltabout_cpp_outsA(ZLTOUTTYPEA sout, const char* str, size_t cch) {
	if (NULL==sout) return;
	if (NULL==str) return;
	sout->write(str, (std::streamsize)cch);
}

void zltabout_cpp_outsW(ZLTOUTTYPEW sout, const wchar_t* str, size_t cch) {
	if (NULL==sout) return;
	if (NULL==str) return;
	sout->write(str, (std::streamsize)cch);
}

/// [Core] Formatted output narrow string (格式化窄字符串并输出).
static void zltabout_cpp_outvfA_coreformat(ZLTOUTTYPEA sout, const char* fmt, va_list argptr) {
	char buf[ZLTABOUT_CPP_BUFSIZE];
	memset(buf, 0, ZLTABOUT_CPP_BUFSIZE);
#if ZLTABOUT_CPP_CRT_SECURE
	vsprintf_s(buf, ZLTABOUT_CPP_BUFSIZE-1, fmt, argptr);
#else
	vsnprintf(buf, ZLTABOUT_CPP_BUFSIZE-1, fmt, argptr);
#endif
	sout->write(buf, (std::streamsize)strlen(buf));
}

void zltabout_cpp_outvfA(ZLTOUTTYPEA sout, int indent, const char* fmt, va_list argptr) {
	int i;
	if (NULL==sout) return;
	if ( sout->eof() ) return;
	sout->setstate(sout->rdstate() & ~std::ios::failbit);	// clear failbit.
	for(i=0; i<indent; ++i) {
		sout->put('\t');
	}
	if ( sout->eof() ) return;
	if (NULL!=fmt) {
		// check Percent sign(%) .
		int hasPercentSign = 0;
		std::streamsize cch = 0;
		const char* p = fmt;
		while(*p!='\0') {
			if (*p=='%') {
				hasPercentSign = 1;
				break;
			}
			++cch;
			++p;
		}
		// output.
		if (hasPercentSign) {
			zltabout_cpp_outvfA_coreformat(sout, fmt, argptr);
		}
		else {
			sout->write(fmt, cch);
		}
	}
	sout->setstate(sout->rdstate() & ~std::ios::failbit);	// clear failbit.
}

/// [Core] Formatted output wide string (格式化宽字符串并输出).
static void zltabout_cpp_outvfW_coreformat(ZLTOUTTYPEW sout, const wchar_t* fmt, va_list argptr) {
	wchar_t buf[ZLTABOUT_CPP_BUFSIZE];
	wmemset(buf, 0, ZLTABOUT_CPP_BUFSIZE);
#if ZLTABOUT_CPP_CRT_SECURE
	vswprintf_s(buf, ZLTABOUT_CPP_BUFSIZE-1, fmt, argptr);
#else
	vswprintf(buf, ZLTABOUT_CPP_BUFSIZE-1, fmt, argptr);
#endif
	sout->write(buf, (std::streamsize)wcslen(buf));
}

void zltabout_cpp_outvfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, va_list argptr) {
	int i;
	if (NULL==sout) return;
	if ( sout->eof() ) return;
	sout->setstate(sout->rdstate() & ~std::ios::failbit);	// clear failbit.
	for(i=0; i<indent; ++i) {
		sout->put(L'\t');
	}
	if ( sout->eof() ) return;
	if (NULL!=fmt) {
		// check Percent sign(%) .
		int hasPercentSign = 0;
		std::streamsize cch = 0;
		const wchar_t* p = fmt;
		while(*p!=L'\0') {
			if (*p==L'%') {
				hasPercentSign = 1;
				break;
			}
			++cch;
			++p;
		}
		// output.
		if (hasPercentSign) {
			zltabout_cpp_outvfW_coreformat(sout, fmt, argptr);
		}
		else {
			sout->write(fmt, cch);
		}
	}
	sout->setstate(sout->rdstate() & ~std::ios::failbit);	// clear failbit.
}

void zltabout_cpp_outfA(ZLTOUTTYPEA sout, int indent, const char* fmt, ...) {
	va_list argptr;
	if (NULL==sout) return;
	va_start(argptr, fmt);
	zltabout_cpp_outvfA(sout, indent, fmt, argptr);
	va_end(argptr);
}

void zltabout_cpp_outfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, ...) {
	va_list argptr;
	if (NULL==sout) return;
	va_start(argptr, fmt);
	zltabout_cpp_outvfW(sout, indent, fmt, argptr);
	va_end(argptr);
}

/** @} */	// @addtogroup GROUP_ZLTABOUT
/** @} */	// @addtogroup GROUP_ZYLLIBC
