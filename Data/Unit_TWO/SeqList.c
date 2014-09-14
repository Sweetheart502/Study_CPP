/*
 * =====================================================================================
 *
 *       Filename:  SeqList.c
 *
 *    Description:  顺序存储实现的增删改查等操作. 感觉有错误.未修复.
 *
 *        Version:  1.0
 *        Created:  2014年09月01日 20时34分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <stdio.h>

#define		MAXSIZE		100
#define		ERROR		-1
#define		OK		0

typedef	int elemtype ;

typedef struct {
	elemtype elem[MAXSIZE] ;
	int length ;
} SeqList ;

void Init_SeqList ( SeqList *L )
{
	L->length = 0 ;
}

// ÊäÈëÏßÐÔ±íµÄÊýŸÝ
int Creat_SeqList ( SeqList *L )
{
	int i ;

	printf ( "Please input the length :\n" ) ;
	scanf ( "%d", &L->length ) ;

	printf ( "Please input %d element :\n", L->length ) ;
	for ( i= 1; i <= L->length; i++ )
		scanf ( "%d", &L->elem[i] ) ;

	return OK ;
}


// Êä³öÏßÐÔ±íµÄÊýŸÝ
int Output_SeqList ( SeqList *L )
{
	int i ;

	if ( L->length == 0 ) {
		printf ( "The list is NULL.\n" ) ;
		return ERROR ;
	}

	for ( i = 1; i <= L->length; i++ )
		printf ( "%d  ", L->elem[i] ) ;
	printf ( "\n" ) ;

	return OK ;
}

// »ñµÃË³Ðò±íÉÏŸßÌåµÄÖµ
int GetElem ( SeqList *L, int i, elemtype *x )
{
	if ( L->length == 0 ) {
		printf ( "The list is NULL.\n" ) ;
		return ERROR ;
	}

	if ( i < 1 || i > L->length ) {
		printf ( "Postion is ERROR.\n" ) ;
		return ERROR ;
	}

	*x = L->elem[i] ;

	return OK ;
}

// »ñµÃË³Ðò±íÄ³ÖµµÄÎ»ÖÃ
int Locate ( SeqList *L, elemtype x )
{
	int i ;

	if ( L->length == 0 ) {
		printf ( "The list is NULL.\n" ) ;
	}
/*
	if ( i < 1 || i > L->length ) {
		printf ( "Postion is ERROR.\n" ) ;
		return ERROR ;
	}
*/
	for ( i = 1; i <= L->length; i++ ) {
		if ( L->elem[i] == x )
			break ;
	}

	if ( i <= L->length ) 
		return i ;
	else 
		return 0 ;
}

int Insert_SeqList ( SeqList *L, int i, elemtype *x )
{
	int k ;

	//检验线性表是否已满
	if ( L->length == MAXSIZE - 1 ) {
		printf ( "The list is full.\n" ) ;
		return -1 ;
	}

	// 检验位置的合法性
	if ( i < 1 || i > L->length + 1 ) {
		printf ( "Postion is ERROR.\n" ) ;
		return -1 ;
	}

	// 空出插入位置
	for ( k = L->length; k >= i; k-- ) {
		L->elem[k+1] = L->elem[k] ;
	}
	// 插入 x
	L->elem[i] = *x ;

	// 长度加１
	L->length++ ;

	return OK ;
}

int Delete_SeqList ( SeqList *L, int i, elemtype *x )
{
	int k ;

	if ( L->length == 0 ) {
		printf ( "The list is NULL.\n" ) ;
		return ERROR ;
	}

	if ( i < 1 || i > L->length ) {
		printf ( "Postion is ERROR.\n" ) ;
		return ERROR ;
	}

	*x = L->elem[i] ; 

	for ( k = i; k <= L->length; k++ ) {
		L->elem[k] = L->elem[k+1] ;
	}

	L->length-- ;

	return OK ; 
}

int Reserve_SeqList ( SeqList *L )
{
	int i ;
	elemtype tmp ;

	for ( i = 1; i <= L->length/2; i++ ) {
		tmp = L->elem[i] ;
		L->elem[i] = L->elem[L->length - i + 1] ;
		L->elem[L->length - i + 1] = tmp ;
	}

	return OK ;
}

// 将两个升序的线性表合并为一个升序的线性表
int Merge ( SeqList *La, SeqList *Lb, SeqList *Lc )
{
	int i, j, k ;

	 i = j = k = 1 ;

	 while ( i <= La->length && j <= Lb->length ) {
		if ( La->elem[i] <= Lb->elem[j] )
			Lc->elem[k++] = La->elem[i++] ;
		else
			Lc->elem[k++] = Lb->elem[j++] ;
	 }

	 while ( i <= La->length ) {
		Lc->elem[k++] = La->elem[i++] ;
	 }

	 while ( j <= Lb->length ) {
		Lc->elem[k++] = Lb->elem[j++] ;
	 }

	 Lc->length = La->length + Lb->length ;

	 return OK ;
}

int main ()
{
	SeqList La, Lb, Lc ;
	elemtype x, position ;

	
	Init_SeqList ( &La ) ;		
	Creat_SeqList ( &La ) ;			

	// 获得３位置数据元素
	printf ( "\n\t\t\t-- GetElem --\n" ) ;
	GetElem ( &La, 3, &x ) ;	
	sleep ( 1 ) ;
	printf ( "The element is %d.\n", x ) ;

	// 获得查找数据的位置
	printf ( "\n\t\t\t-- Locate --\n" ) ;
	position = Locate ( &La, x ) ;	
	sleep ( 1 ) ;
	if ( position == ERROR )
		printf ( "The postion is ERROR.\n" ) ;
	else if ( position == 0 ) 
		printf ( "Not find.\n" ) ;
	else 
		printf ( "The element's position is %d.\n", position ) ;

	// 插入数据元素
	printf ( "Please input your insert_elem and position:" ) ;
	scanf ( "%d", &x ) ;
	scanf ( "%d", &position ) ;
	Insert_SeqList ( &La, position, &x ) ;	
	Output_SeqList ( &La ) ;

	// 删除数据元素
	printf ( "Please input your delete_position:" );
	scanf ( "%d", &position ) ;
	Delete_SeqList ( &La, position, &x ) ;	
	printf ( "The delete_elem is %d.\n", x ) ;

	// 充值线性表
	Reserve_SeqList ( &La ) ;		

	Output_SeqList ( &La ) ;		

	
	Init_SeqList ( &Lb ) ;
	Creat_SeqList ( &Lb ) ;
	Output_SeqList ( &Lb ) ;


	// 合并线性表
	Merge ( &La, &Lb, &Lc ) ;
	Output_SeqList ( &Lc ) ;

	return 0 ;
}

