/*
Filename:       heap.cpp
Author:         Jake Hoekstra
Date:           2/20/20
Description:    This file implements the functions for the HEAP data structure 
                as assigned in P01
*/
#include <iostream>
#include "heap.h"

/*
Function:   intialize(n)
Input(s):   n - integer that will be the capacity of the HEAP object
Outputs:    An empty HEAP that has a defined cacpacity
*/
HEAP initialize(int n){
    HEAP *H = new HEAP(n);
    return *H;
}

/*
Function:   buildHeap(heap, A, n)
Input(s):   heap - HEAP object to be built 
            A - array of values to be added into the heap
            n - size of the heap
*/
void buildHeap(HEAP *heap, std::vector<ELEMENT> A, int n){
    // Initialize a heap of capacity n
    heap->size = n;
    // Add each ELEMENT into heap
    for (int i = 0; i < n; i++){
        heap->H.push_back(A[i]);
    }
    heap->size = n;
    // Builds the max heap
    for (int i = n/2 - 1; i >= 0; i--){
        maxHeapify(heap, i);
    }
}

/*
Function:   maxHeapify(A, i)
Input(s):   A - HEAP that is to be heapified
            i - index where heapify will be applied
Output:     None
*/
void maxHeapify(HEAP *A, int i){
    // Find children of i
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    // Find if left child is larger than the right and store index 
    if(l < A->size && A->H[l].key > A->H[largest].key){
        largest = l;
    }
    // Find if right child is larger than the right and store index 
    if(r < A->size && A->H[r].key > A->H[largest].key){
        largest = r;
    }
    // If a child is larger than the parent, swap them and call recursively
    if (largest != i){
        heapSwap(A, i, largest);
        maxHeapify(A, largest);
    }
}

/*
Function:   heapSwap(A, i, j)
Input(s):   A - heap to have elements swapped
            i - first element to be swapped
            j - second element to be swapped
Output:     None
*/
void heapSwap(HEAP *A, int i, int j){
    ELEMENT buffer = A->H[i];
    A->H[i] = A->H[j];
    A->H[j] = buffer;
}

/*
Function:   insert(A, flag, key)
Input(s):   A - Heap to insert element to
            flag - flag for whether or not to print heap
            key - key value of inserted element
Output:     None
*/
void insert(HEAP *A, int flag, int key){
    // Buffer element to add to vector
    ELEMENT E;

    if (flag == 2){
        printHeap(A);
    }
    // Add element to vector
    E.key = key;
    A->H.push_back(E);

    A->size++;
    if (A->size > A->capacity){
        A->capacity++;
    }

    buildHeap(A, A->H, A->size);
    if (flag == 2){
        printHeap(A);
    }
}

/*
Function:   deleteMax(A, flag)
Input(s):   A - Heap to delete max value from
            flag - int for whether or not to print heap
Output:     Key value of deleted max
*/
ELEMENT deleteMax(HEAP *A, int flag){
    if(flag == 2){
        printHeap(A);
    }
    ELEMENT returnE = A->H[0];
    // Swap the elements
    ELEMENT buffer = A->H[0];
    A->H[0] = A->H[A->size - 1];
    A->H[A->size - 1] = buffer;
    
    A->size--;
    buildHeap(A, A->H, A->size);
    if(flag == 2){
        printHeap(A);
    }
    return returnE;

}

/*
Function:   increaseKey(A, flag, index, value)
Input(s):   A - Heap to have element's key increased
            flag - int for whether or not to print heap
            index - int for location of element to increase key
            value - int value to increase key to
Output:     None
*/
void increaseKey(HEAP *A, int flag, int index, int value){
    if (index > A->size){
        // TODO
        return;
    } else if (value < A->H[index].key){
        std::cout << "Value is smaller than current key value" << std::endl;
        return;
    }
    if (flag == 2){
        printHeap(A);
    }
    A->H[index].key = value;
    buildHeap(A, A->H, A->size);
    if (flag == 2){
        printHeap(A);
    }
}

/*
Function:   printHeap(A)
Input(s):   A - heap to be printed
Outputs:    None
*/
void printHeap(HEAP *A){
    std::cout << "Heap Information:" << std::endl;
    std::cout << "Size:\t\t" << A->size << std::endl;
    std::cout << "Capacity:\t" << A->capacity << std::endl;
    std::cout << "Key Values: " << std::endl << "[ ";
    for (int i = 0; i < A->size; i++){
        std::cout << A->H[i].key << " "; 
    }
    std::cout << "]" << std::endl;
}
