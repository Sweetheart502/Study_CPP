/*
 * =====================================================================================
 *
 *       Filename:  jose.c
 *
 *    Description:  Josephus排列问题.
 *        Version:  1.0
 *        Created:  2014年09月04日 14时26分32秒
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
	ElemType order ;
	struct node *next ;
} LNode, *ListLink ;


// 初始化链表
ListLink InitLink ()
{
	ListLink head ;

	head = ( ListLink ) malloc ( sizeof ( LNode ) ) ;

	head->next = NULL ;

	return head ;
}


// 头插法创建链表,将链表的数据域附上标号
int CreatLink_Head ( ListLink h, int n )
{
	ListLink p = h, q ;
	int i ;

	for ( i = 1; i < n + 1; i++ ) {
		q = ( ListLink ) malloc ( sizeof ( LNode ) ) ;
		q->order = i ;
		
		q->next = p->next ;
		p->next = q ;
	}

	return 0 ;
}

// 尾插法创建链表,将链表的数据域附上标号
int CreatLink_Tail ( ListLink h, int n ) 
{
	// p指针指向尾结点,q为新创建的结点
	ListLink p = h, q ;
	int i ;

	for ( i = 1; i < n + 1; i++ ) {
		// 申请新结点空间并赋值
		q = ( ListLink ) malloc ( sizeof ( LNode ) ) ;
		q->order = i ;

		// 将新结点尾插在链表中
		q->next = p->next ;
		p->next = q ;
		// 移动尾指针
		p = q ;
	}

}


// 约瑟夫环的简单实现
// m表示起始位置,k表示间隔长度
int JoseLink ( ListLink h, int m, int k )
{
	ListLink p = h, delp ;
	int i ;
	
	for ( i = 1; i < m; i++ ) {
		// 将指针p放在起始位置的前驱上
		p = p->next ;
	}

	while ( h->next ) {
		// 找到出圈的结点
		for ( i = 1; i < k; i++ ) {
			p = p->next ;
			
			// 如果p指向空结点表示上一步操作无效,所以将其移至首元结点上
			if ( p == NULL ) {
				p = h->next ;
			}

			// 如果p的下一个结点为空结点,则将其移至h上,下一次移动保证它的下一结点有效
			if ( p->next == NULL ) {
				p = h ;
			}
		}
		
		// 删除待删结点
		delp = p->next ;

		// 输出出圈结点的数据域值
		printf ( "\t%d\n", delp->order ) ;

		// 删除出圈结点
		p->next = delp->next ;
		free ( delp ) ;
	}

}
/*
void Print ( ListLink h )
{
	ListLink p = h->next ;

	while ( p ) {
		printf ( "%d ", p->order ) ;
		p = p->next ;
	}
}
*/

int main(int argc, char *argv[])
{
	// n表示链表中的结点总数;
	// m表示起始位置
	// k表示间隔长度
	int n, m, k ;
	ListLink head ;

	// 输入链表中的结点总数
	printf ( "Please input your n ( the member sum ) :\n" ) ;
	scanf ( "%d", &n ) ;

	head = InitLink () ;

	CreatLink_Tail ( head, n ) ;

	printf ( "Please input the begin_pos m and the distance k: \n" ) ;
	scanf ( "%d %d", &m, &k ) ;

	printf ( "The jose display :\n" ) ;
	JoseLink ( head, m, k ) ;

	return EXIT_SUCCESS;
}

