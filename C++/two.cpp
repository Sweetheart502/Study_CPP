/*
 * =====================================================================================
 *
 *       Filename:  two.cpp
 *
 *    Description:  上机作业:在linux环境中编辑/编译/运行下面的程序,体会C++程序中的输入输出流类对象的输入输出操作.
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 19时16分12秒
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

int max ( int x, int y ) ; 	// 函数声明

int main ()
{
	int a, b, c ;

	cin >> a >> b ;

	c = max ( a, b ) ;

	cout << "max = " << c << '\n' ;

	return 0 ;
}

int max ( int x, int y ) 	// 函数定义
{
	int z ;

	if ( x >y ) 
	      z = x ;
	else 
	      z = y ;

	return ( z ) ;
}
