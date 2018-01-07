
#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <stdio.h>
#include <assert.h>


template <class T>
class DynamicArray {
public:
	explicit DynamicArray(int size) : size(size), amountOfData(0) {
		arr = new node*[size];
		for (int i=0; i < size; ++i) 	arr[i] = NULL;
	};
	
	//recieves pointer to data and index of data to insert to.
	bool insert(T* newGroup,int i) {
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
	
	bool exists(const T* group, int i) const{
		node* currNode = arr[i];
		while (currNode) {
			if (currNode->data == group) return true;
			currNode = currNode->next;
		}
		return false;
	}
	
	T* getGroup(const T* group, int i)  {
		if (!exists(group, i)) return NULL;
		node* currNode = arr[i];
		while (currNode) {
			if (currNode->data == group) return currNode->data;
			currNode = currNode->next;
		}
		assert(false);
		return NULL;
	}
	
private:
	
	struct node {
		T* data;
		node* next;
	};
	
	
	void extend(){
	
		int newSize = size*2+1;
		node** newArr = new node*[newSize];
		for (int i=0; i < size; ++i) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		size = newSize;
	}
	int size;
	int amountOfData;
	node** arr;
};


#endif /* DynamicArray_hpp */
