#include "stdafx.h"
#include "CSWoman.h"
#include "ListNode.h"

listNode::~listNode()
{
	delete woman_;
	delete next_; 
}
