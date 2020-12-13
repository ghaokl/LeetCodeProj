#include "stdafx.h"
#include "FunctionClass.h"

LinkNode* FunctionClass::getKthFrom2End(LinkNode* head, int k)
{
	if (!head) return nullptr;
	LinkNode* slowPtr = nullptr;
	LinkNode* fastPtr = nullptr;
	fastPtr = slowPtr = head;

	//��֤Kֵ�Ƿ����
	int len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	if (k <= 0 || k > len) return nullptr;

	while (k--)
	{
		fastPtr = fastPtr->next;
	}

	while (fastPtr)
	{
		fastPtr = fastPtr->next;
		slowPtr = slowPtr->next;
	}

	return slowPtr;
}
