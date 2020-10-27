//evitam includerea bibliotecilor de mai multe ori
#pragma once 

#include <iostream>
#include<string>
#include<memory>

using namespace std;


/*
Structura unui nod din arborele binar
*/
class node
{
private:

	int data; // cheia nodului

	//variable de tip pointer-to-node pentru a retine adresa urmatoarelor 2 noduri
	shared_ptr<node> left; //nodul din stanga 
	shared_ptr<node> right;//nodul din dreapta

	
public:
	int getData();
	void setData(int newData);

	shared_ptr<node> getLeft();
	shared_ptr<node> getRight();

	void setLeft(shared_ptr<node> newLeftNode);
	void setRight(shared_ptr<node> newRightNode);
	

	shared_ptr<node> returnTheRightNode(shared_ptr<node> actual) { return actual->getRight(); }
	shared_ptr<node> returnTheLeftNode(shared_ptr<node> actual) { return actual->getLeft(); }
	
	//constructor pentru initializarea variabileleor cu 0  si null in cazul crearii unui nod.
	node()
	{
        this->data = 0;
		this->left = nullptr;
		this->right = nullptr;

	}
	
};


int node::getData()
{
	return this->data;
}


void node::setData(int newData)
{
	this->data = newData;
}



shared_ptr<node> node::getLeft()
{

	return this->left;
}

shared_ptr<node> node::getRight()
{
	return this->right;

}



void node::setLeft(shared_ptr<node> newLeftNode)
{
	this->left = newLeftNode;
}



void node::setRight(shared_ptr<node> newRightNode)
{
	this->right = newRightNode;
}
