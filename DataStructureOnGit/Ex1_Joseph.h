#pragma once

#include"CircularLinkedList.h"

void Joseph() {
    int m, n, a[30];

    cout << "输入报数上限m，然后输入人数n（n<30）:";
    cin >> m >> n;
    cout << endl;

    CirLinkList L;
    InitList(L);
    cout << "输入" << n << "个人的密码:";
    CreateList(L, n);
    //TraverseList(L);
}