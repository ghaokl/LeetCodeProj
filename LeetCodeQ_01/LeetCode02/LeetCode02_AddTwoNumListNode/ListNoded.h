#pragma once
#include "stdafx.h"

struct ListNoded
{
	int val;
	ListNoded* next;
	ListNoded():val(0),next(nullptr){}
	ListNoded(int x):val(x),next(nullptr){}
	ListNoded(int x,ListNoded* next):val(x),next(next){}
};