#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "AVLtree.h"



//Возвращает node_for_balance -- корень сбалансированного поддерева
template <class Key>
AvlNode<Key>* AVLtree<Key> :: balance (AvlNode<Key>* node_for_balance){
	node_for_balance -> recomputeHeight();
	short delta_balance = node_for_balance -> getDeltaBalanceOfNode();

	if (delta_balance == 2)
	{
		//todo сделать повороты, в которых пересчитывается высота
		return node_for_balance;
	}
	if (delta_balance == -2)
	{
		//сделать повороты
		return node_for_balance;
	}
	// балансировка не нужна; -1 <= delta_balance <= 1
	return node_for_balance;
}

template <class Key>
AvlNode<Key>* AVLtree<Key>::recursive_insert (Key key, AvlNode<Key>* current_root){
	
	if (current_root == nullptr)
		return new AvlNode<Key>(key);
	if (key == current_root -> key)
		return current_root;

	if (key < current_root -> key)
		current_root -> left = recursive_insert(key, current_root -> left);
	else 
		current_root -> right = recursive_insert(key, current_root -> right);
	
	return balance(current_root);
}

template <class Key>
void AVLtree<Key>::insert(Key key){
	root = recursive_insert(key, root);
}


#endif