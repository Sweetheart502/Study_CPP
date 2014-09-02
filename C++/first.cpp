/*
 * =====================================================================================
 *
 *       Filename:  first.cpp
 *
 *    Description:  自己写的第一个C++程序.
 *
 *        Version:  1.0
 *        Created:  2014年08月24日 20时36分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <iostream>
//using namespace std;

int max ( int x , int y )
{
	int 	z ;

	if ( x > y ) {
		z = x ;
	} else {
		z = y ;
	}

	return z ;
}

int main(int argc, char *argv[])
{
	int 	a , b , c ;

	cin >> a >> b ;
	
	c = max ( a , b );

	cout << "max = " << c << '\n' ;

	return 0;
}

