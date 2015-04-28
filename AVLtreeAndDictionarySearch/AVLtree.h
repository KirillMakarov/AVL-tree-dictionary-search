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
	AvlNode<Key>* root;
public:
	AVLtree():root(0){}

	/*
		Добавляет элемент key в AVL дерево,
		при необходимости происходит балансировка.

		Если элемент уже добавлен в дерево, то повторного добавления не осуществляется,
		то есть двух элементов с одинаковым ключом в AVL-дереве не существует.
	*/
	void insert (Key key);
};

#include "AVLtree.hpp"
#endif