#pragma once

#include "stdafx.h"
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#include "ListNode05.h"

using namespace std;

class Fun05
{
public:
	ListNode05* addTwoNumbers(ListNode05* l1, ListNode05* l2);
	void reorderList(ListNode05* head);
	ListNode05* GetMidNode(ListNode05* head);
	ListNode05* ReverseListNode(ListNode05* head);
	void MergeList(ListNode05* l1, ListNode05* l2);
	ListNode05* deleteDuplicates(ListNode05* head);
	bool isPalindrome(ListNode05* head);
	bool uniqueOccurrences(vector<int>& arr);
	int GetLengthListNode(ListNode05* head);
	void GetSamePoint(ListNode05* headA, ListNode05* headB);
	ListNode05 *getIntersectionNode(ListNode05 *headA, ListNode05 *headB);

	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K);

};

