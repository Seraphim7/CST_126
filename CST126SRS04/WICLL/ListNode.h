#pragma once

class CSWoman;

struct listNode
{
	CSWoman* woman_;
	listNode* next_;

	~listNode();
};
