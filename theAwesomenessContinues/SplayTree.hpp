#ifndef SplayTree_hpp
#define SplayTree_hpp

#include <stdio.h>
#include <iostream>
#include <assert.h>

using std::cout;
using std::ostream;
using std::endl;


class SplayTree {
private:
	struct Node {
		Node(int data, Node* father = NULL, Node* left = NULL, Node* right =
             NULL): data(data), father(father), lChild(left), rChild(right), sumOfNodes(data), numOfNodes(1), repetitions(1) {}
		
		
		bool operator<(const Node& other) const {
			return data < other.data;
		}
		
		bool operator==(const Node& other) const {
			return data == other.data;
		}
		
		bool operator!=(const Node& other) const {
			return !(*this == other);
		}
		

		
		
        int totalValue() {
            return sumOfNodes;
        }
		
		//helper print function for debugging
        ostream& print(ostream& os) const {
			os  << data << " ";
			return os;
		}
		
		int data;
		Node* father;
		Node* lChild;
		Node* rChild;
        int sumOfNodes;
        int numOfNodes;
        int repetitions;
	};
	
	/*Each tree will keep a pointer to its head node and a pointer to the
	 * node with the highest value that will update accordingly
	 */
	Node* head;
	Node* top;
	
public:
    SplayTree(Node* root = NULL): head(root), top(NULL) {}
    ~SplayTree() {
		inOrderRecDestroy(head);
		head = NULL;
		top = NULL;
	}
	
//------------------- Classic splay tree functions ------------------
	
//
//    //splay tree remove function
//    bool remove(int val) {
//        if(!exist(val)) return false;
//        splay(val);
//        if (!head->lChild && !head->rChild) {
//            delete head->data;
//            delete head;
//            head = NULL;
//            top = NULL;
//            return true;
//        }
//        if (!head->lChild) {
//            Node* oldHead = head;
//            head = head->rChild;
//            head->father = NULL;
//            delete oldHead->data;
//            delete oldHead;
//        } else
//            if (!head->rChild) {
//                Node* oldHead = head;
//                head = head->lChild;
//                head->father = NULL;
//                delete oldHead->data;
//                delete oldHead;
//            } else {
//                Node* lMax = findMax(head->lChild);
//                SplayTree tempTree(head->lChild);
//
//                tempTree.head->father = NULL;
//                tempTree.splay(*(lMax->data));
//                Node* oldHead = head;
//                head = tempTree.head;
//                head->rChild = oldHead->rChild;
//                head->father = NULL;
//                delete oldHead->data;
//                delete oldHead;
//                head->rChild->father = head;
//                tempTree.head = NULL;
//            }
//        top = findMax(head);
//        return true;
//    }

	//splay tree insert function
    bool insert(int val) {
		if (!head) {
            Node* newNode = new Node(val);
			head = newNode;
			top = head;
			return true;
		}
        find(val);
        if(head->data == val) {
            head->repetitions += 1;
            head->sumOfNodes += val;
            head->numOfNodes += 1;
            return true;
        }
		//if(exist(*val)) return false;
        Node* newNode = new Node(val);
		if( val < (head->data) ) {
			Node* oldHead = head;
			newNode->rChild = oldHead;
			newNode->lChild = oldHead->lChild;

            newNode->sumOfNodes = oldHead->sumOfNodes + val;
            newNode->numOfNodes = oldHead->numOfNodes + 1;
            oldHead->sumOfNodes = oldHead->data;
            oldHead->numOfNodes = 1;

			oldHead->father = newNode;
			
			if(oldHead->lChild) {
				oldHead->lChild->father = newNode;
				oldHead->lChild = NULL;
			}
            if(oldHead->rChild) {
                oldHead->sumOfNodes += oldHead->rChild->sumOfNodes;
                oldHead->numOfNodes += oldHead->rChild->numOfNodes;
            }
			newNode->father = NULL;
			head = newNode;
			
		} else {
			Node* oldHead = head;
			newNode->lChild = oldHead;
			newNode->rChild = oldHead->rChild;
			oldHead->father = newNode;
            newNode->numOfNodes = oldHead->numOfNodes + 1;
            newNode->sumOfNodes = oldHead->sumOfNodes + val;
            oldHead->sumOfNodes = oldHead->data;
            oldHead->numOfNodes = 1;
            
			if (oldHead->rChild) {
                //newNode->numOfNodes -= oldHead->rChild->numOfNodes;
                //newNode->sumOfNodes -= oldHead->rChild->sumOfNodes;
                
				oldHead->rChild->father = newNode;
				oldHead->rChild = NULL;
			}
            if(oldHead->lChild) {
                oldHead->sumOfNodes += oldHead->lChild->sumOfNodes;
                oldHead->numOfNodes += oldHead->lChild->numOfNodes;
            }
            
			head = newNode;
			if (top && (top->data) < val) top = newNode;
			
		}
		
		return true;
	}
    
    int totalNumberOfNodes() {
        if (head==NULL) return 0;
        return head->numOfNodes;
    }
    
    int totalTreeValue() {
        if (head==NULL) return -1;
        return head->sumOfNodes;
    }
    
    
    
    
   //splay tree find max function
	static Node* findMax(Node* top) {
		if(top == NULL) return NULL;
		Node* current = top;
		Node* next = current->rChild;
		while(next != NULL) {
			current = next;
			next = current->rChild;
		}
		return current;
	}
	
	//splay tree find function
	int find(int val) {
		if (!head)  return NULL;
		Node* current = head;
		Node* next = findNext(current, val);
		while(next != NULL && current != next) {
			current = next;
			next = findNext(current, val);
		}
		splay((current->data));
		
		if (next != NULL) {
			return current->data;
		}
		
		return NULL;
	}
	
    int sumOfBestN(int numberOfNodes) {
		if (!head) return -1;
        if( head->numOfNodes < numberOfNodes) return -1;
        if( head->numOfNodes == numberOfNodes) return head->sumOfNodes;
        Node* current = head;
        bool done = false;
        int nodesLeft = numberOfNodes;
        int sum = 0;
        while (!done) {
            if(current->rChild) {
                if(current->rChild->numOfNodes > nodesLeft) {
                    current = current->rChild;
                    continue;
                }
                if(current->rChild->numOfNodes == nodesLeft) return current->rChild->sumOfNodes + sum;
                if(current->rChild->numOfNodes >= nodesLeft - current->repetitions) return current->rChild->sumOfNodes + current->data * (nodesLeft - current->rChild->numOfNodes) + sum;
                
                sum += current->rChild->sumOfNodes + current->data * current->repetitions;
                nodesLeft -= current->rChild->numOfNodes + current->rChild->repetitions;
                current = current->lChild;
                continue;
            }
            if(nodesLeft == 1) return current->data * current->repetitions + sum;

            sum += current->data * current->repetitions;
            nodesLeft -= current->repetitions;
            current = current->lChild;
        }
        return 0;
    }
    
	//splay function
	void splay(int val) {
		if (!exist(val)) return;
		Node* current = head;
		Node* father = NULL;
		Node* grandFather = NULL;
		Node* greatGrandFather = NULL;
		while( (current->data) != val ) {
			greatGrandFather = grandFather;
			grandFather = father;
			father = current;
			current = findNext(current, val);
		}
		if(grandFather != NULL) {
			//case3
			Node** pGrandFather = NULL;
			do{
				if (grandFather->father == NULL) {
					pGrandFather = &head;
				} else {
					pGrandFather = findDirection(greatGrandFather, grandFather);
				}
				
				switch (findOrder(grandFather, father, current)) {
					case LL:
						ZigZigLL(pGrandFather, grandFather, father, current);
						break;
					case LR:
						ZigZagLR(pGrandFather, grandFather, father, current);
						break;
					case RL:
						ZigZagRL(pGrandFather, grandFather, father, current);
						break;
					case RR:
						ZigZigRR(pGrandFather, grandFather, father, current);
						break;
				}
				
				father = current->father;
				if(father != NULL) {
					grandFather = father->father;
					if (grandFather != NULL) {
						greatGrandFather = grandFather->father;
					}
				}
			} while ( current != head && current->father != head );
		}
		//case2
		if(head != current) {
			if ((father->data) < val)  {
				ZigR(&head, father, current);
				return;
			} else {
				ZigL(&head, father, current);
				return;
			}
		}
	}
	
	
//--------------- Added functionality for splay tree -------------
	
	/* Updates tree basd upon update function
	 * the function will run on the data inside a node and _LIBCPP_INVOKE_RETURN
	 * a boolean value to indicate if the data was treated
	 */
//	void update(UpdateFunction updateFunction) {
//		int arraySize = size();
//		T** arrOriginal = new T*[arraySize + 1]();
//		T** arrChanged = new T*[arraySize + 1]();
//		T** arrNotChanged = new T*[arraySize + 1]();
//		T** arrFinal = new T*[arraySize + 1]();
//		
//		for (int i = 0; i < arraySize; i++) {
//			arrOriginal[i] = NULL;
//			arrChanged[i] = NULL;
//			arrNotChanged[i] = NULL;
//			arrFinal[i] = NULL;
//		}
//		
//		getData(arrOriginal);
//		runFunction(arrOriginal, arrChanged, arrNotChanged, updateFunction);
//		mergeSortArrays(arrChanged, arrNotChanged, arrFinal);
//		inOrderRecDestroy(head);
//		head = NULL;
//		top = NULL;
//		buildTreeFromArray(head, arrFinal);
//		delete [] arrOriginal;
//		delete [] arrChanged;
//		delete [] arrNotChanged;
//		delete [] arrFinal;
//	}
	
/*	void update(UpdateFunction updateFunction) {
		int arraySize = size();
		T** arrOriginal = new T*[arraySize + 1]();
		T** arrChanged = new T*[arraySize + 1]();
		T** arrNotChanged = new T*[arraySize + 1]();
		T** arrFinal = new T*[arraySize + 1]();
		
		for (int i = 0; i < arraySize; i++) {
			arrOriginal[i] = NULL;
			arrChanged[i] = NULL;
			arrNotChanged[i] = NULL;
			arrFinal[i] = NULL;
		}
		
		getData(arrOriginal);
		runFunction(arrOriginal, arrChanged, arrNotChanged, updateFunction);
		mergeSortArrays(arrChanged, arrNotChanged, arrFinal);
		inOrderRecDestroy(head);
		head = NULL;
		top = NULL;
		buildTreeFromArray(head, arrFinal);
		delete [] arrOriginal;
		delete [] arrChanged;
		delete [] arrNotChanged;
		delete [] arrFinal;
	}
	*/

	// boolean exists function - searches branch for given value
	bool exist(int val) const {
		if (!head) return false;
		Node* currNode = head;
		while (1) {
			if ( ((*currNode).data) == val ) return true;
			if ( val< ((*currNode).data)) {
				if ( (*currNode).lChild) {
					currNode = currNode->lChild;
				} else {
					return false;
				}
			} else {
				if ((*currNode).rChild) {
					currNode = currNode->rChild;
				} else {
					return false;
				}
			}
		}
	}
	
	/*New functionality of tree - top keeps the highest value in the tree
	 *this function simply returns that value
	 */
	int getTop() {
		if (!top) return NULL;
		return top->data;
	}
	
	
	//used to return pointers to the values in the tree by array
	void exportArr(int* arr) {
		int i = 0;
		recursiveFill(arr, head, &i);
	}
	
	
	//used to count number of nodes in tree
	int size() {
		return countNodes(head);
	}


	//helper function for debugging
	ostream& print(ostream& os) const {
		preOrder(os);
		inOrder(os);
		postOrder(os);
		return os;
	}


private:
	
	//helper function for node counting
	static int countNodes(Node* node) {
		int count = 0;
		if (node) {
			count ++;
			count += countNodes(node->lChild);
			count += countNodes(node->rChild);
		}
		return count;
	}
	
	
	
	//helper function for returning pointers to array
	static void recursiveFill(int* arr, Node* node, int* i) {
		if (node) {
			recursiveFill(arr, node->lChild, i);
			//cout << *i << endl;
			arr[*i] = node->data;
			*i = *i + 1 ;
			recursiveFill(arr, node->rChild, i);
		}
	}
	
	//helper functions to get NEW COPY of data
	void getData(int* arrOriginal) {
		int i=0;
		getDataRec(arrOriginal, head, &i);
	}
	static void getDataRec(int* arr, Node* node, int* i) {
		if (node) {
			getDataRec(arr, node->lChild, i);
			arr[*i] = ((node->data));
			*i = *i + 1 ;
			getDataRec(arr, node->rChild, i);
		}
	}
	
	//splits original into two arrays by update function
//	void runFunction(T** arrOriginal, T** arrChanged,T**  arrNotChanged,
//					 UpdateFunction updateFunction) {
//		int i = 0;
//		int j = 0;
//		for (int k = 0; arrOriginal[k] != NULL; ++k) {
//			if (updateFunction(*arrOriginal[k]))  {
//				arrChanged[i] = arrOriginal[k];
//				i++;
//			} else {
//				arrNotChanged[j] = arrOriginal[k];
//				j++;
//			}
//		}
//	}
//
/*	void runFunction(T** arrOriginal, T** arrChanged,T**  arrNotChanged,
					 UpdateFunction updateFunction) {
		int i = 0;
		int j = 0;
		for (int k = 0; arrOriginal[k] != NULL; ++k) {
			if (updateFunction(*arrOriginal[k]))  {
				arrChanged[i] = arrOriginal[k];
				i++;
			} else {
				arrNotChanged[j] = arrOriginal[k];
				j++;
			}
		}
	}*/
	
	//merges arrays
	void mergeSortArrays(int* arrChanged, int* arrNotChanged, int* arrFinal) {
		int i = 0;
		int j = 0;
		int k = 0;
		while (arrChanged[i] && arrNotChanged[j]) {
			if (arrChanged[i]<  arrNotChanged[j]) {
				arrFinal[k] = arrChanged[i];
				i++;
			} else {
				arrFinal[k] = arrNotChanged[j];
				j++;
			}
			k++;
		}
		while (arrChanged[i]) {
			arrFinal[k] = arrChanged[i];
			i++;
			k++;
		}
		while (arrNotChanged[j]) {
			arrFinal[k] = arrNotChanged[j];
			j++;
			k++;
		}
	}

	//inserts all values of array into tree
	void buildTreeFromArray(Node* head, int* arrFinal) {
		for (int i = 0; arrFinal[i]; ++i ) {
			insert(arrFinal[i]);
		}
	}

	
	//helper function for deleting tree
	void inOrderRecDestroy(Node* node) const {
		if (node) {
			inOrderRecDestroy(node->lChild);
			inOrderRecDestroy(node->rChild);
//            delete node->data;
			delete node;
		}
	}
	
	

	
	//Helps to get the next node in searches - returns same/left/right node
	Node* findNext(Node* checkAgainst, int val) const {
		if ((checkAgainst->data)< val)  	return checkAgainst->rChild;
		if (val < (checkAgainst->data)) 	return checkAgainst->lChild;
		if (val == (checkAgainst->data)) 	return checkAgainst;
		assert(false);
		return NULL;
	}
	
	Node** findDirection(Node* grandFather, Node* father){
		if ((grandFather->data) < (father->data)) {
			return &(grandFather->rChild);
		} else {
			return &(grandFather->lChild);
		}
	}

	
	
	//--------splay tree helper functions----------
	
	static void ZigL(Node** grandFather, Node* father, Node* child) {
        child->sumOfNodes = father->sumOfNodes;
        child->numOfNodes = father->numOfNodes;
        father->sumOfNodes = father->data * father->repetitions;
        father->numOfNodes = father->repetitions;
        
        if (father->rChild) {
            father->sumOfNodes += father->rChild->sumOfNodes;
            father->numOfNodes += father->rChild->numOfNodes;
        }
        
        if (child->rChild) {
            father->sumOfNodes += child->rChild->sumOfNodes;
            father->numOfNodes += child->rChild->numOfNodes;
        }
        
		*grandFather = child;
		father->lChild = child->rChild;
		child->rChild = father;
        child->father = NULL;
        father->father = child;



        if (father->lChild) {
            father->lChild->father = father;
        }

	}
	
	static void ZigR(Node** grandFather, Node* father, Node* child ) {
        child->sumOfNodes = father->sumOfNodes;
        child->numOfNodes = father->numOfNodes;
        father->sumOfNodes = father->data * father->repetitions;
        father->numOfNodes = father->repetitions;
        
        if (father->lChild) {
            father->sumOfNodes += father->lChild->sumOfNodes;
            father->numOfNodes += father->lChild->numOfNodes;
        }
        
        if (child->lChild) {
            father->sumOfNodes += child->lChild->sumOfNodes;
            father->numOfNodes += child->lChild->numOfNodes;
        }
        
		*grandFather = child;
		father->rChild = child->lChild;
		child->lChild = father;
        child->father = NULL;
        father->father = child;

        if (father->rChild) {
            father->rChild->father = father;
        }
        

	}
	
	static void ZigZagLR(Node** greatGrandFather, Node* grandFather,
						 Node* father, Node* child) {
        int totalSum = grandFather->sumOfNodes;
        int totalNum = grandFather->numOfNodes;
        
        grandFather->sumOfNodes = grandFather->data * grandFather->repetitions;
        grandFather->numOfNodes = grandFather->repetitions;
        
        if(grandFather->rChild) {
            grandFather->sumOfNodes += grandFather->rChild->sumOfNodes;
            grandFather->numOfNodes += grandFather->rChild->numOfNodes;
        }
        if(child->rChild) {
            grandFather->sumOfNodes += child->rChild->sumOfNodes;
            grandFather->numOfNodes += child->rChild->numOfNodes;
        }
        
        father->sumOfNodes = father->data * father->repetitions;
        father->numOfNodes = father->repetitions;
        
        if(father->lChild) {
            father->sumOfNodes += father->lChild->sumOfNodes;
            father->numOfNodes += father->lChild->numOfNodes;
        }
        if(child->lChild) {
            father->sumOfNodes += child->lChild->sumOfNodes;
            father->numOfNodes += child->lChild->numOfNodes;
        }
        
        child->sumOfNodes = totalSum;
        child->numOfNodes = totalNum;
        
        
		*greatGrandFather = child;
		father->rChild = child->lChild;
		grandFather->lChild = child->rChild;
		child->lChild = father;
		child->rChild = grandFather;
		if (father->rChild) father->rChild->father = father;
		if (grandFather->lChild) grandFather->lChild->father = grandFather;
		father->father = child;
        child->father = grandFather->father;
        grandFather->father = child;
	}

	static void ZigZagRL(Node** greatGrandFather, Node* grandFather,
						 Node* father, Node* child) {
        int totalSum = grandFather->sumOfNodes;
        int totalNum = grandFather->numOfNodes;
        
        grandFather->sumOfNodes = grandFather->data * grandFather->repetitions;
        grandFather->numOfNodes = grandFather->repetitions;
        
        if(grandFather->lChild) {
            grandFather->sumOfNodes += grandFather->lChild->sumOfNodes;
            grandFather->numOfNodes += grandFather->lChild->numOfNodes;
        }
        if(child->lChild) {
            grandFather->sumOfNodes += child->lChild->sumOfNodes;
            grandFather->numOfNodes += child->lChild->numOfNodes;
        }
        
        father->sumOfNodes = father->data * father->repetitions;
        father->numOfNodes = father->repetitions;
        
        if(father->rChild) {
            father->sumOfNodes += father->rChild->sumOfNodes;
            father->numOfNodes += father->rChild->numOfNodes;
        }
        if(child->rChild) {
            father->sumOfNodes += child->rChild->sumOfNodes;
            father->numOfNodes += child->rChild->numOfNodes;
        }

        child->sumOfNodes = totalSum;
        child->numOfNodes = totalNum;
        
		*greatGrandFather = child;
		father->lChild = child->rChild;
		grandFather->rChild = child->lChild;
		child->rChild = father;
		child->lChild = grandFather;
		if (father->lChild) father->lChild->father = father;
		if (grandFather->rChild) grandFather->rChild->father = grandFather;
        child->father = grandFather->father;
        grandFather->father = child;
        father->father = child;
	}

	static void ZigZigRR(Node** greatGrandFather, Node* grandFather,
						  Node* father, Node* child) {
        int totalSum = grandFather->sumOfNodes;
        int totalNum = grandFather->numOfNodes;
        
        grandFather->sumOfNodes = grandFather->data * grandFather->repetitions;
        grandFather->numOfNodes = grandFather->repetitions;
        
        if(father->lChild) {
            grandFather->sumOfNodes += father->lChild->sumOfNodes;
            grandFather->numOfNodes += father->lChild->numOfNodes;
        }
        
        if(grandFather->lChild) {
            grandFather->sumOfNodes += grandFather->lChild->sumOfNodes;
            grandFather->numOfNodes += grandFather->lChild->numOfNodes;
        }
        
        father->sumOfNodes = father->data * father->repetitions + grandFather->sumOfNodes;
        father->numOfNodes = father->repetitions + grandFather->numOfNodes;
        
        if(child->lChild) {
            father->sumOfNodes += child->lChild->sumOfNodes;
            father->numOfNodes += child->lChild->numOfNodes;
        }
        
        child->sumOfNodes = totalSum;
        child->numOfNodes = totalNum;
        
		*greatGrandFather = child;
		grandFather->rChild = father->lChild;
		father->rChild = child->lChild;
		child->lChild = father;
		father->lChild = grandFather;
        child->father = grandFather->father;
        grandFather->father = father;
        father->father = child;
		if (father->rChild) father->rChild->father = father;
		if (grandFather->rChild) grandFather->rChild->father = grandFather;
		

	}
	
	static void ZigZigLL(Node** greatGrandFather, Node* grandFather,
						  Node* father, Node* child) {
        int totalSum = grandFather->sumOfNodes;
        int totalNum = grandFather->numOfNodes;
        
        grandFather->sumOfNodes = grandFather->data * grandFather->repetitions;
        grandFather->numOfNodes = grandFather->repetitions;
        
        if(father->rChild) {
            grandFather->sumOfNodes += father->rChild->sumOfNodes;
            grandFather->numOfNodes += father->rChild->numOfNodes;
        }
        
        if(grandFather->rChild) {
            grandFather->sumOfNodes += grandFather->rChild->sumOfNodes;
            grandFather->numOfNodes += grandFather->rChild->numOfNodes;
        }
        
        father->sumOfNodes = father->data * father->repetitions + grandFather->sumOfNodes;
        father->numOfNodes = father->repetitions + grandFather->numOfNodes;
        
        if(child->rChild) {
            father->sumOfNodes += child->rChild->sumOfNodes;
            father->numOfNodes += child->rChild->numOfNodes;
        }
        
        child->sumOfNodes = totalSum;
        child->numOfNodes = totalNum;
        
		*greatGrandFather = child;
		father->lChild = child->rChild;
		child->rChild = father;
		grandFather->lChild = father->rChild;
		father->rChild = grandFather;
        child->father = grandFather->father;
        grandFather->father = father;
        father->father = child;
		if (father->lChild) father->lChild->father = father;
		if (grandFather->lChild) grandFather->lChild->father = grandFather;
	}
    
	//used to decide which state kind of rotation is needed
	enum Order { LL, LR, RL, RR} ;
	
	static Order findOrder(Node* grandFather, Node* father, Node* current) {
		if ((grandFather->data) < (father->data) ) {
			if ((current->data) < (father->data) ) {
				return RL;
			} else {
				return RR;
			}
		} else {
			if ((current->data) < (father->data)) {
				return LL;
			}else {
				return LR;
			}
		}

	}


	//Debugging helper functions for printing contents of tree
	ostream& inOrder(ostream& os) const{
		inOrderRecPrint(head,os);
		os << "|";
		return os;
	}
	ostream& postOrder(ostream& os) const{
		postOrderRecPrint(head,os);
		os << "|";
		return os;
	}
	ostream& preOrder(ostream& os) const{
		preOrderRecPrint(head,os);
		os << "|";
		return os;
	}
	
	ostream& inOrderRecPrint(Node* node, ostream& os) const {
		if (node) {
			inOrderRecPrint(node->lChild, os);
			node->print(os);
			inOrderRecPrint(node->rChild, os);
		}
		return os;
	}
	
	ostream& preOrderRecPrint(Node* node, ostream& os) const {
		if (node) {
			node->print(os);
			preOrderRecPrint(node->lChild, os);
			preOrderRecPrint(node->rChild, os);
		}
		return os;
		
	}
	
	ostream& postOrderRecPrint(Node* node, ostream& os) const {
		if (node) {
			postOrderRecPrint(node->lChild, os);
			postOrderRecPrint(node->rChild, os);
			node->print(os);
		}
		return os;
	}
};



#endif /* SplayTree_hpp */
