//
// Created by small on 2025/4/20.
//

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include"../general.h"

typedef char QElemType;
typedef  struct  QNode {
    QElemType data;
    struct  QNode* next;
} QNode, * QueuePtr;

typedef  struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;



//初始化
inline Status InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = static_cast<QueuePtr>(malloc(sizeof(QNode)));
    if (!Q.front) return ERROR;
    Q.front->next = nullptr;
    return OK;
}

//销毁
inline Status DestroyQueue(LinkQueue& Q) {
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

//清空队列
inline Status ClearQueue(LinkQueue& Q) {
    if (Q.rear==Q.front)return OK;//空队列无需清空
    if (Q.rear==nullptr&&Q.front==nullptr)return ERROR;//未分配内存的队列无法清空

    Q.rear = Q.front;
    QueuePtr p = Q.front->next;
    Q.front->next = nullptr;
    while (p) {
        QueuePtr q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

//判断空
inline Status QueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

//求长度
inline int QueueLength(LinkQueue Q) {
    int length = 0;
    QueuePtr p = Q.front;
    while (p != Q.rear) {
        length++;
        p = p->next;
    }
    return length;
}

//得到队首元素
inline Status GetHead(LinkQueue Q, QElemType& e) {
    if (Q.front == Q.rear) return ERROR;
    e = Q.front->next->data;
    return OK;
}

//入队列
inline Status EnQueue(LinkQueue& Q, QElemType e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) exit(OVERFLOW);
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

//出队列
inline Status DeQueue(LinkQueue& Q, QElemType& e) {
    if (Q.front == Q.rear) return ERROR;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return OK;
}

//遍历输出
inline Status DisplayQueue(LinkQueue Q, Status (*visit)(QElemType)) {
    QueuePtr p = Q.front->next;
    while (p) {
        if (!visit(p->data))return ERROR;
        p = p->next;
    }
    return OK;
}

inline Status DisplayQueue(LinkQueue Q) {
    QueuePtr p = Q.front->next;
    while (p) {
        if (!(cout << p->data << " "))return ERROR;
        p = p->next;
    }
    cout << endl;
    return OK;
}

#endif //LINKQUEUE_H
