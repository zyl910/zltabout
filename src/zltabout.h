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
 * Formatting output with indentation (带缩进的格式化输出) .
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

#ifndef ZLTABOUTMODE
/** Output Mode (输出模式).
 *
 * Default value is @ref ZLTABOUTMODE_DUMMY (若该宏没有定义，则自动设为默认值 @ref ZLTABOUTMODE_DUMMY ).
 *
 * @see ZLTABOUTMODE_DUMMY, ZLTABOUTMODE_C, ZLTABOUTMODE_CPP
 */
#define ZLTABOUTMODE	ZLTABOUTMODE_DUMMY
#endif

// == Mode choice (模式选择) ==
#if ZLTABOUTMODE==ZLTABOUTMODE_DUMMY
	#define ZLTOUTTYPEA	void*
	#define ZLTOUTTYPEW	void*
	#define ZLTOUTCA(sout, ch)
	#define ZLTOUTCW(sout, ch)
	#define ZLTOUTFVA(sout, fmt, argptr)
	#define ZLTOUTFVW(sout, fmt, argptr)
	#define ZLTOUTFA(args)
	#define ZLTOUTFW(args)
#elif ZLTABOUTMODE==ZLTABOUTMODE_C
	#include "zltabout_c.h"
#elif ZLTABOUTMODE==ZLTABOUTMODE_CPP
	#include "zltabout_cpp.h"
#else	// #if ZLTABOUTMODE==ZLTABOUTMODE_DUMMY
	#ifndef ZLTABOUT_OTHER_MODE
		#error Error ZLTABOUTMODE !
	#endif	// #ifdef ZLTABOUT_OTHER_MODE
#endif	// #if ZLTABOUTMODE==ZLTABOUTMODE_DUMMY

// == TCHAR marco ==
#ifdef UNICODE
	#define ZLTOUTTYPE	ZLTOUTTYPEW
	#define ZLTOUTC(sout, ch)	ZLTOUTCW(sout, ch)
	#define ZLTOUTFV(sout, indent, fmt, argptr)	ZLTOUTFVW(sout, fmt, argptr)
	#define ZLTOUTF	ZLTOUTFW
#else	// #ifdef UNICODE
	#define ZLTOUTTYPE	ZLTOUTTYPEA
	#define ZLTOUTC(sout, ch)	ZLTOUTCA(sout, ch)
	#define ZLTOUTFV(sout, indent, fmt, argptr)	ZLTOUTFVA(sout, fmt, argptr)
	#define ZLTOUTF	ZLTOUTFA
#endif	// #ifdef UNICODE

#endif // #ifndef __ZLTABOUT_H_INCLUDED


/** @} */	// @addtogroup GROUP_ZLTABOUT
/** @} */	// @addtogroup GROUP_ZYLLIBC
