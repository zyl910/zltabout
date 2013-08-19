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
 * @file	zltabout_c.h
 * @brief	zltabout: C mode (C模式的zltabout) .
 * @since	@ref GROUP_ZLTABOUT 1.0
 */

#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

#if defined __cplusplus
extern "C" {
#endif

#define ZLTOUTTYPEA	FILE*
#define ZLTOUTTYPEW	FILE*

#define ZLTOUTCA(sout, ch)	fputc(ch, sout)
#define ZLTOUTCW(sout, ch)	fputwc(ch, sout)
#define ZLTOUTVFA(sout, indent, fmt, argptr)	zltabout_c_outvfA(sout, indent, fmt, argptr)
#define ZLTOUTVFW(sout, indent, fmt, argptr)	zltabout_c_outvfW(sout, indent, fmt, argptr)
#define ZLTOUTFA	zltabout_c_outfA
#define ZLTOUTFW	zltabout_c_outfW


/** Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出窄字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 */
extern void zltabout_c_outvfA(ZLTOUTTYPEA sout, int indent, const char* fmt, va_list argptr);

/** Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出宽字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 */
extern void zltabout_c_outvfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, va_list argptr);

/** Formatted output with indentation (带缩进格式化输出窄字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 */
extern void zltabout_c_outfA(ZLTOUTTYPEA sout, int indent, const char* fmt, ...);

/** Formatted output with indentation (带缩进格式化输出宽字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 */
extern void zltabout_c_outfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, ...);



#if defined __cplusplus
};
#endif

/** @} */	// @addtogroup GROUP_ZLTABOUT
/** @} */	// @addtogroup GROUP_ZYLLIBC
