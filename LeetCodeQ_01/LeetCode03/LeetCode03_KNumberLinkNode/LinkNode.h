#pragma once
#include "stdafx.h"

struct LinkNode
{
	int val;
	LinkNode* next;
	LinkNode(int x):val(x),next(nullptr){}
};
