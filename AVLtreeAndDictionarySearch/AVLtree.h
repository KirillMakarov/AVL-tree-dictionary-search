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
	/*
	Осуществляет рекурсивную вставку элемента с ключом key, если это необходимо.
	Возвращает current_root со сбалансированным AVL поддеревом.
	*/
	AvlNode<Key>* recursive_insert (Key key, AvlNode<Key>* current_root);

	/*
	Осуществляет балансировку для node_for_balance, если это необходимо.
	Возвращает корень сбалансированного поддерева
	*/
	AvlNode<Key>* balance (AvlNode<Key>* node_for_balance);

	AvlNode<Key>* simple_rotate_left (AvlNode<Key>* node_for_rotate);
	AvlNode<Key>* simple_rotate_right (AvlNode<Key>* node_for_rotate);

	void recursive_print(AvlNode<Key>* p, int level);
public:
	AVLtree():root(0){}
	
	AvlNode<Key>* root;//todo сделать private

	/*
	Добавляет элемент key в AVL дерево,
	при необходимости происходит балансировка.

	Если элемент уже добавлен в дерево, то повторного добавления не осуществляется,
	то есть двух элементов с одинаковым ключом в AVL-дереве не существует.
	*/
	void insert (Key key);

	/*
		функция для тестирования
	*/

	void print_tree ();
};
#include "AVLtree.hpp"
#endif