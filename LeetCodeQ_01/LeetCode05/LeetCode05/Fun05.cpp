#pragma once
#include "stdafx.h"
#include "ListNode05.h"
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include "Fun05.h"

using namespace std;

ListNode05* Fun05::addTwoNumbers(ListNode05* l1, ListNode05* l2)
{
	stack<int>* s1 = new stack<int>();
	stack<int>* s2 = new stack<int>();
	stack<int>* s3 = new stack<int>();

	if (l1 && !l2) return l1;
	if (!l1 && l2) return l2;

	while (l1)
	{
		s1->push(l1->val);
		l1 = l1->next;
	}

	while (l2)
	{
		s2->push(l2->val);
		l2 = l2->next;
	}
	int carry = 0;
	while (!s1->empty() || !s2->empty())
	{
		int n1 = s1->empty() ? 0 : s1->top();
		int n2 = s2->empty() ? 0 : s2->top();

		int sum = n1 + n2 + carry;

		s3->push(sum % 10);

		carry = sum / 10;

		if (!s1->empty()) s1->pop();
		if (!s2->empty()) s2->pop();
	}

	if (carry > 0) s3->push(carry);

	ListNode05* dumpy = new ListNode05(-1);
	ListNode05* pre = new ListNode05(-1);
	pre = dumpy;
	while (!s3->empty())
	{
		ListNode05* tempNode = new ListNode05(s3->top());
		s3->pop();
		dumpy->next = tempNode;
		dumpy = dumpy->next;
	}
	delete s1;
	delete s2;
	delete s3;

	return pre->next;

}

void Fun05::reorderList(ListNode05* head)
{
	ListNode05* l1 = head;
	ListNode05* mid = GetMidNode(head);
		
	ListNode05* l2 = mid->next;
	mid->next = nullptr;
	l2 = ReverseListNode(l2);

	MergeList(l1, l2);

}

ListNode05* Fun05:: GetMidNode(ListNode05* head)
{
	ListNode05* fast = nullptr;
	ListNode05* slow = nullptr;
	fast = slow = head;

	while (fast)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;

}

ListNode05* Fun05:: ReverseListNode(ListNode05* head)
{
	ListNode05* tempNode = nullptr;
	
	while (head)
	{
		ListNode05* current = nullptr;
		tempNode = head;
		tempNode->next = current;
		
		head = head->next;
		current = tempNode;
	}

	return tempNode;
}

void Fun05:: MergeList(ListNode05* l1, ListNode05* l2)
{
	ListNode05* l1_temp = nullptr;
	ListNode05* l2_temp = nullptr;

	while (l1&&l2)
	{
		l1_temp = l1->next;	
		l2_temp = l2->next;

		l1->next = l2;
		l1 = l1_temp;

		l2->next = l1;
		l2 = l2_temp;

	}
}

ListNode05* Fun05::deleteDuplicates(ListNode05* head)
{
	if (head == nullptr || head->next == nullptr) return head;

	ListNode05* dumppy = new ListNode05(-1);
	ListNode05* preNode = new ListNode05(-1);
	ListNode05* curNode = new ListNode05(-1);
	ListNode05* postNode = new ListNode05(-1);

	dumppy->next = head;
	preNode = dumppy;
	curNode =head;
	postNode = head->next;
	bool flag = false;

	while (postNode)
	{
		
		while (postNode&&postNode->val==curNode->val)
		{
			curNode = postNode;
			postNode = postNode->next;
			flag = true;
		}
		if (flag==true)
		{
			curNode = curNode->next;
			preNode->next = (curNode ? curNode : nullptr);
			if (curNode == nullptr) break;
			postNode = curNode->next;
			flag = false;
		}
		else
		{
			preNode = curNode;
			curNode = postNode;
			postNode = postNode->next;
		}

	}

	return dumppy->next;

}

bool Fun05::isPalindrome(ListNode05* head)
{
	if (head == nullptr || head->next == nullptr) return true;

	ListNode05* pre = head;

	stack<int> s;
	while (pre)
	{
		s.push(pre->val);
		pre = pre->next;
	}

	while (head)
	{
		if (head->val != s.top())
		{
			return false;
		}
		head = head->next;
		s.pop();
	}
	return true;
}

bool Fun05::uniqueOccurrences(vector<int>& arr)
{
	unordered_map<int, int> cnts;
	for (auto& n:arr)
	{
		cnts[n]++;
	}
	unordered_set<int> times;
	for (auto& x:cnts)
	{
		times.insert(x.second);
	}

	return times.size() == cnts.size();
}

int Fun05::GetLengthListNode(ListNode05* head)
{
	int len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return len;
}
void Fun05::GetSamePoint(ListNode05* headA, ListNode05* headB)
{
	int lenA = GetLengthListNode(headA);
	int lenB = GetLengthListNode(headB);

	int n = abs(lenA - lenB);

	if (lenA > lenB)
	{
		while (headA&&n--)
		{
			headA = headA->next;
		}
	}
	else
	{
		while (headB&&n--)
		{
			headB = headB->next;
		}
	}
}

ListNode05* Fun05::getIntersectionNode(ListNode05 *headA, ListNode05 *headB)
{
	if (headA == nullptr || headB == nullptr) return nullptr;

	int lenA = GetLengthListNode(headA);
	int lenB = GetLengthListNode(headB);

	int n = abs(lenA - lenB);

	if (lenA > lenB)
	{
		while (headA&&n--)
		{
			headA = headA->next;
		}
	}
	else
	{
		while (headB&&n--)
		{
			headB = headB->next;
		}
	}

	while (headA&&headB)
	{
		if (headA == headB)
		{
			return headA;
		}
		else
		{
			headA = headA->next;
			headB = headB->next;
		}
	}
	return nullptr;
}

vector<int> Fun05::intersection(vector<int>& nums1, vector<int>& nums2)
{
	int len1 = nums1.size();
	int len2 = nums2.size();
	unordered_set<int> set1;
	unordered_set<int> set2;

	vector<int> intersection;

	for (auto& item:nums1)
	{
		set1.insert(item);
	}

	for (auto& item:nums2)
	{
		set2.insert(item);
	}

	if (len1 > len2)
	{
		for (int i=0;i<len2;i++)
		{
			if (set1.count(nums2[i]))
			{
				intersection.push_back(nums2[i]);
			}
		}
	}
	return intersection;
}

vector<vector<int>> Fun05::kClosest(vector<vector<int>>& points, int K)
{
	priority_queue<pair<int, int>>q;
	for (int i=0;i<K;i++)
	{
		q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
	}
	int n = points.size();
	for (int j = K; j < n; j++)
	{
		int dist = points[j][0] * points[j][0] + points[j][1] * points[j][1];
		if (dist < q.top().first)
		{
			q.pop();
			q.emplace(dist, j);
		}
	}
	vector<vector<int>> ans;
	while (!q.empty())
	{
		ans.push_back(points[q.top().second]);
		q.pop();
	}

	return ans;

}
