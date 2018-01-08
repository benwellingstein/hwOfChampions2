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
    SplayTree(Node* root = NULL);
    ~SplayTree();



	//splay tree insert function
    bool insert(int val);

    
    int totalNumberOfNodes();

    
    int totalTreeValue();

    
    
    
   //splay tree find max function
//    static Node* findMax(Node* top);
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
    void find(int val);
    
    int sumOfBestN(int numberOfNodes);

    
	//splay function
    void splay(int val);

	
	// boolean exists function - searches branch for given value
    bool exist(int val) const;

	/*New functionality of tree - top keeps the highest value in the tree
	 *this function simply returns that value
	 */
    int getTop();

	
	//used to return pointers to the values in the tree by array
    void exportArr(int* arr);

	
	
	//used to count number of nodes in tree
    int size();



	//helper function for debugging
    ostream& print(ostream& os) const;



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
    void getData(int* arrOriginal);

    
	static void getDataRec(int* arr, Node* node, int* i) {
		if (node) {
			getDataRec(arr, node->lChild, i);
			arr[*i] = ((node->data));
			*i = *i + 1 ;
			getDataRec(arr, node->rChild, i);
		}
	}
	
	
	//merges arrays
    void mergeSortArrays(int* arrChanged, int* arrNotChanged, int* arrFinal);


	//inserts all values of array into tree
    void buildTreeFromArray(Node* head, int* arrFinal);

	
	//helper function for deleting tree
    void inOrderRecDestroy(Node* node) const;

	
	

	
	//Helps to get the next node in searches - returns same/left/right node
    Node* findNext(Node* checkAgainst, int val) const {
        if ((checkAgainst->data)< val)      return checkAgainst->rChild;
        if (val < (checkAgainst->data))     return checkAgainst->lChild;
        if (val == (checkAgainst->data))     return checkAgainst;
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
