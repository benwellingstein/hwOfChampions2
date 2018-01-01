#ifndef MinHeap_hpp
#define MinHeap_hpp

#include <stdio.h>


//TODO after testing move back to private
struct HeapNode {
	int val;
	HeapNode* left;
	HeapNode* right;
	HeapNode* father;
};

class MinHeap {
public:
	//will return array of void pointers to new nodes
	MinHeap(int n, int* data, void** pointers);
	~MinHeap();
	
	void* insert(int x);
	void decKey(void* p, int x);
	void delMin();
	int findMin() const;
	
	//TODO after testing move back to private
	HeapNode* head;
	
	//TODO after testing move back to private
	//size->binary (without leading one)
	//run with 1 to get next node, 0 to get last node
	long long getNextDirections(int option);
	
	
	//TODO after testing move back to private
	void* insertNode(int x, HeapNode* currNode, long long directions);
	
private:
	
	int size;
	
	void siftDown(HeapNode* node);

	void siftUp(HeapNode* node);
	
	void createHeap(HeapNode** loc, int n, int* data, int i, void** p);
	void connectFathers(HeapNode* node);

	void siftHeap(HeapNode* node);
	
	HeapNode* findSiftDownNode(HeapNode* node);
	
	void swapNodes(HeapNode* father, HeapNode* son);
	void swapRight(HeapNode* father);
	void swapLeft(HeapNode* father);
	
	void* insertNode(int x, HeapNode* currNode, long long directions,
					 int dLen, int currDig);
	
	bool chooseDirection(long long directions, int currDig,int totalDig);
	int getDig(long long directions, int currDig, int totalDig);
	int len(long long d);

	
	HeapNode* getLastNode();
	HeapNode* findLastNode(HeapNode* node, long long directions,
					   int lenD, int currD);
	
	void switchPlaces(HeapNode* head, HeapNode* node);
	void deleteNodes(HeapNode* node);
};

#endif /* MinHeap_hpp */
