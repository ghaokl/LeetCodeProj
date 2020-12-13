#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

class SolutionArray
{
public:
	//×ªÖÃ¾ØÕó
	vector<vector<int>> Transpose(vector<vector<int>>& A);
	//×Ö·û´®ÒìÎ»Í¬ÅĞ¶Ï
	bool isAnagram(string s, string t);
	bool ContainsNearbyDuplicate(vector<int>& nums, int k);
	void nextPermutation(vector<int>& nums);
};
