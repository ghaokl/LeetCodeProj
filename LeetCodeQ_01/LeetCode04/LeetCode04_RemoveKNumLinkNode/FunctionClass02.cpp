#include "stdafx.h"
#include "FunctionClass02.h"


ListNode03* FunctionClass02::RemoveNthFromEnd(ListNode03* head,int n)
{
	if (!head) return nullptr;
	ListNode03* pre = nullptr;
	pre->next = head;
	ListNode03* fast = nullptr;
	ListNode03* slow = nullptr;
	slow = fast = head;

	int k = n + 1;
	while (k--)
	{
		fast = fast->next;
	}

	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	ListNode03* temp = slow->next;
	slow->next = slow->next->next;
	delete temp;
	return pre->next;


}