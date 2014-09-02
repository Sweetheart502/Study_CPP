/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  C++ 第二章的学习
 *
 *        Version:  1.0
 *        Created:  2014年09月02日 20时38分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <string.h>
#include <iostream>
using namespace std ;

class Student {
	private :
		int number ;
		char name[15] ;
		float score ;
	public :
		void init ( int number1, char *name1, float score1 ) ;
		void modify ( float score1 ) 
		{ score = score1 ; }
		void print () ;
} ;

// 以下是成员函数init () 和 print () 在 Student 类体外的定义
void Student::init ( int number1, char *name1, float score1 ) 
{
	number = number1 ;
	strcpy ( name, name1 ) ;
	score = score1 ;
}

void Student::print ()
{
	cout << "number : " << number << endl << "name : " << name
	     << endl << "score : " << score << '\n' ;
}

int main ()
{
	int numberi ;
	char namei[15] ;
	float scorei ;
	Student stu1, stu2 ; 			// 创建了两个Student类的对象stu1和stu2

	cout << "Enter number :\n" ;
	cin >> numberi ;

	cout << "Enter name :\n" ;
	cin >> namei ;

	cout << "Enter score :\n" ;
	cin >> scorei ;

	stu1.init ( numberi, namei, scorei ) ; 		// 对象stu1调用成员函数init ()

	cout << "Enter number :\n" ;
	cin >> numberi ;

	cout << "Enter name :\n" ;
	cin >> namei ;

	cout << "Enter score :\n" ;
	cin >> scorei ;

	stu2.init ( numberi, namei, scorei ) ; 		// 对象stu2调用成员函数init ()
	stu2.modify ( 87 ) ; 				// 对象stu2调用函数成员modify ()

	stu1.print () ; 				// 对象stu1调用函数成员print ()
	stu2.print () ; 				// 对象stu2调用函数成员print ()

	return 0 ;
}
