#include <assert.h>
#include <iostream>
#include "MinHeap.hpp"
#include "unitTests.h"

using std::endl;
using std::cout;

void testMakeHeap() {
	int arr[] = {1,2,3,4,5};
	void* result[5];
	MinHeap h(5, arr, result);
	ASSERT_EQUALS(h.head->val, 1);
	ASSERT_EQUALS(h.head->left->val, 2);
	ASSERT_EQUALS(h.head->right->val, 3);
	ASSERT_EQUALS(h.head->left->left->val, 4);
	ASSERT_EQUALS(h.head->left->right->val, 5);

	ASSERT_EQUALS(h.head,(HeapNode*)result[0]);
	ASSERT_EQUALS(h.head->left,(HeapNode*)result[1]);
	ASSERT_EQUALS(h.head->right,(HeapNode*)result[2]);
	ASSERT_EQUALS(h.head->left->left,(HeapNode*)result[3]);
	ASSERT_EQUALS(h.head->left->right,(HeapNode*)result[4]);

	ASSERT_EQUALS(h.head->father,NULL);
	ASSERT_EQUALS(h.head->left->father,(HeapNode*)result[0]);
	ASSERT_EQUALS(h.head->right->father,(HeapNode*)result[0]);

}

void testSiftDown() {
	int arr[] = {5,4,3,2,1};
	void* result[5];
	MinHeap h(5, arr, result);
	ASSERT_EQUALS(h.head->val, 1);
	ASSERT_EQUALS(h.head->left->val, 2);
	ASSERT_EQUALS(h.head->left->left->val, 5);
	ASSERT_EQUALS(h.head->left->right->val, 4);
	ASSERT_EQUALS(h.head->right->val, 3);
}


void testInsert() {
	int arr[] = {1,2,3,4,5};
	void* result[5];
	MinHeap h(5, arr, result);
	ASSERT_EQUALS(110, h.getNextDirections(1));
	h.insert(100);
	ASSERT_EQUALS(h.head->right->left->val, 100);
	ASSERT_EQUALS(h.head->right->left->father->val, 3);

	
	int arr2[] = {1,2,3,4,5,6,7,8,9,10};
	void* result2[10];
	MinHeap h2(10, arr2, result2);
	ASSERT_EQUALS(1011, h2.getNextDirections(1));
	h2.insert(100);
	ASSERT_EQUALS(h2.head->left->right->right->val, 100);
}



void testDecKey() {
	int arr[] = {1,2,3,4,5};
	void* result[5];
	MinHeap h(5, arr, result);
	//if new value is larger or equal dont change
	h.decKey(result[4], 100);
	ASSERT_EQUALS(h.head->val, 1);
	ASSERT_EQUALS(h.head->left->val, 2);
	ASSERT_EQUALS(h.head->right->val, 3);
	ASSERT_EQUALS(h.head->left->left->val, 4);
	ASSERT_EQUALS(h.head->left->right->val, 5);

	h.decKey(result[3], 4);
	ASSERT_EQUALS(h.head->val, 1);
	ASSERT_EQUALS(h.head->left->val, 2);
	ASSERT_EQUALS(h.head->right->val, 3);
	ASSERT_EQUALS(h.head->left->left->val, 4);
	ASSERT_EQUALS(h.head->left->right->val, 5);

	/*expect
	 *			0
	 *		1		3
	 *	 4	  2
	 */
	h.decKey(result[4], 0);
	ASSERT_EQUALS(h.head->val, 0);
	ASSERT_EQUALS(h.head->left->val, 1);
	ASSERT_EQUALS(h.head->right->val, 3);
	ASSERT_EQUALS(h.head->left->left->val, 4);
	ASSERT_EQUALS(h.head->left->right->val, 2);

	int arr2[] = {1,100};
	void* result2[2];
	MinHeap h2(2, arr2, result2);
	
	h2.decKey(result2[1], 40);
	ASSERT_EQUALS(h2.head->val, 1);
	ASSERT_EQUALS(h2.head->left->val, 40);
	
	h2.decKey(result2[1], 0);
	ASSERT_EQUALS(h2.head->val, 0);
	ASSERT_EQUALS(h2.head->left->val, 1);
	
}

void testDelMin() {
	int arr[] = {1,2,3,4,5};
	void* result[5];
	MinHeap h(5, arr, result);
	
	//TODO CHECK SIZE!
	h.delMin();
	ASSERT_EQUALS(h.findMin(),2);
	ASSERT_EQUALS(h.head->val, 2);
	ASSERT_EQUALS(h.head->left->val, 4);
	ASSERT_EQUALS(h.head->right->val, 3);
	ASSERT_EQUALS(h.head->left->left->val, 5);
	h.delMin();
	ASSERT_EQUALS(h.findMin(),3);
	ASSERT_EQUALS(h.head->val, 3);
	ASSERT_EQUALS(h.head->left->val, 4);
	ASSERT_EQUALS(h.head->right->val, 5);
	h.delMin();
	ASSERT_EQUALS(h.findMin(),4);
	ASSERT_EQUALS(h.head->val, 4);
	ASSERT_EQUALS(h.head->left->val, 5);
	h.delMin();
	ASSERT_EQUALS(h.findMin(),5);
	ASSERT_EQUALS(h.head->left, NULL);
	ASSERT_EQUALS(h.head->right, NULL);

	
}


int main() {
	cout << "-------MIN HEAP TESTS-----------" << endl;
	RUN_TEST(testMakeHeap);
	RUN_TEST(testSiftDown);
	RUN_TEST(testInsert);
	RUN_TEST(testDecKey);
	RUN_TEST(testDelMin);
	return 0;
}



