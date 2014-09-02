/*
 * =====================================================================================
 *
 *       Filename:  four.cpp
 *
 *    Description:  在linux环境中编辑编译运行下面的程序，体会C++程序中main()函数的返回值的意义.
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 19时30分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std ;

int main () 		// 前面的int指定了main函数返回值的数据类型.
{
	int a, b, c ;

	cin >> a >> b ;

	if ( b == 0 )
	      // main()函数返回非0值表示程序遇到错误而结束.
	      return -1 ; 
	c = a / b ;

	cout << "c = " << c << '\n' ;

	// 程序正常结束,函数main()返回值为0.
	return 0 ;
}
