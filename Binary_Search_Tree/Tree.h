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
	NODE<Type>* Insert(NODE<Type>* Current_Node,Type Value);
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
NODE<Type> Insert(NODE<Type> * root,Type Value)
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
		root->Left=Insert(root->Left,Value)
	}
	else if (Value > root->Data)
	{
		root->Parent = root;
		root->Right = Insert(root->Right, Value)
	}

}
template<typename Type>
NODE<Type>*Find(Type Value)
{
	NODE<Type>*current = root;
	//traverse left if value is less than current nodes value
	if (Value < current->Data)
	{
		current->Left = current;
	}
	//travers right if value is greater than current nodes value
	else if (Value > current->Data)
	{
		current->Right = current;
	}
	//if no value matches and a nullptr is found, inform the user that there is no value that matches in the list
	else if (current->Right == nullptr || current->Left == nullptr)
	{
		std::cout << "No Matching values were found inside of the tree!"
	}
	else
	{
		
	}
	return current;
}
template<typename Type>
NODE<Type>*FindMax(NODE<Type>* root)
{
	while (root->Right != nullptr)root = root->Right;
	return root;

}
template<typename Type>
NODE<Type>*FindMin(NODE<Type>* root)
{
	while (root->Left != nullptr)root = root->Left;
	return root;
}
template<typename Type>
void Inorder(NODE<Type>* root)
{
	if (root == nullptr) return;
	//Recursive call left and right and display the Data
	Inorder(root->Left);
	std::cout << "Value stored is: " << root->Data << std::endl;
	Inorder(root->Right);

}
template<typename Type>
Tree<Type>::~Tree()
{

}
#endif // !TREE_H