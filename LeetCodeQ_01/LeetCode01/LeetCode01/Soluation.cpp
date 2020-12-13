#include "stdafx.h"
#include "Soluation.h"
#include <iostream>
#include "ListNode.h"

using namespace std;


ListNode* Soluation::merge(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;
	if (l1->val <= l2->val)
	{
		l1->next = merge(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = merge(l1, l2->next);
		return l2;
	}

}

ListNode* Soluation::sortList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* pre = head;
	while (fast&&fast->next)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = nullptr;
	return merge(sortList(head), sortList(slow));
}
