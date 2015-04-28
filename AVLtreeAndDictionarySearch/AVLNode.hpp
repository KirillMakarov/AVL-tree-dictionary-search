#ifndef AVLNODE_HPP
#define AVLNODE_HPP
#include "AvlNode.h"

template <class Key>
short AvlNode<Key>::getDeltaBalanceOfNode()
{
	short result = 0;
	if (left != nullptr)
		result += left -> height;
	if (right != nullptr)
		result -= right ->height;
	return result;
}

template <class Key>
void AvlNode<Key>::recomputeHeight() 
{
	unsigned char resultHeight = 0;
	if (left != nullptr)
		resultHeight = left->height;
	if (right != nullptr && right->height > resultHeight)
		resultHeight = right->height;
	height = resultHeight + 1;
}
#endif