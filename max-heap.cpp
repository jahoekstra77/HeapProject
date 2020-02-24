/*
Filename:   max-heap.cpp
Author:     Jake Hoekstra
Date:       2/20/20
Description: 
            This file implements the Max Heap data structure using objects and 
            a number of related functions
*/
// Prototypes
class ELEMENT;
class HEAP;
HEAP initialize(int n);
void buildHeap(HEAP *heap, ELEMENT *A, int n);
void maxHeapify(HEAP *A, int i);
void heapSwap(HEAP *A, int i, int j);

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
        ELEMENT H[];
    // Constructor for HEAP
    HEAP(int n){
        size = n;
        capacity = n;
        H[n];
    }
};

/*
Function:   intialize(n)
Input(s):    n - integer that will be the capacity of the HEAP object
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
void buildHeap(HEAP *heap, ELEMENT *A, int n){
    // initialize a heap of capacity n
    (*heap) = initialize(n);
    // Add each ELEMENT into heap
    for (int i = 0; i < n; i++){
        (*heap).H[i] = A[i];
    }
    (*heap).size = n;
    // Builds the max heap
    for (int i = n/2; i > 0; i--){
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
    int l = 2*i;
    int r = 2*i + 1;
    int largest = i;
    // Find if left child is larger than the right and store index 
    if(l < A->size && A->H[l].key > A->H[i].key){
        largest = l;
    }
    // Find if right child is larger than the right and store index 
    if(l < A->size && A->H[r].key > A->H[i].key){
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
Input(s):   A - HEAP where elements are to be swapped
            i - index of element 1 to be swapped
            j - index of element 2 to be swapped
Output:     None
*/
void heapSwap(HEAP *A, int i, int j){
    int buffer = A->H[i].key;
    A->H[i].key = A->H[j].key;
    A->H[j].key = buffer;
}

/*
Function:   printHeap(A)
Inputs:     A - heap to be printed
Outputs:    None
*/
void printHeap(HEAP A){
    cout << "Heap Information:" << endl;
    cout << "Size:\t\t" << A.size << endl;
    cout << "Capacity:\t" << A.capacity << endl;
    cout << "Key Values: " << endl << "[ " << A.H[0].key;
    for (int i = 1; i < A.size; i++){
        cout << ", " << A.H[i].key; 
    }
    cout << " ]" << endl;
}