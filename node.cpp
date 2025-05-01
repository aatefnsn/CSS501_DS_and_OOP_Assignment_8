#include "pch.h"
#include "node.h"

template <class T>
node<T>::node() {
	this->data = nullptr;
	//this->nodesVector = vector <node <T>>; 
	/*this->left = nullptr;
	this->right = nullptr;*/
}

template <class T>
node<T>::node(T data) {

	this->data = data;
	/*this->left = nullptr;
	this->right = nullptr;*/
}

//template <class T>
//node<T>::node(T data, node* l, node * r) {
//	this->data = data;
//	this->left = l;
//	this->right = r;
//}

template <class T>
T node<T>::getData() {
	return this->data;
}

//template <class T>


//template <class T>
//node * node<T>::getRight() {
//
//}

template <class T>
void node<T>::setData(T data) {
	this->data = data;
}

//template <class T>
//void node<T>::setLeft(node * left) {
//	this->left = left;
//}
//
//template <class T>
//void node<T>::setRight(node * right) {
//	this->right = right;
//}
