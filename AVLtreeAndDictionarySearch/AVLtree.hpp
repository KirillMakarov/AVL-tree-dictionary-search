#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "AVLtree.h"

template <class Key>
int AVLtree<Key>::getSize() const
{
	return size;
}

//Можно создать одну универсальную функцию для поворотов, 
//но разделение на 2 делает код более читабельным
//...
//Делает левый поворот вокруг node_for_rotate
//возвращает корень сбалансированного дерева (это может быть не node_for_rotate)
//
template <class Key>
AvlNode<Key>* AVLtree<Key>::simple_rotate_left (AvlNode<Key>* node_for_rotate){
	AvlNode<Key>* temp_node = node_for_rotate -> right;
	node_for_rotate ->right = temp_node->left;
	temp_node -> left = node_for_rotate;

	node_for_rotate->recomputeHeight();
	temp_node -> recomputeHeight();

	return temp_node;
}

template <class Key>
AvlNode<Key>* AVLtree<Key>::simple_rotate_right (AvlNode<Key>* node_for_rotate){
	AvlNode<Key>* temp_node = node_for_rotate -> left;
	node_for_rotate ->left = temp_node->right;
	temp_node -> right = node_for_rotate;

	node_for_rotate->recomputeHeight();
	temp_node->recomputeHeight();
	return temp_node;
}

//Возвращает корень сбалансированного поддерева
//при условии, что все потомки данного корня сбалансированы.
template <class Key>
AvlNode<Key>* AVLtree<Key> :: balance (AvlNode<Key>* node_for_balance){
	node_for_balance -> recomputeHeight();
	short delta_balance = node_for_balance -> getDeltaBalanceOfNode();

	if (delta_balance == 2)
	{
		//высота левого на 2 больше 

		//Рассматриваем левое поддерево node_for_balance
		//Если у него высота правого поддерева строго больше высоты левого,
		//то выполняем большой поворот, так как обычного поворота уже не достаточно.
		if (node_for_balance -> left -> getDeltaBalanceOfNode () < 0)
			node_for_balance -> left = simple_rotate_left(node_for_balance->left);
		//иначе достаточно обычного поворота
		return simple_rotate_right(node_for_balance);
	}
	if (delta_balance == -2)
	{
		//высота правого на 2 больше 

		//Рассматриваем правое поддерево node_for_balance
		//Если у него высота левого поддерева строго больше высоты правого,
		//то выполняем большой поворот.
		if (node_for_balance -> right -> getDeltaBalanceOfNode () > 0)
			node_for_balance -> right = simple_rotate_right(node_for_balance->right);
		return simple_rotate_left(node_for_balance);
	}

	// балансировка не нужна; -1 <= delta_balance <= 1
	return node_for_balance;
}

template <class Key>
AvlNode<Key>* AVLtree<Key>::recursive_insert (Key key, AvlNode<Key>* current_root){

	if (current_root == nullptr)
	{
		size++;
		return new AvlNode<Key>(key);
	}
	if (key == current_root -> key)
		return current_root;

	if (key < current_root -> key)
		current_root -> left = recursive_insert(key, current_root -> left);
	else 
		current_root -> right = recursive_insert(key, current_root -> right);

	//Балансирует, поднимаясь вверх по рекурсии.
	return balance(current_root);
}

template <class Key>
void AVLtree<Key>::insert(Key key){
	root = recursive_insert(key, root);
}

template <class Key>
void AVLtree<Key>::print_tree(){
	recursive_print(root, 0);
}

//todo delete this function in release version
template <class Key>
void AVLtree<Key>::recursive_print(AvlNode<Key>* p, int level){
	 if(p)
    {
        recursive_print(p->left,level + 1);
        for(int i = 0;i< level;i++) cout<<"   ";
        cout << p->key << endl;
        recursive_print(p->right,level + 1);
    }
}


template <class Key>
void AVLtree<Key>::destroy(AvlNode<Key>* node){
	if (node)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}
#endif