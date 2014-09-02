/*
 * =====================================================================================
 *
 *       Filename:  three.cpp
 *
 *    Description:  在linux环境中编辑/编译/运行下面的程序,体会C++程序中的输入输出流类对象的输入和输出操作.
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 19时21分38秒
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

int main ()
{
	int 	i ;
	float 	f ;
	char 	s[80] ;

	cout << "Enter an integer, float, and string :" ;
	cin >> i >> f >> s ;
	cout << "Here's your data :" << i << ' ' << f << endl << s << '\n' ;

	return 0 ;

}
