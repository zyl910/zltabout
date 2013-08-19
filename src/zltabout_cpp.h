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
 * @file	zltabout_cpp.h
 * @brief	zltabout: C++ mode (C++模式的zltabout) .
 * @since	@ref GROUP_ZLTABOUT 1.0
 */

#include <ostream>


#if defined __cplusplus
extern "C" {
#endif

#define ZLTOUTTYPEA	std::basic_ostream<char>*
#define ZLTOUTTYPEW	std::basic_ostream<wchar_t>*

#define ZLTOUTCA(sout, ch)	zltabout_cpp_outcA(sout, ch)
#define ZLTOUTCW(sout, ch)	zltabout_cpp_outcW(sout, ch)
#define ZLTOUTVFA(sout, indent, fmt, argptr)	zltabout_cpp_outvfA(sout, indent, fmt, argptr)
#define ZLTOUTVFW(sout, indent, fmt, argptr)	zltabout_cpp_outvfW(sout, indent, fmt, argptr)
#define ZLTOUTFA	zltabout_cpp_outfA
#define ZLTOUTFW	zltabout_cpp_outfW

extern int zltabout_cpp_outcA(ZLTOUTTYPEA sout, char ch);
extern wint_t zltabout_cpp_outcW(ZLTOUTTYPEW sout, wchar_t ch);

/** Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出窄字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 */
extern void zltabout_cpp_outvfA(ZLTOUTTYPEA sout, int indent, const char* fmt, va_list argptr);

/** Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出宽字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 */
extern void zltabout_cpp_outvfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, va_list argptr);

/** Formatted output with indentation (带缩进格式化输出窄字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 */
extern void zltabout_cpp_outfA(ZLTOUTTYPEA sout, int indent, const char* fmt, ...);

/** Formatted output with indentation (带缩进格式化输出宽字符串版).
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 */
extern void zltabout_cpp_outfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, ...);



#if defined __cplusplus
};
#endif

/** @} */	// @addtogroup GROUP_ZLTABOUT
/** @} */	// @addtogroup GROUP_ZYLLIBC
