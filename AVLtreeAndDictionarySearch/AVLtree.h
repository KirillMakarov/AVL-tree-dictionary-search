#ifndef AVLTREE
#define AVLTREE
#include <iostream>

template <class Key>
class AvlNode {
private:
	Key key;
	AvlNode* parent;
	AvlNode* left;
	AvlNode* right;
};

//=============================================================================
//== AVLtree ==================================================================
//=============================================================================

template <class Key>
class AVLtree {
private:
	AvlNode* root;
};

#include "AVLtree.hpp"
#endif