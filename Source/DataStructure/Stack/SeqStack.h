//
// Created by small on 2025/4/21.
//

#ifndef SEQSTACK_H
#define SEQSTACK_H

#include"../general.h"

#define  STACK_INIT_SIZE   100
#define  STACKINCREMENT  10

typedef char SElemType;
typedef  struct {
    SElemType* base;
    SElemType* top;
    int   stacksize;
} SeqStack;//顺序栈

//初始化
inline Status InitStack(SeqStack& S)
{
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

//销毁
inline Status DestroyStack(SeqStack& S)
{
    free(S.base);
    S.base = S.top = NULL;
    S.stacksize = 0;
    return OK;
}

//遍历输出
inline Status DisplayStack(SeqStack S)
{
    if (!S.base) return ERROR;
    if (S.top == S.base) return ERROR;
    SElemType* p = S.base;
    while (p < S.top)
    {
        cout << *p << " ";
        p++;
    }
    cout << endl;
    return OK;
}

//判断空
inline Status IsStackEmpty(SeqStack S)
{
    if (!S.base) return TRUE;
    return S.top == S.base;
}

//求长度
inline int StackLength(SeqStack S)
{
    if (!S.base) return ERROR;
    return S.top - S.base;
}

//得到栈首元素
inline Status GetTop(SeqStack S, SElemType& e)
{
    if (!S.base) return ERROR;
    if (S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}

inline Status Push(SeqStack& S, SElemType e)
{
    if (!S.base) return ERROR;
    if (S.top - S.base >= S.stacksize)
    {//如果栈满，重新分配空间
        SElemType* newBase = (SElemType*)realloc(S.base, (static_cast<unsigned long long>
            (S.stacksize) + STACKINCREMENT) * sizeof(SElemType));
        if (!newBase) exit(OVERFLOW);
        S.top = newBase + (S.top - S.base);
        S.base = newBase;
        S.stacksize += STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    return OK;
}

//出栈
inline Status Pop(SeqStack& S, SElemType& e)
{
    if (!S.base) return ERROR;
    if (S.top == S.base) return ERROR;
    e = *(--S.top);
    return OK;
}

//清空栈
inline Status ClearStack(SeqStack& S)
{
    if (!S.base) return ERROR;
    S.top = S.base;
    return OK;
}

#endif //SEQSTACK_H
