// LeetCode02_AddTwoNumListNode.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include "string.h"
#include "ListNoded.h"
#include "Solution.h"
#include "Test.h"

using namespace std;
int main()
{
	ListNoded* l1 = new ListNoded(3);
	ListNoded* l2 = new ListNoded(5);
	ListNoded* l3 = new ListNoded(5);
	l1->next = l2;
	l2->next = l3;

	ListNoded* p1 = new ListNoded(3);
	ListNoded* p2 = new ListNoded(5);
	ListNoded* p3 = new ListNoded(5);
	p1->next = p2;
	p2->next = p3;

	/*ListNoded l1, l2, l3,p1,p2,p3;
	l1.val = 3;
	l1.next = &l2;
	l2.val = 6;
	l2.next = &l3;
	l3.val = 7;

	p1.val = 3;
	p1.next = &p2;
	p2.val = 6;
	p2.next = &p3;
	p3.val = 7;*/
	
	

	//Solution* s = new Solution();
	//s->addTwoNumbers(l1,p1);
	//ListNoded* q = s->addTwoNumbers(l1, p1);

	Test* t=new Test();
	ListNoded* q= t->AddTwoNumbers(l1, p1);
	cout << q->val << endl;
	cout << q->next->val << endl;
	cout<< q->next->next->val << endl;

	
	//cout << l1->val << endl;
	system("pause");

	delete t;
	return 0;
}

