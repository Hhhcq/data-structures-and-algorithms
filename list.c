#include <stdlib.h>
#include <string.h>
#include "list.h"


bool InsertNodeFromBehind(List_t* pList, char* pDataBuf, unsigned int pBufLen){
    Node_t* newNode = NULL;
    newNode = (Node_t*)malloc(sizeof(Node_t) + pBufLen - 1);
    if(newNode == NULL){
        return false;
    }
    
    newNode->Length = pBufLen;
    memcpy(newNode->Data, pDataBuf, pBufLen);
    if(pList->NodeTotal != 0){
        pList->RootNode->Last->Next = newNode;
        newNode->Last = pList->RootNode->Last;
        pList->RootNode->Last = newNode;
        newNode->Next = pList->RootNode;
    }
    else{
        pList->RootNode = newNode;
        newNode->Last = newNode;
        newNode->Next = newNode;
    }
    
    pList->NodeTotal++;
    return true;
}

bool InsertNodeFromFront(List_t* pList, char* pDataBuf, unsigned int pBufLen){
    Node_t* newNode = NULL;
    newNode = (Node_t*)malloc(sizeof(Node_t) + pBufLen - 1);
    if(newNode == NULL){
        return false;
    }
    
    newNode->Length = pBufLen;
    memcpy(newNode->Data, pDataBuf, pBufLen);
    if(pList->NodeTotal != 0){
        pList->RootNode->Last->Next = newNode;
        newNode->Last = pList->RootNode->Last;
        pList->RootNode->Last = newNode;
        newNode->Next = pList->RootNode;
        pList->RootNode = newNode;
    }
    else{
        pList->RootNode = newNode;
        newNode->Last = newNode;
        newNode->Next = newNode;
    }
    
    pList->NodeTotal++;
    return true;
}

unsigned int DeletNodeFromBehind(List_t* pList, char* pDataBuf, unsigned int pBufLen){
    unsigned int validLength = 0;
    if(pList->RootNode == NULL){
        return validLength;
    }
    Node_t* deletNode = pList->RootNode->Last;
    
    validLength = (deletNode->Length < pBufLen) ? deletNode->Length : pBufLen;
    if(validLength && pDataBuf != NULL){
        memcpy(pDataBuf, deletNode->Data, validLength);
    }
    
    deletNode->Last->Next = pList->RootNode;
    pList->RootNode->Last = deletNode->Last;
    
    free(deletNode);
    
    pList->NodeTotal--;
    if(pList->NodeTotal == 0){
        pList->RootNode = NULL;
    }
    
    return validLength;
}

unsigned int DeletNodeFromFront(List_t* pList, char* pDataBuf, unsigned int pBufLen){
    unsigned int validLength = 0;
    if(pList->RootNode == NULL){
        return validLength;
    }
    Node_t* deletNode = pList->RootNode;
    
    validLength = (deletNode->Length < pBufLen) ? deletNode->Length : pBufLen;
    if(validLength && pDataBuf != NULL){
        memcpy(pDataBuf, deletNode->Data, validLength);
    }
    
    deletNode->Next->Last = deletNode->Last;
    pList->RootNode = deletNode->Next;
    
    free(deletNode);
    
    pList->NodeTotal--;
    if(pList->NodeTotal == 0){
        pList->RootNode = NULL;
    }
    
    return validLength;
}

void ListInit(List_t* pList){
    pList->NodeTotal = 0;
    pList->RootNode = NULL;
}

void ListReset(List_t* pList){
    for(; pList->NodeTotal != 0;){
        DeletNodeFromBehind(pList, NULL, 0);
    }
}

