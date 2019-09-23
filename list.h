#ifndef __LIST_H_
#define __LIST_H_

#include <stdbool.h>

typedef struct node{
	struct node* Last;
	struct node* Next;
	unsigned int Length;
	char Data[1];
}Node_t;

typedef struct list{
	Node_t* RootNode;
	unsigned int NodeTotal;
}List_t;

void ListInit(List_t* pList);

bool InsertNodeFromBehind(List_t* pList, char* pDataBuf, unsigned int pBufLen);

bool InsertNodeFromFront(List_t* pList, char* pDataBuf, unsigned int pBufLen);

/*
@brief          
@param[in]  pList		    指向需要操作的链表结构
@param[out] pDataBuf	    删除节点的数据存储地址
@param[in]  pBufLen		    缓存的最大长度，如果小于节点数据长度将导致取出的数据不全

@return     validLength     存入缓存区的实际数据长度，节点无数据或者链表为空时返回0
*/
unsigned int DeletNodeFromBehind(List_t* pList, char* pDataBuf, unsigned int pBufLen);

/*
@brief                      从链表的前端删除节点，并将节点中存储的数据放入指定的缓存区
                            中。
@param[in]  pList		    指向需要操作的链表结构
@param[out] pDataBuf	    删除节点的数据存储地址
@param[in]  pBufLen		    缓存的最大长度，如果小于节点数据长度将导致取出的数据不全

@return     validLength     存入缓存区的实际数据长度，节点无数据或者链表为空时返回0
*/
unsigned int DeletNodeFromFront(List_t* pList, char* pDataBuf, unsigned int pBufLen);

void ListReset(List_t* pList);

#endif