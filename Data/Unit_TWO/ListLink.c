/*
 * =====================================================================================
 *
 *       Filename:  ListLink.c
 *
 *    Description:  课堂简介单链表
 *
 *        Version:  1.0
 *        Created:  2014年09月03日 15时12分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType ;

typedef struct node {
	ElemType elem ;
	struct node *next ;
} LNode, *ListLink ;


// 初始化链表为空链表
ListLink InitLink ()
{
	ListLink head ;

	head = ( ListLink ) malloc ( sizeof ( LNode ) ) ;
	head->next = NULL ;

	return head ;
}


// 创建链表
int CreatLink ( ListLink h )
{
	ListLink p ;
	int x ;

	scanf ( "%d", &x ) ;

	while ( x > 0 ) {
		p = ( ListLink ) malloc ( sizeof ( LNode ) ) ;
		p->elem = x ;
		p->next = h->next ;
		h->next = p ;

		scanf ( "%d", &x ) ;
	}
	
	return 0 ;
}

// 输出链表
int PrintLink ( ListLink h )
{
	ListLink p ;

	p = h->next ;

	if ( p == NULL ) {
		printf ( "The lisrlink is NULL.\n" ) ;
		return -1 ;
	}

	while ( p ) {
		printf ( "%4d", p->elem ) ;
		p = p->next ;
	}
	printf ( "\n" ) ;

	return 0 ;
}

// 按值查找
ListLink GetPosition_Value ( ListLink h, int value )
{
	ListLink p = h->next ;

	while ( p ) {
		if ( p->elem == value )
		      break ;
		p = p->next ;
	}

	return p ;
}

// 按序查找
ListLink GetPosition_Order ( ListLink h, int i )
{
	ListLink p = h ;
	int j ;

	if ( i <= 0 ) {
		printf ( "The position isERROR.\n" ) ;
		return NULL ;
	}

	for ( j = 0; p && j < i; j++ ) {
		p = p->next ;
	}

	return p ;
}

// 在特定位置插入数据元素
int InsertLink ( ListLink h, int i, int value )
{
	ListLink p, q ;

	// 先找到插入的位置
	p = GetPosition_Order ( h, i-1 ) ;

	// 检验是否找到位置
	if ( p == NULL ) {
		printf ( "The position isERROR.\n" ) ;
		return -1 ;
	}

	// q进行赋值
	q = ( ListLink ) malloc ( sizeof ( LNode ) ) ;
	q->elem = value ;

	// 进行插入
	q->next = p->next ;
	p->next = q ;
	
	return 0 ;
}

// 删除特定位置的数据
int DeleteLink ( ListLink h, int i, int *x )
{
	ListLink p, q ;
	
	p = GetPosition_Order ( h, i-1 ) ;

	if ( p == NULL || p->next == NULL) {
		printf ( "The position is ERROR.\n" ) ;
		return -1 ;
	}

//	*x = p->next->elem ;

	// 删除
	q = p->next ;
	p->next = q->next ;
	*x = q->elem ; 

	return 0 ;
}




int main(int argc, char *argv[])
{
	ListLink head, p ;
	ElemType x, pos ;

	// init the listlink
	head = InitLink () ;

	// creat a listlink
	CreatLink ( head ) ;

	// get a value that position is told
	printf ( "Please input the get value :\n" ) ;
	scanf ( "%d", &x ) ;
	p = GetPosition_Value ( head, x ) ;
	printf ( "\n%d\n", p->elem ) ;

	// insert a number
	printf ( "Please input your inserted value :\n" ) ;
	scanf ( "%d", &x ) ;
	printf ( "Please input the position :\n" ) ;
	scanf ( "%d", &pos ) ;
	InsertLink ( head, pos, x ) ;

	// delete a number
	printf ( "Please input the position :\n" ) ;
	scanf ( "%d", &pos ) ;
	DeleteLink ( head, pos, &x ) ;
	// printf ( "The value is %d.\n". x ) ;

	// reverse
	

	// merge


	// print the listlink
	PrintLink ( head ) ;

	return EXIT_SUCCESS;
}

