#include "SplayTree.hpp"
#include <cassert>

SplayTree::SplayTree(Node* root): head(root), top(NULL) {}

SplayTree::~SplayTree() {
    inOrderRecDestroy(head);
    head = NULL;
    top = NULL;
}

bool SplayTree::insert(int val) {
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
        
        oldHead->father = newNode;
        
        if(oldHead->lChild) {
            oldHead->sumOfNodes -= oldHead->lChild->sumOfNodes;
            oldHead->numOfNodes -= oldHead->lChild->numOfNodes;
            oldHead->lChild->father = newNode;
            oldHead->lChild = NULL;
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
        
        if (oldHead->rChild) {
            oldHead->sumOfNodes -= oldHead->rChild->sumOfNodes;
            oldHead->numOfNodes -= oldHead->rChild->numOfNodes;
            
            oldHead->rChild->father = newNode;
            oldHead->rChild = NULL;
        }
        
        head = newNode;
        if (top && (top->data) < val) top = newNode;
        
    }
    
    return true;
}

int SplayTree::totalNumberOfNodes() {
    if (head==NULL) return 0;
    return head->numOfNodes;
}

int SplayTree::totalTreeValue() {
    if (head==NULL) return -1;
    return head->sumOfNodes;
}

void SplayTree::find(int val) {
    if (!head) return;
    Node* current = head;
    Node* next = findNext(current, val);
    while(next != NULL && current != next) {
        current = next;
        next = findNext(current, val);
    }
    splay((current->data));
}

int SplayTree::sumOfBestN(int numberOfNodes) {
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
            nodesLeft -= current->rChild->numOfNodes + current->repetitions;
            current = current->lChild;
            continue;
        }
        if(nodesLeft <= current->repetitions) return current->data * nodesLeft + sum;
        
        sum += current->data * current->repetitions;
        nodesLeft -= current->repetitions;
        current = current->lChild;
    }
    return 0;
}

void SplayTree::splay(int val) {
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


bool SplayTree::exist(int val) const {
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

int SplayTree::getTop() {
    if (!top) return -1;
    return top->data;
}

void SplayTree::exportArr(int* arr) {
    int i = 0;
    recursiveFill(arr, head, &i);
}

int SplayTree::size() {
    return countNodes(head);
}

ostream& SplayTree::print(ostream& os) const {
    preOrder(os);
    inOrder(os);
    postOrder(os);
    return os;
}

void SplayTree::getData(int* arrOriginal) {
    int i=0;
    getDataRec(arrOriginal, head, &i);
}


void SplayTree::mergeSortArrays(int* arrChanged, int* arrNotChanged, int* arrFinal) {
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

void SplayTree::buildTreeFromArray(Node* head, int* arrFinal) {
    for (int i = 0; arrFinal[i]; ++i ) {
        insert(arrFinal[i]);
    }
}

void SplayTree::inOrderRecDestroy(Node* node) const {
    if (node) {
        inOrderRecDestroy(node->lChild);
        inOrderRecDestroy(node->rChild);
        //            delete node->data;
        delete node;
    }
}

