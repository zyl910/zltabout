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
 * Formatted output with indentation (带缩进的格式化输出) .
 *
 * @author	[zyl910](mailto:zyl910hero@gmail.com)
 * @version	1.0
 * @date	2013-08-23
 *
 * Links:
 *
 * * Git:	https://github.com/zyl910/zltabout
 * * Blog:	http://www.cnblogs.com/zyl910/tag/zltabout/
 * 
 * zltabout is a lightweight C library.
 *
 * Features (特性):
 * * Formatting output with indentation (带缩进的格式化输出) .
 * 
 * ## Usage (用法)
 * 
 * Add `src/``*.*` to you project (将 `src/``*.*` 加入到您的项目).
 * 
 * Example code:
 * 
 * 
 * 
 *
 * ## Documentation (文档)
 * 
 * You can generate documentation with [doxygen](http://www.stack.nl/~dimitri/doxygen/index.html) (您可以用doxygen生成文档).
 * 
 * Use doxywizard to open *.doxygen file (使用doxywizard打开 *.doxygen).
 * 
 * * zltabout_doc.doxygen: Generates documentation from interface files (生成接口的文档) .
 * * zltabout_docfull.doxygen: Generates documentation from interface & implement and example files (生成接口、实现、示例等内容的详细文档).
 * 
 * You may need change INCLUDE_PATH in *.doxyfile with the actual location (您可能需要在 *.doxygen 中调整INCLUDE_PATH为实际路径).
 * 
 * 
 * ## MIT License (MIT许可证)
 * 
 * Copyright (c) 2000-2013 zyl910 \<zyl910hero@gmail.com\>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * ## Tested compiler (测试过的编译器)
 * 
 * * Virtual C++: 6, 7.1(2003), 8(2005), 9(2008), 10(2010), 11(2012).
 * * Borland C++ Builder: 6.
 * * GCC(Linux): 4.7.0(Fedora 17),  4.7.2(Fedora 18),  4.8.1(Fedora 19).
 * * GCC(MinGW): 4.6.2(MinGW(20120426)), 4.7.1(TDM-GCC(MinGW-w64)).
 * * LLVM GCC: 4.2(Mac OS X Lion 10.7.4), 4.2.1(Mac OS X Mountain Lion 10.8.3).
 * 
 * 
 * 
 * ## Change history (变更日志)
 * 
 * [2013-08-23] V1.0
 *
 * * Release v1.0 (发布1.0版).
 *
 * @{
 */

/**
 * @file	zltabout.h
 * @brief	Formatting output with indentation (带缩进的格式化输出) .
 * @since	@ref GROUP_ZLTABOUT 1.0
 */


#ifndef __ZLTABOUT_H_INCLUDED
#define __ZLTABOUT_H_INCLUDED

// ZLTABOUTMODE consts.
#define ZLTABOUTMODE_DUMMY	0	//!< No output (不输出) .
#define ZLTABOUTMODE_C	1	//!< C mode (C模式). FILE* .
#define ZLTABOUTMODE_CPP	2	//!< C++ mode (C++模式). stream . 

/** @def ZLTABOUTMODE
 * Output Mode (输出模式).
 *
 * Default value is @ref ZLTABOUTMODE_DUMMY (若该宏没有定义，则自动设为默认值 @ref ZLTABOUTMODE_DUMMY ).
 *
 * @see ZLTABOUTMODE_DUMMY, ZLTABOUTMODE_C, ZLTABOUTMODE_CPP
 */
#ifndef ZLTABOUTMODE
#define ZLTABOUTMODE	ZLTABOUTMODE_DUMMY
#endif


// == Mode mapping (模式映射) ==

#if ZLTABOUTMODE==ZLTABOUTMODE_DUMMY
	#define ZLTOUTTYPEA	void*
	#define ZLTOUTTYPEW	void*
	#define ZLTOUTCA(sout, ch)
	#define ZLTOUTCW(sout, ch)
	#define ZLTOUTSA(sout, str, cch)
	#define ZLTOUTSW(sout, str, cch)
	#define ZLTOUTVFA(sout, indent, fmt, argptr)
	#define ZLTOUTVFW(sout, indent, fmt, argptr)
	#define ZLTOUTFA(args)
	#define ZLTOUTFW(args)
#elif ZLTABOUTMODE==ZLTABOUTMODE_C
	#include "zltabout_c.h"
#elif ZLTABOUTMODE==ZLTABOUTMODE_CPP
	#include "zltabout_cpp.hpp"
#else	// #if ZLTABOUTMODE==ZLTABOUTMODE_DUMMY
	#ifndef ZLTABOUT_OTHER_MODE
		#error Error ZLTABOUTMODE !
	#endif	// #ifdef ZLTABOUT_OTHER_MODE
#endif	// #if ZLTABOUTMODE==ZLTABOUTMODE_DUMMY

/** @def ZLTOUTTYPEA
 * Narrow output stream's type (窄输出流的类型).
 *
 * @see ZLTOUTTYPE, ZLTOUTTYPEW
 */

/** @def ZLTOUTTYPEW
 * Wide output stream's type (宽输出流的类型).
 *
 * @see ZLTOUTTYPE, ZLTOUTTYPEA
 */

/** @def ZLTOUTCA
 * Writes a narrow character to a stream (向流输出一个窄字符).
 *
 * Prototype: `int zltoutcA(ZLTOUTTYPEA sout, char ch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	ch	Character (字符).
 * @return	Each of these functions returns the character written. A return value of EOF indicates an error.
 *
 * @see ZLTOUTC, ZLTOUTCW
 */

/** @def ZLTOUTCW
 * Writes a wide character to a stream (向流输出一个宽字符).
 *
 * Prototype: `wint_t zltoutcW(ZLTOUTTYPEW sout, wchar_t ch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	ch	Character (字符).
 * @return	Each of these functions returns the character written. A return value of WEOF indicates an error.
 *
 * @see ZLTOUTC, ZLTOUTCA
 */

/** @def ZLTOUTSA
 * Write a narrow string to a stream (向流输出窄字符串).
 *
 * Prototype: `void zltoutsA(ZLTOUTTYPEA sout, const char* str, size_t cch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	str	Output string (输出字符串).
 * @param[in]	cch	Count of characters (字符数).
 *
 * @see ZLTOUTS, ZLTOUTSW
 */

/** @def ZLTOUTSW
 * Write a wide string to a stream (向流输出宽字符串).
 *
 * Prototype: `void zltoutsW(ZLTOUTTYPEW sout, const wchar_t* str, size_t cch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	str	Output string (输出字符串).
 * @param[in]	cch	Count of characters (字符数).
 *
 * @see ZLTOUTS, ZLTOUTSA
 */

/** @def ZLTOUTVFA
 * Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出窄字符串版).
 *
 * Prototype: `void zltoutvfA(ZLTOUTTYPEA sout, int indent, const char* fmt, va_list argptr);;`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 *
 * @see ZLTOUTVF, ZLTOUTVFW
 */

/** @def ZLTOUTVFW
 * Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出宽字符串版).
 *
 * Prototype: `void zltoutvfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, va_list argptr);;`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 *
 * @see ZLTOUTVF, ZLTOUTVFA
 */

/** @def ZLTOUTFA
 * Formatted output with indentation (带缩进格式化输出窄字符串版).
 *
 * Prototype: `void zltoutfA(ZLTOUTTYPEA sout, int indent, const char* fmt, ...);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 *
 * @see ZLTOUTF, ZLTOUTFW
 */

/** @def ZLTOUTFW
 * Formatted output with indentation (带缩进格式化输出宽字符串版).
 *
 * Prototype: `void zltoutfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, ...);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 *
 * @see ZLTOUTF, ZLTOUTFA
 */


// == TCHAR marco ==
#ifdef UNICODE
	#define ZLTOUTTYPE	ZLTOUTTYPEW
	#define ZLTOUTC(sout, ch)	ZLTOUTCW(sout, ch)
	#define ZLTOUTS(sout, str, cch)	ZLTOUTSW(sout, str, cch)
	#define ZLTOUTVF(sout, indent, fmt, argptr)	ZLTOUTVFW(sout, fmt, argptr)
	#define ZLTOUTF	ZLTOUTFW
#else	// #ifdef UNICODE
	#define ZLTOUTTYPE	ZLTOUTTYPEA
	#define ZLTOUTC(sout, ch)	ZLTOUTCA(sout, ch)
	#define ZLTOUTS(sout, str, cch)	ZLTOUTSA(sout, str, cch)
	#define ZLTOUTVF(sout, indent, fmt, argptr)	ZLTOUTVFA(sout, fmt, argptr)
	#define ZLTOUTF	ZLTOUTFA
#endif	// #ifdef UNICODE

/** @def ZLTOUTTYPE
 * Output stream's type (输出流的类型).
 *
 * @see ZLTOUTTYPEA, ZLTOUTTYPEW
 */

/** @def ZLTOUTC
 * Writes a character to a stream (向流输出一个字符).
 *
 * Prototype: `int zltoutc(ZLTOUTTYPE sout, TCHAR ch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	ch	Character (字符).
 * @return	Each of these functions returns the character written. A return value of EOF/WEOF indicates an error.
 *
 * @see ZLTOUTCA, ZLTOUTCW
 */

/** @def ZLTOUTS
 * Write a string to a stream (向流输出字符串).
 *
 * Prototype: `void zltouts(ZLTOUTTYPE sout, const TCHAR* str, size_t cch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	str	Output string (输出字符串).
 * @param[in]	cch	Count of characters (字符数).
 *
 * @see ZLTOUTSA, ZLTOUTSW
 */

/** @def ZLTOUTVF
 * Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出).
 *
 * Prototype: `void zltoutvf(ZLTOUTTYPE sout, int indent, const TCHAR* fmt, va_list argptr);;`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 *
 * @see ZLTOUTVFA, ZLTOUTVFW
 */

/** @def ZLTOUTF
 * Formatted output with indentation (带缩进格式化输出).
 *
 * Prototype: `void zltoutf(ZLTOUTTYPE sout, int indent, const TCHAR* fmt, ...);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 *
 * @see ZLTOUTFA, ZLTOUTFW
 */

#endif // #ifndef __ZLTABOUT_H_INCLUDED


/** @} */	// @addtogroup GROUP_ZLTABOUT
/** @} */	// @addtogroup GROUP_ZYLLIBC
