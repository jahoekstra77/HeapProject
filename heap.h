#ifndef heap_H_
#define heap_H_
#include <vector>

/*
ELEMENT
Description:
        This is the class that acts as the nodes for the heap tree, each
        node has a key value that is used for ordering
*/
class ELEMENT {
    public:
        int key;
};

/*
HEAP
Description:
            A max heap that is made up of an array of ELEMENT objects, the 
            size of the heap is the current number of ELEMENTs in the tree and 
            capcacity is the max number of ELEMENTs to be stored.
*/
class HEAP {
    public:
        int capacity;
        int size;
        std::vector<ELEMENT> H;
    // Constructor for HEAP
    HEAP(int n){
        size = 0;
        capacity = n;
        H[n];
    }
    HEAP initialize(int n);
    void buildHeap(HEAP *heap, std::vector<ELEMENT> A, int n);
    void maxHeapify(HEAP *A, int i);
    void printHeap(HEAP *A);
    void heapSwap(HEAP *A, int i, int j);
    void insert(HEAP *A, int flag, int key);
    void increaseKey(HEAP *A, int flag, int index,int value);
    void increaseKey(HEAP *A, int flag, int index,int value);
};




#endif