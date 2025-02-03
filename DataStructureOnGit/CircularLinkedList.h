#pragma once
#include"general.h"

typedef char ElemType;

typedef struct LNode
{
    ElemType data;
    struct  LNode* next;
} LNode, * LinkList;

//初始化
Status Init(LinkList& L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    if (!L)return ERROR;
    return OK;
}

//创建
Status Create(int  n, LinkList& L)
{
    if (!L)return ERROR;

    LinkList q = L;
    for (int i = n; i > 0; i--) 
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        cin >> p->data;
        p->next = q->next;
        q->next = p;
        q = p;
    }

    q->next = L->next;

    return OK;
}

//遍历输出
Status Traverse(LinkList L)
{
    if (!L) return ERROR; //不能遍历未初始化的表
    if (!L->next) return ERROR; //不能遍历只有头结点的表

    LinkList p = L->next;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != L->next);//先执行一次，再判断
    cout << endl;
    return OK;
}

//销毁
void Destroy(LinkList& L)
{
    LinkList p = L, q = p->next;
    while (q)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
}

//判断空
bool IsEmpty(LinkList L)
{
    return(L->next == NULL);
}

//求长度

//用e返回L中第i个元素的值

//顺序查找第1个值域与e相等的元素的位序

//在L的第i个位置上插入新的元素e

//删序L中的第i个元素



