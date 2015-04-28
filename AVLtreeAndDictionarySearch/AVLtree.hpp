#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "AVLtree.h"

template <class Key>
void AVLtree<Key>::recursive_insert (Key key, AvlNode<Key>* current_root){
}

template <class Key>
void AVLtree<Key>::insert(Key key){
	if (AVLtree::root == nullptr)
	{
		root = new AvlNode<Key>(key);
		return;
	}

	recursive_insert(key, root);
}


#endif