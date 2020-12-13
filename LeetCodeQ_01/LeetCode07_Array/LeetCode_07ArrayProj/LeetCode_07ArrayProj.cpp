// LeetCode_07ArrayProj.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SolutionArray.h"
#include <iostream>

using namespace std;


int main()
{
	int a[] = { 4,2,0,2,3,2,0};
	vector<int> A(a, a + 7);
	SolutionArray *s = new SolutionArray();

	s->nextPermutation(A);

	for (int i=0;i<7;i++)
	{
		cout << A[i] << endl;
	}

	
	system("pause");
    return 0;
}

