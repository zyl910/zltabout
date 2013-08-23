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
 * zltabout is a lightweight C/C++ library.
 *
 * Features (特性):
 * * Formatting output with indentation (带缩进的格式化输出) .
 * * Same code on C FILE and C++ stream (能以相同的代码绑定到 C FILE 或 C++流).
 * * Support (支持 char/wchat_t/TCHAR) .
 *
 * 
 * Dependent projects (依赖项目):
 * 
 * * [tcharall](https://github.com/zyl910/tcharall): TCHAR on all platforms.
 *
 *
 * ## Usage (用法)
 * 
 * ### C Example
 * 
 * Step 1 Definition `ZLTABOUTMODE` macro and include `zltabout.h` (定义 `ZLTABOUTMODE` 宏 与 引入 `zltabout.h`):
 * 
 * 	#define ZLTABOUTMODE	1	// ZLTABOUTMODE_C
 * 	#include "zltabout.h"
 * 
 * Step2 Definition variable for `ZLTOUTTYPE` type  and assignment (定义 `ZLTOUTTYPE` 类型的变量并赋值为stdout):
 * 
 * 	ZLTOUTTYPE sout;
 * 	sout = (ZLTOUTTYPE)stdout;
 * 
 * Step3 Use `zltoutc` to output a character (使用 `zltoutc` 输出一个字符):
 * 
 * 	zltoutc(sout, _T('\n'));
 * 
 * Step4 Use `zltouts` to output string (使用 `zltouts` 输出字符串):
 * 
 * 	static const TCHAR strEnd[] = _T("(END)");
 * 	zltouts(sout, strEnd, sizeof(strEnd)/sizeof(strEnd[0])-1);
 * 
 * Step5 Use `zltoutf` to formatted output with indentation (使用 `zltoutf` 进行带缩进的格式化输出):
 * 
 * 	for(i=0; i<3; ++i) {
 * 		zltoutf(sout, i, _T("indent %d\n"), i);
 * 	}
 * 
 * 
 * Full code:
 * 
 * 	#include <stdio.h>
 * 	#include <wchar.h>
 * 	
 * 	#include "auto_tchar.h"
 * 	#include "auto_tmain.h"
 * 	
 * 	#define ZLTABOUTMODE	1	// ZLTABOUTMODE_C
 * 	#include "zltabout.h"
 * 	
 * 	
 * 	/// main .
 * 	int _tmain(int argc, TCHAR* argv[])
 * 	{
 * 		ZLTOUTTYPE sout;
 * 		static const TCHAR strEnd[] = _T("(END)");
 * 		int i;
 * 	
 * 		// show.
 * 		sout = (ZLTOUTTYPE)stdout;
 * 		for(i=0; i<3; ++i) {
 * 			zltoutf(sout, i, _T("indent %d\n"), i);
 * 		}
 * 		zltouts(sout, strEnd, sizeof(strEnd)/sizeof(strEnd[0])-1);
 * 		zltoutc(sout, _T('\n'));
 * 	
 * 		return 0;
 * 	}
 * 
 * Example Output:
 * 
 * 	indent 0
 * 		indent 1
 * 			indent 2
 * 	(END)
 * 
 * 
 * ### C++ Example
 * 
 * Step 1 Definition `ZLTABOUTMODE` macro and include `zltabout.h` (定义 `ZLTABOUTMODE` 宏 与 引入 `zltabout.h`):
 * 
 * 	#define ZLTABOUTMODE	2	// ZLTABOUTMODE_CPP
 * 	#include "zltabout.h"
 * 
 * Step2 Definition variable for `ZLTOUTTYPE` type  and assignment (定义 `ZLTOUTTYPE` 类型的变量并赋值为cout/wcout):
 * 
 * 	ZLTOUTTYPE sout;
 * 	#ifdef UNICODE
 * 		sout = dynamic_cast<ZLTOUTTYPEW>(&wcout);
 * 	#else
 * 		sout = dynamic_cast<ZLTOUTTYPEA>(&cout);
 * 	#endif
 * 
 * Step3 Use `zltoutc` to output a character (使用 `zltoutc` 输出一个字符):
 * 
 * 	zltoutc(sout, _T('\n'));
 * 
 * Step4 Use `zltouts` to output string (使用 `zltouts` 输出字符串):
 * 
 * 	static const TCHAR strEnd[] = _T("(END)");
 * 	zltouts(sout, strEnd, sizeof(strEnd)/sizeof(strEnd[0])-1);
 * 
 * Step5 Use `zltoutf` to formatted output with indentation (使用 `zltoutf` 进行带缩进的格式化输出):
 * 
 * 	for(i=0; i<3; ++i) {
 * 		zltoutf(sout, i, _T("indent %d\n"), i);
 * 	}
 * 
 * 
 * Full code:
 * 
 * 	#include <iostream>
 * 	#include <sstream>
 * 	
 * 	#include <stdio.h>
 * 	#include <wchar.h>
 * 	
 * 	#include "auto_tchar.h"
 * 	#include "auto_tmain.h"
 * 	
 * 	//#define ZLTABOUTMODE	1	// ZLTABOUTMODE_C
 * 	#define ZLTABOUTMODE	2	// ZLTABOUTMODE_CPP
 * 	#include "zltabout.h"
 * 	
 * 	using namespace std;
 * 	
 * 	/// test mode (测试模式).
 * 	///
 * 	/// values:
 * 	/// * 1: Test cout/wcout .
 * 	/// * 2: Test stringstream/wstringstream .
 * 	///
 * 	#define MYTESTMODE	2
 * 	
 * 	
 * 	/// Do Test.
 * 	void dotest(ZLTOUTTYPE sout, int indent) {
 * 		static const TCHAR strEnd[] = _T("(END)");
 * 		int i;
 * 		for(i=0; i<3; ++i) {
 * 			zltoutf(sout, indent+i, _T("indent %d\n"), i);
 * 		}
 * 		zltouts(sout, strEnd, sizeof(strEnd)/sizeof(strEnd[0])-1);
 * 		zltoutc(sout, _T('\n'));
 * 	}
 * 	
 * 	/// main .
 * 	int _tmain(int argc, TCHAR* argv[])
 * 	{
 * 		ZLTOUTTYPE sout;
 * 	
 * 		// show.
 * 	#if ZLTABOUTMODE==ZLTABOUTMODE_DUMMY
 * 		sout = (ZLTOUTTYPE)NULL;
 * 	#elif ZLTABOUTMODE==ZLTABOUTMODE_C
 * 		sout = (ZLTOUTTYPE)stdout;
 * 	#elif ZLTABOUTMODE==ZLTABOUTMODE_CPP
 * 		#if (MYTESTMODE==1)
 * 			// test cout/wcout .
 * 			#ifdef UNICODE
 * 				sout = dynamic_cast<ZLTOUTTYPEW>(&wcout);
 * 			#else
 * 				sout = dynamic_cast<ZLTOUTTYPEA>(&cout);
 * 			#endif
 * 		#elif (MYTESTMODE==2)
 * 			// test stringstream/wstringstream .
 * 			basic_stringstream<TCHAR> ss;
 * 			sout = dynamic_cast<ZLTOUTTYPE>(&ss);
 * 		#endif
 * 	#else
 * 		#error Error ZLTABOUTMODE !
 * 	#endif
 * 		dotest(sout, 0);
 * 	
 * 		#if (ZLTABOUTMODE==ZLTABOUTMODE_CPP) && (MYTESTMODE==2)
 * 			// test stringstream/wstringstream part 2.
 * 			basic_string<TCHAR> str = ss.str();
 * 			#ifdef UNICODE
 * 				wcout << str;
 * 			#else
 * 				cout << str;
 * 			#endif
 * 		#endif
 * 	
 * 		return 0;
 * 	}
 * 
 * ### Quick reference (快速参考)
 * 
 * Commonly used functions (常用函数):
 *
 * 	// Output stream's type (输出流的类型).
 * 	#define ZLTOUTTYPE	// C FILE* or C++ basic_ostream .
 * 	
 * 	// Writes a character to a stream (向流输出一个字符).
 * 	int zltoutc(ZLTOUTTYPE sout, TCHAR ch);
 * 	
 * 	// Write a string to a stream (向流输出字符串).
 * 	void zltouts(ZLTOUTTYPE sout, const TCHAR* str, size_t cch);
 * 	
 * 	// Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出).
 * 	void zltoutvf(ZLTOUTTYPE sout, int indent, const TCHAR* fmt, va_list argptr);
 * 	
 * 	//Formatted output with indentation (带缩进格式化输出).
 * 	void zltoutf(ZLTOUTTYPE sout, int indent, const TCHAR* fmt, ...);
 *
 * 
 * Input macros (输入配置性宏) :
 * 
 * * ZL_NOWIDE: No definition wide char functions (不定义宽字符版函数) . Used to improve the compatibility , e.g. bcb6 (用于提高兼容性, 例如bcb6).
 * * @ref ZLTABOUTMODE: Output Mode (输出模式). values: 0(@ref ZLTABOUTMODE_DUMMY), 1(@ref ZLTABOUTMODE_C), 2(@ref ZLTABOUTMODE_CPP) .
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
 * [2013-08-23] V1.0: http://www.cnblogs.com/zyl910/p/zltabout.html
 *
 * * Release v1.0 (发布1.0版).
 *
 * @{
 */

/**
 * @file	zltabout.h
 * @brief	Formatting output with indentation (带缩进的格式化输出) .
 * @since	@ref GROUP_ZLTABOUT 1.0
 *
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
	#define zltoutcA(sout, ch)
	#define zltoutcW(sout, ch)
	#define zltoutsA(sout, str, cch)
	#define zltoutsW(sout, str, cch)
	#define zltoutvfA(sout, indent, fmt, argptr)
	#define zltoutvfW(sout, indent, fmt, argptr)
	#define zltoutfA(args)
	#define zltoutfW(args)
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

/** @def zltoutcA
 * Writes a narrow character to a stream (向流输出一个窄字符).
 *
 * Prototype: `int zltoutcA(ZLTOUTTYPEA sout, char ch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	ch	Character (字符).
 * @return	Each of these functions returns the character written. A return value of EOF indicates an error.
 *
 * @see zltoutc, zltoutcW
 */

/** @def zltoutcW
 * Writes a wide character to a stream (向流输出一个宽字符).
 *
 * Prototype: `wint_t zltoutcW(ZLTOUTTYPEW sout, wchar_t ch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	ch	Character (字符).
 * @return	Each of these functions returns the character written. A return value of WEOF indicates an error.
 *
 * @see zltoutc, zltoutcA
 */

/** @def zltoutsA
 * Write a narrow string to a stream (向流输出窄字符串).
 *
 * Prototype: `void zltoutsA(ZLTOUTTYPEA sout, const char* str, size_t cch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	str	Output string (输出字符串).
 * @param[in]	cch	Count of characters (字符数).
 *
 * @see zltouts, zltoutsW
 */

/** @def zltoutsW
 * Write a wide string to a stream (向流输出宽字符串).
 *
 * Prototype: `void zltoutsW(ZLTOUTTYPEW sout, const wchar_t* str, size_t cch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	str	Output string (输出字符串).
 * @param[in]	cch	Count of characters (字符数).
 *
 * @see zltouts, zltoutsA
 */

/** @def zltoutvfA
 * Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出窄字符串版).
 *
 * Prototype: `void zltoutvfA(ZLTOUTTYPEA sout, int indent, const char* fmt, va_list argptr);;`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 *
 * @see zltoutvf, zltoutvfW
 */

/** @def zltoutvfW
 * Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出宽字符串版).
 *
 * Prototype: `void zltoutvfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, va_list argptr);;`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 *
 * @see zltoutvf, zltoutvfA
 */

/** @def zltoutfA
 * Formatted output with indentation (带缩进格式化输出窄字符串版).
 *
 * Prototype: `void zltoutfA(ZLTOUTTYPEA sout, int indent, const char* fmt, ...);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 *
 * @see zltoutf, zltoutfW
 */

/** @def zltoutfW
 * Formatted output with indentation (带缩进格式化输出宽字符串版).
 *
 * Prototype: `void zltoutfW(ZLTOUTTYPEW sout, int indent, const wchar_t* fmt, ...);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 *
 * @see zltoutf, zltoutfA
 */


// == TCHAR marco ==
#ifdef UNICODE
	#define ZLTOUTTYPE	ZLTOUTTYPEW
	#define zltoutc(sout, ch)	zltoutcW(sout, ch)
	#define zltouts(sout, str, cch)	zltoutsW(sout, str, cch)
	#define zltoutvf(sout, indent, fmt, argptr)	zltoutvfW(sout, fmt, argptr)
	#define zltoutf	zltoutfW
#else	// #ifdef UNICODE
	#define ZLTOUTTYPE	ZLTOUTTYPEA
	#define zltoutc(sout, ch)	zltoutcA(sout, ch)
	#define zltouts(sout, str, cch)	zltoutsA(sout, str, cch)
	#define zltoutvf(sout, indent, fmt, argptr)	zltoutvfA(sout, fmt, argptr)
	#define zltoutf	zltoutfA
#endif	// #ifdef UNICODE

/** @def ZLTOUTTYPE
 * Output stream's type (输出流的类型).
 *
 * @see ZLTOUTTYPEA, ZLTOUTTYPEW
 */

/** @def zltoutc
 * Writes a character to a stream (向流输出一个字符).
 *
 * Prototype: `int zltoutc(ZLTOUTTYPE sout, TCHAR ch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	ch	Character (字符).
 * @return	Each of these functions returns the character written. A return value of EOF/WEOF indicates an error.
 *
 * @see zltoutcA, zltoutcW
 */

/** @def zltouts
 * Write a string to a stream (向流输出字符串).
 *
 * Prototype: `void zltouts(ZLTOUTTYPE sout, const TCHAR* str, size_t cch);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	str	Output string (输出字符串).
 * @param[in]	cch	Count of characters (字符数).
 *
 * @see zltoutsA, zltoutsW
 */

/** @def zltoutvf
 * Formatted output with indentation using a pointer to a list of arguments (参数列表指针形式的带缩进格式化输出).
 *
 * Prototype: `void zltoutvf(ZLTOUTTYPE sout, int indent, const TCHAR* fmt, va_list argptr);;`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 * @param[in]	argptr	Pointer to list of arguments (参数列表指针).
 *
 * @see zltoutvfA, zltoutvfW
 */

/** @def zltoutf
 * Formatted output with indentation (带缩进格式化输出).
 *
 * Prototype: `void zltoutf(ZLTOUTTYPE sout, int indent, const TCHAR* fmt, ...);`
 *
 * @param[in]	sout	Output stream (输出流).
 * @param[in]	indent	Indent (缩进).
 * @param[in]	fmt	Format specification (格式化串).
 *
 * @see zltoutfA, zltoutfW
 */

#endif // #ifndef __ZLTABOUT_H_INCLUDED


/** @} */	// @addtogroup GROUP_ZLTABOUT
/** @} */	// @addtogroup GROUP_ZYLLIBC
