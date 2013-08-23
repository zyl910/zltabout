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
 * @file	zltabout_cpp.hpp
 * @brief	zltabout: C++ mode (C++模式的zltabout) .
 * @since	@ref GROUP_ZLTABOUT 1.0
 */


#ifndef __ZLTABOUT_CPP_HPP_INCLUDED
#define __ZLTABOUT_CPP_HPP_INCLUDED

#include <ostream>

#include <stdarg.h>


#if defined __cplusplus
extern "C" {
#endif

#define ZLTOUTTYPEA	std::basic_ostream<char>*
#define ZLTOUTTYPEW	std::basic_ostream<wchar_t>*

#define zltoutcA(sout, ch)	zltabout_cpp_outcA(sout, ch)
#define zltoutcW(sout, ch)	zltabout_cpp_outcW(sout, ch)
#define zltoutsA(sout, str, cch)	zltabout_cpp_outsA(sout, str, cch)
#define zltoutsW(sout, str, cch)	zltabout_cpp_outsW(sout, str, cch)
#define zltoutvfA(sout, indent, fmt, argptr)	zltabout_cpp_outvfA(sout, indent, fmt, argptr)
#define zltoutvfW(sout, indent, fmt, argptr)	zltabout_cpp_outvfW(sout, indent, fmt, argptr)
#define zltoutfA	zltabout_cpp_outfA
#define zltoutfW	zltabout_cpp_outfW

/** Writes a narrow character to a stream (向流输出一个窄字符).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	ch	Character (字符).
 * @return	Each of these functions returns the character written. A return value of EOF indicates an error.
 *
 */
extern int zltabout_cpp_outcA(ZLTOUTTYPEA sout, char ch);

#ifndef ZL_NOWIDE
/** Writes a wide character to a stream (向流输出一个宽字符).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	ch	Character (字符).
 * @return	Each of these functions returns the character written. A return value of WEOF indicates an error.
 *
 */
extern wint_t zltabout_cpp_outcW(ZLTOUTTYPEW sout, wchar_t ch);
#endif

/** Write a narrow string to a stream (向流输出窄字符串).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	str	Output string (输出字符串).
 * @param[in]	cch	Count of characters (字符数).
 *
 */
extern void zltabout_cpp_outsA(ZLTOUTTYPEA sout, const char* str, size_t cch);

#ifndef ZL_NOWIDE
/** Write a wide string to a stream (向流输出宽字符串).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	str	Output string (输出字符串).
 * @param[in]	cch	Count of characters (字符数).
 *
 */
extern void zltabout_cpp_outsW(ZLTOUTTYPEW sout, const wchar_t* str, size_t cch);
#endif

/** Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出窄字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 */
extern void zltabout_cpp_outvfA(ZLTOUTTYPEA sout, int indent, const char* fmt, va_list argptr);

#ifndef ZL_NOWIDE
/** Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出宽字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 */
extern void zltabout_cpp_outvfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, va_list argptr);
#endif

/** Formatted output with indentation (带缩进格式化输出窄字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 */
extern void zltabout_cpp_outfA(ZLTOUTTYPEA sout, int indent, const char* fmt, ...);

#ifndef ZL_NOWIDE
/** Formatted output with indentation (带缩进格式化输出宽字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 */
extern void zltabout_cpp_outfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, ...);
#endif



#if defined __cplusplus
};
#endif

#endif // #ifndef __ZLTABOUT_CPP_HPP_INCLUDED

/** @} */	// @addtogroup GROUP_ZLTABOUT
/** @} */	// @addtogroup GROUP_ZYLLIBC
