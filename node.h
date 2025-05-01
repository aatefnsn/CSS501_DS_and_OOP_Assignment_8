#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
class node {
private:
	T data;
	//vector < node <T>> nodesVector; 
	/*node * left;
	node * right;*/
public:

	node();
	node(T data);
	//node(T data, node* l, node * r);
	T getData();
	/*node * getLeft() {
		return this->left;
	}
	node * getRight() {
		return this->right;
	}*/
	void setData(T data);
	/*void setLeft(node * left);
	void setRight(node * right);*/
};
