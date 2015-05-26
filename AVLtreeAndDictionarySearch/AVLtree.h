#ifndef AVLTREE
#define AVLTREE
#include <iostream>
#include "AvlNode.h"


//=============================================================================
//== AVLtree ==================================================================
//=============================================================================

//TODO: Реализовать удаление узла в качестве дополнительного задания.
template <class Key, class Comparator>
class AVLtree {
private:
	AvlNode<Key>* root;
	/*
	Осуществляет рекурсивную вставку элемента с ключом key, если это необходимо.
	Возвращает current_root со сбалансированным AVL поддеревом.
	*/
	AvlNode<Key>* recursive_insert (const Key & key, AvlNode<Key>* current_root);

	/*
	Осуществляет балансировку для node_for_balance, если это необходимо.
	Возвращает корень сбалансированного поддерева
	*/
	AvlNode<Key>* balance (AvlNode<Key>* node_for_balance);

	AvlNode<Key>* simple_rotate_left (AvlNode<Key>* node_for_rotate);
	AvlNode<Key>* simple_rotate_right (AvlNode<Key>* node_for_rotate);

	void recursive_print(AvlNode<Key>* p, int level);

	int size;

	void destroy(AvlNode<Key>* node);

	bool recursive_isAVLTree(AvlNode<Key>* node);
	Comparator comparator;
public:
	AVLtree():root(0), size(0){}
	~AVLtree(){destroy(root);}

	bool isAVLTree();

	AvlNode<Key>* getRoot(){return root;}
	/*
	Добавляет элемент key в AVL дерево,
	при необходимости происходит балансировка.

	Если элемент уже добавлен в дерево, то повторного добавления не осуществляется,
	то есть двух элементов с одинаковым ключом в AVL-дереве не существует.
	*/
	void insert (const Key& key);
	int getSize() const;
	bool find (const Key& key);

};
#include "AVLtree.hpp"
#endif