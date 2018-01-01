#include "MinHeap.hpp"
#include <cassert>

//------------------------PUBLIC FUNCTIONS-------------------------

MinHeap::MinHeap(int n,int* arr, void** res) : size(0) {
	createHeap(&head, n, arr, 0, res);
	connectFathers(head);
	siftHeap(head);
}

void* MinHeap::insert(int x) {
	long long directions = getNextDirections(1);
	return insertNode(x, head, directions, len(directions), 2);
}

void MinHeap::decKey(void* p, int x) {
	if (!p) return;
	if ( ((HeapNode*)p)->val > x) {
		((HeapNode*)p)->val = x;
		siftUp((HeapNode*)p);
	}
}

void MinHeap::delMin(){
	if (!head) return;
	HeapNode* lastNode = getLastNode();
	HeapNode* oldHead = head;
	switchPlaces(head, lastNode);
	if (oldHead->father->left == oldHead)	oldHead->father->left = NULL;
	else 									oldHead->father->right = NULL;
	
	delete oldHead;
	size--;
	siftDown(head);
}

int MinHeap::findMin() const{
	if (head) return head->val;
	return -1;
}

MinHeap::~MinHeap() {
	deleteNodes(head);
}

//------------------------PRIVATE FUNCTIONS-------------------------

void MinHeap::siftDown(HeapNode* node) {
	if ( node && ( (node->left) || (node->right) ) ) {
		HeapNode* nodeToSwap = findSiftDownNode(node);
		swapNodes(node, nodeToSwap);
		if (nodeToSwap) siftDown(node);
	}
}

void MinHeap::siftUp(HeapNode* node) {
	if (node != head) {
		if (node->val < node->father->val){
			swapNodes(node->father, node);
			siftUp(node);
		}
	}
}

void MinHeap::createHeap(HeapNode** loc, int n, int* data, int i, void** p) {
	if (i < n){
		*loc = new HeapNode{data[i],NULL,NULL,NULL};
		*(((HeapNode**)p)+i) = *loc;
		size++;
		createHeap(&(*loc)->left ,n, data, 2*i+1, p);
		createHeap(&(*loc)->right, n, data, 2*i+2, p);
	}
}


void MinHeap::siftHeap(HeapNode* node){
	if ( node && ( (node->left) || (node->right) ) ) {
		siftHeap(node->left);
		siftHeap(node->right);
		siftDown(node);
	}
}

HeapNode* MinHeap::findSiftDownNode(HeapNode* node) {
	if (!node || (!node->left && !node->right)) return NULL;
	
	//only left exists - return left node if father is larger
	if (!node->right) return node->val > node->left->val ? node->left : NULL;

	//only right exists
	if (!node->left) return node->val > node->right->val ? node->right : NULL;
	
	//both exist if father is larger than sons
	if (node->val > node->right->val || node->val > node->right->val) {
		return node->right->val > node->left->val ? node->left : node->right;
	}
	return NULL;
}


void MinHeap::swapNodes(HeapNode* father, HeapNode* son) {
	if (father && son) {
		if (father->left == son) 	swapLeft(father);
		if (father->right == son ) 	swapRight(father);
	}
}


void MinHeap::swapRight(HeapNode* father) {

	if (!father || !father->right) return;
	
	HeapNode* gFather = father->father;
	HeapNode* rightSon = father->right;
	HeapNode* rightSonL = rightSon->left;
	HeapNode* rightSonR = rightSon->right;
	HeapNode* fatherL = father->left;
	
	father->father = rightSon;
	rightSon->right = father;
	
	rightSon->left = fatherL;
	if (fatherL) fatherL->father = rightSon;
	
	father->left = rightSonL;
	if (rightSonL) rightSonL->father = father;

	father->right = rightSonR;
	if (rightSonR) rightSonR->father = father;
	
	rightSon->father = gFather;
	if (!gFather) head = rightSon;
	else if (gFather->left == father) gFather->left = rightSon;
	else 							  gFather->right = rightSon;
}


void MinHeap::swapLeft(HeapNode* father) {
	if (!father || !father->left) return;
	
	HeapNode* gFather = father->father;
	HeapNode* leftSon = father->left;
	HeapNode* leftSonL = leftSon->left;
	HeapNode* leftSonR = leftSon->right;
	HeapNode* fatherR = father->right;
	
	father->father = leftSon;
	leftSon->left = father;
	
	leftSon->right = fatherR;
	if (fatherR) fatherR->father = leftSon;

	father->left = leftSonL;
	if (leftSonL) leftSonL->father = father;

	father->right = leftSonR;
	if (leftSonR) leftSonR->father = father;
	
	leftSon->father = gFather;
	if (!gFather) head = leftSon;
	else if (gFather->left == father) gFather->left = leftSon;
	else 							  gFather->right = leftSon;
}


void MinHeap::connectFathers(HeapNode* node) {
	if (node) {
		if (node == head) 	node->father = NULL;
		if (node->left) {
			node->left->father = node;
			connectFathers(node->left);
		}
		if (node->right) {
			node->right->father = node;
			connectFathers(node->right);
		}
	}
}


long long MinHeap::getNextDirections(int option) {
	assert(option==0 || option==1);
	long long binary = 0;
	int decimal = size + option;
	int i = 1;
	int remainder;
	
	while (decimal!=0)
	{
		remainder = decimal%2;
		decimal /= 2;
		binary += remainder*i;
		i *= 10;
	}
	return binary;
}


void* MinHeap::insertNode(int x, HeapNode* currNode, long long directions,
						  int dLen, int currDig) {
	
	if (currDig < dLen) {
		return chooseDirection(directions, currDig, dLen) ?
		insertNode(x, currNode->left, directions, dLen, currDig+1) :
		insertNode(x, currNode->right, directions, dLen, currDig+1);
	}
	
	HeapNode* newNode = new HeapNode{x,NULL,NULL,currNode};
	size++;
	if (head == NULL) {
		head = newNode;
	} else {
		if (getDig(directions, currDig, dLen) == 0) currNode->left = newNode;
		else 										currNode->right = newNode;
	}
	return newNode;
}

//true left, false right
bool MinHeap::chooseDirection(long long directions, int currDig,int totalDig) {
	return (getDig(directions,currDig,totalDig) == 0) ;
}

int MinHeap::getDig(long long directions, int currDig, int totalDig) {
	for (int i = 0 ; i< totalDig-currDig ; ++i) {
		directions/=10;
	}
	return directions % 10;
}


int MinHeap::len(long long d) {
	int counter = 0;
	while (d) {
		counter++;
		d/=10;
	}
	return counter;
}

//-----------delMin functions--------------------

HeapNode* MinHeap::getLastNode() {
	long long directions = getNextDirections(0);
	return findLastNode(head, directions, len(directions), 2);
}

HeapNode* MinHeap::findLastNode(HeapNode* node, long long directions, int lenD, int currD) {
	if (currD < lenD)
		return chooseDirection(directions, currD, lenD) ?
			findLastNode(node->left, directions, lenD, currD + 1) :
			findLastNode(node->right, directions, lenD, currD + 1);
	if (chooseDirection(directions, currD, lenD)) {
		return node->left;
	} else {
		return node->right;
	}
}

void MinHeap::switchPlaces(HeapNode* oldHead, HeapNode* node){
	HeapNode* headL = oldHead->left;
	HeapNode* headR = oldHead->right;
	HeapNode* nodeFather = node->father;
	
	//if simple rotation - do so and return
	if (headR == node || headL == node) {
		swapNodes(oldHead, node);
		return;
	}
	
	head = node;
	node->father = NULL;
	
	node->right = headR;
	if (headR) headR->father = node;
	
	node->left = headL;
	if (headL) headL->father = node;
	
	if (nodeFather->right == node) 		nodeFather->right = oldHead;
	else						 		nodeFather->left = oldHead;

	oldHead->father = nodeFather;
	oldHead->left = NULL;
	oldHead->right = NULL;
	
}

//-----------D'Tor functions--------------------

void MinHeap::deleteNodes(HeapNode* node) {
	if (!node) return;
	deleteNodes(node->left);
	deleteNodes(node->right);
	node->val = -1;
	node->left = NULL;
	node->right = NULL;
	delete node;
}





