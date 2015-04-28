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

	//-1, 0, 1
	char balance;

public:
	AvlNode(Key key_from_user):key(key_from_user), parent(0), left(0), right(0){}

};

//=============================================================================
//== AVLtree ==================================================================
//=============================================================================

template <class Key>
class AVLtree {
private:
	AvlNode<Key>* root;
	void recursive_insert (Key key, AvlNode<Key>* current_root);

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