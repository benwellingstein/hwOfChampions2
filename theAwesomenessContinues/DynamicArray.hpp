//
//  DynamicArray.hpp
//  theAwesomenessContinues
//
//  Created by Ben on 03/01/2018.
//  Copyright © 2018 Ben. All rights reserved.
//

#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <stdio.h>



template <class T>
class DynamicArray {
	
public:
	//recieves pointer to data and index of data to insert to.
	void insert(const T* newGroup,int i);
	bool exists(const T* group, int i) const;
	T* getGroup(const T* group, int i) ;
private:
	int size;
	int amountOfData;
	T* arr;
};

#endif /* DynamicArray_hpp */
