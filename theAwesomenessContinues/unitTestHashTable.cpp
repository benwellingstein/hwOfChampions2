#include <assert.h>
#include <iostream>
#include "TrainingHashTable.hpp"
#include "DynamicArray.hpp"
#include "Hash.hpp"

#include "unitTests.h"

using std::endl;
using std::cout;

void testCreate() {
	int arr[] = {1,2,3};
	void* nullArr[3] = {NULL, NULL, NULL};
	TrainingHashTable ht(3,arr,nullArr);
}

void testInsert() {
	int arr[] = {1,2,3};
	void* nullArr[3] = {NULL, NULL, NULL};
	TrainingHashTable ht(3,arr,nullArr);
	ht.insert(4, NULL);
	
	
}

//void testInsert() {
//
//}



int main() {
	cout << "-------MIN HEAP TESTS-----------" << endl;
	RUN_TEST(testCreate);
	RUN_TEST(testInsert);

	return 0;
}




