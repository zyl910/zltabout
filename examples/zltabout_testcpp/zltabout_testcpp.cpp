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

/** @addtogroup GROUP_ZLTABOUT_TESTCPP	zltabout_testcpp
 * Test @ref GROUP_ZLTABOUT for C++ (测试C++下使用 @ref GROUP_ZLTABOUT).
 *
 * @author	[zyl910](mailto:zyl910hero@gmail.com)
 * @since	@ref GROUP_ZLTABOUT 1.0
 * @version	1.0
 * @date	2013-08-23
 *
 * Links:
 *
 * * Git: https://github.com/zyl910/zltabout
 * * Blog: http://www.cnblogs.com/zyl910/tag/zltabout/
 *
 *
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
 * ## Change history (变更日志)
 *
 * [2013-08-23] V1.0
 *
 * * Release v1.0 (发布1.0版).
 *
 * @{
 */

/**
 * @file	zltabout_testcpp.cpp
 * @brief	Test @ref GROUP_ZLTABOUT for C++ (测试C++下使用 @ref GROUP_ZLTABOUT).
 * @since	@ref GROUP_ZLTABOUT 1.0
 */

#include <iostream>
#include <sstream>

#include <stdio.h>
#include <wchar.h>

#include "auto_tchar.h"
#include "auto_tmain.h"

//#define ZLTABOUTMODE	1	// ZLTABOUTMODE_C
#define ZLTABOUTMODE	2	// ZLTABOUTMODE_CPP
#include "zltabout.h"

using namespace std;

/** test mode (测试模式).
 *
 * values:
 * * 1: Test cout/wcout .
 * * 2: Test stringstream/wstringstream .
 *
 */
#define MYTESTMODE	2

/// Do Test.
void dotest(ZLTOUTTYPE sout, int indent) {
	static const TCHAR strEnd[] = _T("(END)");
	int i;
	for(i=0; i<3; ++i) {
		ZLTOUTF(sout, indent+i, _T("indent %d\n"), i);
	}
	ZLTOUTS(sout, strEnd, sizeof(strEnd)/sizeof(strEnd[0])-1);
	ZLTOUTC(sout, _T('\n'));
}

/// main .
int _tmain(int argc, TCHAR* argv[])
{
	ZLTOUTTYPE sout;

	// show.
#if ZLTABOUTMODE==ZLTABOUTMODE_DUMMY
	sout = (ZLTOUTTYPE)NULL;
#elif ZLTABOUTMODE==ZLTABOUTMODE_C
	sout = (ZLTOUTTYPE)stdout;
#elif ZLTABOUTMODE==ZLTABOUTMODE_CPP
	#if (MYTESTMODE==1)
		// test cout/wcout .
		#ifdef UNICODE
			sout = dynamic_cast<ZLTOUTTYPEW>(&wcout);
		#else
			sout = dynamic_cast<ZLTOUTTYPEA>(&cout);
		#endif
	#elif (MYTESTMODE==2)
		// test stringstream/wstringstream .
		basic_stringstream<TCHAR> ss;
		sout = dynamic_cast<ZLTOUTTYPE>(&ss);
	#endif
#else
	#error Error ZLTABOUTMODE !
#endif
	dotest(sout, 0);

	#if (ZLTABOUTMODE==ZLTABOUTMODE_CPP) && (MYTESTMODE==2)
		// test stringstream/wstringstream part 2.
		basic_string<TCHAR> str = ss.str();
		#ifdef UNICODE
			wcout << str;
		#else
			cout << str;
		#endif
	#endif

	return 0;
}


/** @} */	// @addtogroup GROUP_ZLTABOUT_TESTCPP
/** @} */	// @addtogroup GROUP_ZLTABOUT
/** @} */	// @addtogroup GROUP_ZYLLIBC

