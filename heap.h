/*
Filename:       heap.h
Author:         Jake Hoekstra
Date:           2/20/20
Description:    This is the header file for the heap data structure, it
                implements the structures and prototypes the functions that are
                defined in heap.cpp

*/
#ifndef heap_H_
#define heap_H_
#include <vector>


/*
Strucutre:  ELEMENT
Description:
        This is the class that acts as the nodes for the heap tree, each
        node has a key value that is used for ordering
*/
struct ELEMENT {
    public:
        int key;
};

/* 
Strucutre:  HEAP
Description:
            A max heap that is made up of an array of ELEMENT objects, the 
            size of the heap is the current number of ELEMENTs in the tree and 
            capcacity is the max number of ELEMENTs to be stored.
*/
struct HEAP {
    public:
        int capacity;
        int size;
        std::vector<ELEMENT> H;
        // Constructor for HEAP
        HEAP(int n) {
            size = 0;
            capacity = n;
        }        
};

HEAP    initialize(int n);
void    buildHeap(HEAP *heap, std::vector<ELEMENT> A, int n);
void    maxHeapify(HEAP *A, int i);
void    heapSwap(HEAP *A, int i, int j);
void    insert(HEAP *A, int flag, int key);
ELEMENT deleteMax(HEAP *A, int flag);
void    increaseKey(HEAP *A, int flag, int index,int value);
void    printHeap(HEAP *A);

#endif