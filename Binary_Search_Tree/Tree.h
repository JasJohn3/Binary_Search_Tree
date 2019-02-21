#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include<exception>
class invalid_argument;
template<typename Type>
struct NODE
{
	Type Data;
	NODE*Left; 
	NODE*Right;
	NODE*Parent;
	//constructor of the struct NODE
	NODE()
	{
		NODE* Left = nullptr;
		NODE* Right = nullptr;
		NODE* Parent = nullptr;
	}

};

template<typename Type>
class Tree
{
public:
	Tree();
	NODE<Type>* Insert(struct NODE<Type> * root, Type Value);
	NODE<Type>*Find(Type Value);
	NODE<Type>*FindMax(NODE<Type>* root);
	NODE<Type>*FindMin(NODE<Type>* root);
	NODE<Type>* Inorder(struct NODE<Type>* root);

	~Tree();

private:
	NODE<Type>* root;
	
};

template<typename Type>
Tree<Type>::Tree()
{
	NODE<Type>* root = nullptr;
}
template<typename Type>
NODE<Type>* Insert(struct NODE<Type> * root,Type Value)
{
	//Create a new Node if the value is Null
	if (root == nullptr)
	{
		//creating a new NODE, the NODE constructor should assign the pointer values
		root = new NODE<Type>();
		//assigning the value to the temp NODE.
		root->Data = Value;
	}
	//if the value is less than current data, traverse left
	else if (Value < root->Data)
	{
		root->Parent = root;
		root->Left = Insert(root->Left, Value);
	}
	//if the value is less than current data, traverse Right
	else if (Value > root->Data)
	{
		root->Parent = root;
		root->Right = Insert(root->Right, Value);
	}
	return root;

}
template<typename Type>
NODE<Type>*Find(NODE<Type>* root,Type Value)
{
	//traverse left if value is less than current nodes value
	if (Value < root->Data)
	{
		root->Left = root;
	}
	//travers right if value is greater than current nodes value
	else if (Value > root->Data)
	{
		root->Right = root;
	}
	//if no value matches and a nullptr is found, inform the user that there is no value that matches in the list
	else if (root->Right == nullptr || root->Left == nullptr)
	{
		std::cout << "No Matching values were found inside of the tree!" << std::endl;
	}
	else
	{
		
	}
	return root;
}
template<typename Type>
NODE<Type>*FindMax(NODE<Type>* root)
{
	while (root->Right != nullptr)
	{
		root = root->Right;
	}
		
	return root;
}
template<typename Type>
NODE<Type>*FindMin(NODE<Type>* root)
{
	while (root->Left != nullptr)
	{
		root = root->Left;
	}
	return root;
}
template<typename Type>
NODE<Type>* Inorder(struct NODE<Type>* root)
{
	if (root == nullptr) return;
	//Recursive call left and right and display the Data
	Inorder(root->Left);
	std::cout << "Value stored is: " << root->Data << std::endl;
	Inorder(root->Right);

	return root;
}
template<typename Type>
Tree<Type>::~Tree()
{

}
#endif // !TREE_H