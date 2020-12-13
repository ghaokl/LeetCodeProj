#pragma once
#include "stdafx.h"

struct ListNode05
{
	int val;
	ListNode05* next;
	ListNode05():val(0),next(nullptr){}
	ListNode05(int x):val(x),next(nullptr){}
	ListNode05(int x,ListNode05* next):val(x),next(next){}
	

};
