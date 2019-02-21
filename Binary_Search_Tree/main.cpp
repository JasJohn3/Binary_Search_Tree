#include "Tree.h"
#include <iostream>

int main()
{

	Tree<int> Binary_Search_Tree;
	NODE<int>* root = nullptr;
	Binary_Search_Tree.Insert(root,10);
	Binary_Search_Tree.Insert(root, 8);
	Binary_Search_Tree.Insert(root, 12);
	Binary_Search_Tree.Insert(root, 11);
	Binary_Search_Tree.Insert(root, 9);
	Binary_Search_Tree.Inorder(root);

	return 0;
}