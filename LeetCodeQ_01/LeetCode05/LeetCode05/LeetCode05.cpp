// LeetCode05.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "ListNode05.h"


using namespace std;

static bool IsRepeated(string name, string typed)
{
	int i = 0;
	int j = 0;
	while (j < typed.length())
	{
		if ((i < name.length()) && (name[i] == typed[j]))
		{
			i++;
			j++;
		}
		else if ((j > 0) && (typed[j] == typed[j - 1]))
		{
			j++;
		}
		else
		{
			return false;

		}
	}
	return (bool)(i == name.length());

}

vector<int> partitionLabels(string S)
{
	vector<int> len;

	int last[26];
	for (int i = 0; i < S.length(); i++)
	{
		last[S[i] - 'a'] = i;
	}

	int start = 0;
	int end = 0;

	for (int i = 0;i < S.length(); i++)
	{
		end = max(end, last[S[i] - 'a']);
		if (end == i)
		{
			len.push_back(end - start + 1);
			start = end + 1;
		}

	}

	return len;


}

bool isPalindrome(ListNode05* head)
{
	if (head == nullptr) return true;

	stack<int> listNodeValStack;
	ListNode05* pre = head;

	while (pre)
	{
		listNodeValStack.push(pre->val);
		pre = pre->next;
	}
	
	while (head)
	{
		if (head->val == listNodeValStack.top())
		{
			head = head->next;
			listNodeValStack.pop();
		}
		else
		{
			return false;
		}
	}
	return true;

}

bool validMountainArray(vector<int>& A)
{
	int len = A.size();
	if (len <= 2) return false;

	int m= 0;
	int n = len;

	while (m < len-1)
	{
		if (A[m] < A[m + 1])
		{
			m++;
		}
		else
		{
			break;
		}
	}
	if (m == 0 || m == len) return false;

	while (n > 0)
	{
		if (A[n] > A[n - 1])
		{
			n--;
		}
		else
		{
			break;
		}
	}

	return m == n;
}

int maxProfit(vector<int>& prices) {

	int len = prices.size();

	int(*dp)[2] = new int[len][2];
	dp[0][0] = 0;
	dp[0][1] = -prices[0];

	for (int i=1;i<len;i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
	}
	return dp[len - 1][0];

}


int main()
{
	string name = "ghaokl";
	string typed = "ghaoakkl110";

	bool result = IsRepeated(name, typed);

	cout << bool(result) << endl;

	string s = "4";
	s += "5";
	cout << s << endl;
	system("pause");
	return 0;
}

