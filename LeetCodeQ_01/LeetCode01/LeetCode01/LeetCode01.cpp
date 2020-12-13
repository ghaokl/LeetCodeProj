// LeetCode01.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "Soluation.h"
#include "ListNode.h"
#include <iostream>
using namespace std;


int main()
{
	ListNode l1, l2, l3, l4;
	l1.val = 1;
	l1.next = &l2;
	l2.val = 10;
	l2.next = &l3;
	l3.val = 5;
	l3.next = &l4;
	l4.val = 3;

	Soluation s;
	s.sortList(&l1);
	cout << l1.next->val << endl;
	system("pause");
    return 0;
}

