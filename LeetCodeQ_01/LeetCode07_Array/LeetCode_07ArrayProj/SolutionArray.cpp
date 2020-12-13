#include "stdafx.h"
#include "SolutionArray.h"
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int>> SolutionArray::Transpose(vector<vector<int>>& A)
{
	int m = A.size();
	int n = A[0].size();

	vector<vector<int>> B(n);
	for (int i=0;i<n;i++)
	{
		B[i].resize(m);
	}

	for (int i=0;i<m;i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[j][i] = A[i][j];
		}
	}
	return B;

}
bool SolutionArray::isAnagram(string s, string t)
{
	int record[26] = { 0 };

	for (int i=0;i<s.length();i++)
	{
		record[s[i] - 'a']++;
	}

	for (int j=0;j<t.length();j++)
	{
		record[t[j] - 'a']--;
	}

	for (int i = 0; i < 26; i++)
	{
		if (record[i] != 0)
			return false;	
	}
	return true;
}
//¹þÏ£±í²ßÂÔ
bool SolutionArray::ContainsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int, int> map;
	for (int i=0;i<nums.size();i++)
	{
		if (map.find(nums[i]) != map.end())
		{
			int distance = i - map[nums[i]];
			if (distance <= k)
				return true;

			map[nums[i]] = i;
		}
		else
		{
			map[nums[i]] = i;
		}

	}
	return false;
}

void SolutionArray::nextPermutation(vector<int>& nums)
{
	int i = nums.size() - 2;
	while (i >= 0 && nums[i] >= nums[i + 1])
	{
		i--;
	}
	int j = nums.size() - 1;
	while (j >= 0 && nums[j] <= nums[i])
	{
		j--;
	}

	int temp = nums[j];
	nums[j] = nums[i];
	nums[i] = temp;

	reverse(nums.begin() + i + 1, nums.end());


	int i = nums.size() - 2;
	while (i >= 0 && nums[i] >= nums[i + 1]) {
		i--;
	}
	if (i >= 0) {
		int j = nums.size() - 1;
		while (j >= 0 && nums[i] >= nums[j]) {
			j--;
		}
		swap(nums[i], nums[j]);
	}
	reverse(nums.begin() + i + 1, nums.end());

	
}