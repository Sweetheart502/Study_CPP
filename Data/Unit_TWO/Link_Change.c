/*
 * =====================================================================================
 *
 *       Filename:  link.c
 *
 *    Description:  以首元元素为标准进行比较,改变顺序.(小则放前,大则不变.)
 *
 *        Version:  1.0
 *        Created:  2014年09月01日 23时25分04秒
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

typedef struct  node {
	int elem ;
	struct node *next ;
} Elem;

Elem * InitLink ()
{
	Elem *h ;

	h = ( Elem * ) malloc ( sizeof ( Elem ) ) ;

	h->next = NULL ;

	return h ;
}

int CreatLink ( Elem *h )
{
	Elem *p = h, *q ;
	int x ;

	printf ( "Please input the element ( end with zero ) :\n" ) ;
	scanf ( "%d", &x ) ;

	while ( x ) {
		// 申请q空间并赋值
		q = ( Elem * ) malloc ( sizeof ( Elem ) ) ;
		q->elem = x ;

		// 挂链挪尾指针
		p->next = q ;
		p = q ;

		// 输入新的数据元素
		scanf ( "%d", &x ) ;
	}
	// 尾指针next域为NULL
	q->next = NULL ;

	return 0 ;
}

void ChangeLink ( Elem *h )
{
	Elem *p, *q ;
	int key ;

	// key取最先的首元结点数据
	p = h->next ;
	key = p->elem ;
	
	while ( p->next != NULL ) {
		// q指向待比较结点
		q = p->next ;

		// 判断是否小于标志结点的数据元素
		if ( q->elem < key ) {
			// 小于则删除
			p->next = q->next ;

			// 然后头插
			q->next = h->next ;
			h->next = q ;
		}
		else {
			// 不小于则挪动p指针,继续比较
			p = p->next ;
		}
	}
}

int PrintLink ( Elem *h )
{
	Elem *p = h->next ;

	if ( p == NULL ) {
		printf ( "The listlink is NULL.\n" ) ;
		return 1 ;
	}

	while ( p != NULL ) {
		printf ( "%d ", p->elem ) ;
		p = p->next ;
	}
	printf ( "\n" ) ;

	return 0 ;
}

int main(int argc, char *argv[])
{
	Elem *head ;

	// 初始化链表
	head = InitLink () ;

	// 输入数据元素
	CreatLink ( head ) ;

	// 改变链表结构
	ChangeLink ( head ) ;

	// 输出数据元素
	PrintLink ( head ) ;

	return EXIT_SUCCESS;
}

