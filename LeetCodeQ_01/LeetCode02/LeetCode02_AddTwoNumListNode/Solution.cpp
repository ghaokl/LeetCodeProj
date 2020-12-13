//#pragma once
#include "stdafx.h"
#include "Solution.h"


using namespace std;

ListNoded* Solution::addTwoNumbers(ListNoded* l1, ListNoded* l2)
{
	ListNoded* head = nullptr;
	return head;
	/*ListNoded* head = nullptr;
	ListNoded* tail = nullptr;
	int carry = 0;
	while (l1 || l2)
	{
		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		int sum = n1 + n2 + carry;

		if (!head)
		{
			tail = new ListNoded(sum % 10);
			head = tail;
			
		}
		else
		{
			tail->next = new ListNoded(sum % 10);
			tail = tail->next;
		}
		carry = sum / 10;

		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
		if (carry > 0)
		{
			tail->next = new ListNoded(carry);
		}
		return head;	*/
}