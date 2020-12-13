// LeetCode03_KNumberLinkNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "FunctionClass.h"
#include "LinkNode.h"
#include <iostream>
using namespace std;


int main()
{
	LinkNode* l1 = new LinkNode(1);
	LinkNode* l2 = new LinkNode(2);
	LinkNode* l3 = new LinkNode(3);
	LinkNode* l4 = new LinkNode(4);
	LinkNode* l5 = new LinkNode(5);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	FunctionClass* fun = new FunctionClass();

	LinkNode* p = fun->getKthFrom2End(l1, 1);

	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}

	delete fun;

	system("pause");
	return 0;
}

