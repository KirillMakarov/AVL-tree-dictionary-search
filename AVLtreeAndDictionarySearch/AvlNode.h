#ifndef AVLNODE_H
#define AVLNODE_H
//=============================================================================
//== AvlNode ==================================================================
//=============================================================================
template <class Key>
class AvlNode {

	public:
	Key key;
	AvlNode* left;
	AvlNode* right;
	/*
		Так как высота дерева -- это приблизительно логарифм числа элементов,
		а unsigned char гарантировано 1 байт, т.е. 255 максимальная высота, что соответствует
		примерно 2^255 ~ 10^76 различных элементов в дереве, что является достаточным для
		большинства решаемых задач.

		Если же этого недостаточно, то можно изменить char на более вместительный тип, например long.

		Высота дерева из одного элемента 1.

		Русскоязычная статья, описывающая AVL tree, -- http://habrahabr.ru/post/150732/
	*/
	unsigned char height;

	AvlNode(Key key_from_user):key(key_from_user), left(0), right(0), height(1){}

	/*
	Возвращает left.height - right.height
	*/
	short getDeltaBalanceOfNode();
	void recomputeHeight();
};

#include "AVLNode.hpp"
#endif