#pragma once
#include "stdafx.h"

struct ListNode03
{
	int val;
	ListNode03* next;
	ListNode03():val(0),next(nullptr){}
	ListNode03(int x):val(x),next(nullptr){}
	ListNode03(int x,ListNode03* next):val(x),next(next){}

};
