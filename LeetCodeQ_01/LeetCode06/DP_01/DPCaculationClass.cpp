#include "DPCaculationClass.h"
#include <algorithm>

using namespace std;
/* 视频剪辑 动态规划
*/
int DPCaculationClass::videoStitching(vector<vector<int>>& clips, int T)
{
	vector<int> dp(T + 1, INT_MAX - 1);
	dp[0] = 0;

	for (int i = 1; i <= T; i++)
	{
		for (auto& it : clips)
		{
			if (it[0] < i && i <= it[1])
			{
				dp[i] = min(dp[i], dp[it[0]] + 1);
			}
		}

	}
	return dp[T] == INT_MAX - 1 ? -1 : dp[T];
}

int DPCaculationClass::longestMountain(vector<int>& A)
{
	int n = A.size();
	if (n < 3) return 0;

	vector<int> left(n);
	vector<int> right(n);

	for (int i = 1; i < n; i++)
	{
		left[i] = A[i - 1] < A[i] ? left[i - 1] + 1 : 0;
	}

	for (int j=n-2;j>=0;j--)
	{
		right[j] = A[j] > A[j + 1] ? right[j+1] + 1 : 0;
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (left[i] > 0 && right[i] > 0)
		{
			ans = max(ans, left[i] + right[i] + 1);
		}
	}

	return ans;

}

vector<int> DPCaculationClass::smallerNumbersThanCurrent(vector<int>& nums)
{
	vector<int> pVec (101, 0);
	int n = nums.size();

	for (int i=0;i<n;i++)
	{
		pVec[nums[i]]++;
	}

	for (int i = 1; i <= 100; i++)
	{
		pVec[i] += pVec[i - 1];
	}

	vector<int> ret;

	for (int i = 0; i < n; i++)
	{
		ret.push_back(nums[i] == 0 ? 0 : pVec[nums[i] - 1]);
	}
	return ret;
}

