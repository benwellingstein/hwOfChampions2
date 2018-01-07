
#include "DynamicArray.hpp"


template <class T>
DynamicArray<T>::DynamicArray(int size) : size(size), amountOfData(0) {
	arr = new node*[size];
}

//recieves pointer to data and index of data to insert to.
template <class T>
bool DynamicArray<T>::insert(const T* newGroup,int i) {
	if (exists(newGroup,i)) return false;
	
	node* newNode = new node{newGroup,NULL};
	if (!arr[i]) {
		arr[i] = newNode;
	} else {
		newNode->next = arr[i];
		arr[i] = newNode;
	}
	amountOfData++;
	if (amountOfData >= size) {
		extend();
		return true;
	}
	return false;
}

template <class T>
bool DynamicArray<T>::exists(const T* group, int i) const {
	node* currNode = arr[i];
	while (currNode) {
		if (currNode->data == group) return true;
	}
	return false;
}

template <class T>
T* DynamicArray<T>::getGroup(const T* group, int i) {
	if (!exists(group, i)) return NULL;
	node* currNode = arr[i];
	while (currNode) {
		if (currNode->data == group) return currNode->data;
	}
	assert(false);
	return NULL;
}

//------------------private functions------------------------------------
template <class T>
void DynamicArray<T>::extend(){
	node* newArr[] = new node*[size*2 + 1];
	for (int i=0; i < size; ++i) {
		newArr[i] = arr[i];
	}
	delete arr;
	arr = newArr;
}
