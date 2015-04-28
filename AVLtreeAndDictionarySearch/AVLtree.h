#ifndef AVLTREE
#define AVLTREE
#include <iostream>
#include "AvlNode.h"


//=============================================================================
//== AVLtree ==================================================================
//=============================================================================

template <class Key>
class AVLtree {
private:
	AvlNode<Key>* root;

	/*
		Осуществляет рекурсивную вставку элемента с ключом key, если это необходимо.
		Возвращает current_root со сбалансированным AVL поддеревом.
	*/
	AvlNode<Key>* recursive_insert (Key key, AvlNode<Key>* current_root);

	/*
		Осуществляет балансировку для node_for_balance, если это необходимо.
		Возвращает node_for_balance со сбалансированным поддеревом.
	*/
	AvlNode<Key>* balance (AvlNode<Key>* node_for_balance);
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