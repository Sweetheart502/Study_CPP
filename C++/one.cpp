/*
 * =====================================================================================
 *
 *       Filename:  one.cpp
 *
 *    Description: 上机作业:在linux环境编写一个完整的C++控制台应用程序. 
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 19时10分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>
using namespace std ;

int main ()
{
	string user_name ;

	cout << "Please enter your first name :" ;
	cin >> user_name ;
	cout << '\n' << "Hello, " << user_name << " ... and goodbye!\n" ;

	return 0 ;
}

