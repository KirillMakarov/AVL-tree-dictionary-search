#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "AVLtree.h"

template <class Key, class Comparator>
int AVLtree<Key, Comparator>::getSize() const
{
	return size;
}

//Можно создать одну универсальную функцию для поворотов, 
//но разделение на 2 делает код более читабельным
//...
//Делает левый поворот вокруг node_for_rotate
//возвращает корень сбалансированного дерева (это может быть не node_for_rotate)
//
template <class Key, class Comparator>
AvlNode<Key>* AVLtree<Key, Comparator>::simple_rotate_left (AvlNode<Key>* node_for_rotate){
	AvlNode<Key>* temp_node = node_for_rotate -> right;
	node_for_rotate ->right = temp_node->left;
	temp_node -> left = node_for_rotate;

	node_for_rotate->recomputeHeight();
	temp_node -> recomputeHeight();

	return temp_node;
}

template <class Key, class Comparator>
AvlNode<Key>* AVLtree<Key, Comparator>::simple_rotate_right (AvlNode<Key>* node_for_rotate){
	AvlNode<Key>* temp_node = node_for_rotate -> left;
	node_for_rotate ->left = temp_node->right;
	temp_node -> right = node_for_rotate;

	node_for_rotate->recomputeHeight();
	temp_node->recomputeHeight();
	return temp_node;
}

//Возвращает корень сбалансированного поддерева
//при условии, что все потомки данного корня сбалансированы.
template <class Key, class Comparator>
AvlNode<Key>* AVLtree<Key, Comparator> :: balance (AvlNode<Key>* node_for_balance){
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

template <class Key, class Comparator>
AvlNode<Key>* AVLtree<Key, Comparator>::recursive_insert (const Key& key, AvlNode<Key>* current_root){

	if (current_root == nullptr)
	{
		size++;
		return new AvlNode<Key>(key);
	}
	if (key == current_root -> key)
		return current_root;

	if (comparator(key, current_root -> key))
		current_root -> left = recursive_insert(key, current_root -> left);
	else 
		current_root -> right = recursive_insert(key, current_root -> right);

	//Балансирует, поднимаясь вверх по рекурсии.
	return balance(current_root);
}

template <class Key, class Comparator>
void AVLtree<Key, Comparator>::insert(const Key& key){
	root = recursive_insert(key, root);
}

template <class Key, class Comparator>
void AVLtree<Key, Comparator>::destroy(AvlNode<Key>* node){
	if (node)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

template <class Key, class Comparator>
bool AVLtree<Key, Comparator>::find(const Key& key){
	if (!root) return false;
	AvlNode<Key>* temp_node = root;
	while (temp_node->key != key)
	{
		if (comparator(key, temp_node->key))
			temp_node = temp_node -> left;
		else
			temp_node = temp_node -> right;
		if (!temp_node)
			return false;
	}
	return true;
}

template <class Key, class Comparator>
bool AVLtree<Key, Comparator>::isAVLTree(){
	return recursive_isAVLTree(root);
}

template<class Key, class Comparator>
bool AVLtree<Key, Comparator>::recursive_isAVLTree(AvlNode<Key>* node){
	if (node)
	{
		short delta_balance_of_current_node = node->getDeltaBalanceOfNode();
		if (delta_balance_of_current_node <= 1 || delta_balance_of_current_node >= -1)
		{
			//у текущей вершины выполняется свойство сбалансированности, посчитаем у детей.
			return recursive_isAVLTree(node->left) && recursive_isAVLTree(node->right);
		}
		{
			return false; // если у текущей вершины не выполняется свойство сбалансированности
		}
	}
	else {
		//если у узла только 1 ребенок, то это условие для нулевого ребенка.
		return true;
	}
}
#endif