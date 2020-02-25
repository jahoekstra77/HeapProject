/*
Filename:   heap.cpp
Author:     Jake Hoekstra
Date:       2/20/20
Description: 
            This file implements the Max Heap data structure using objects and 
            a number of related functions
*/


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
    if(l < A->size && A->H[i].key > A->H[i].key){
        largest = l;
    }
    // Find if right child is larger than the right and store index 
    if(r < A->size && A->H[i].key > A->H[i].key){
        largest = r;
    }
    // If a child is larger than the parent, swap them and call recursively
    if (largest != i){
        ELEMENT buffer = A->H[i];
        A->H[i] = A->H[largest];
        A->H[largest] = buffer;
        maxHeapify(A, i);
    }
}


/*
Function:   printHeap(A)
Input(s):     A - heap to be printed
Outputs:    None
*/
void printHeap(HEAP *A){
    std::cout << "Heap Information:" << std::endl;
    std::cout << "Size:\t\t" << A->size << std::endl;
    std::cout << "Capacity:\t" << A->capacity << std::endl;
    std::cout << "Key Values: " << std::endl << "[ " << A->H[0].key;
    for (int i = 1; i < A->H.size(); i++){
        std::cout << ", " << A->H[i].key; 
    }
    std::cout << " ]" << std::endl;
}

/*
Function:   insert(A, flag, key)
Input(s):   A - Heap to insert element to
            flag - flag for whether or not to print heap
            key - key value of inserted element
Output:     None
*/
void insert(HEAP *A, int flag, int key){
    if (A->size + 1 >= A->capacity){
        std::cout << "Cannot insert element, above capacity" << std::endl;
        return;
    }
    if (flag == 2){
        printHeap(A);
    }
    A->H[A->size].key = key;
    A->size++;
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
int deleteMax(HEAP *A, int flag){
    if(flag == 2){
        printHeap(A);
    }
    int returnVal = A->H[0].key;
    // Swap the elements
    ELEMENT buffer = A->H[0];
    A->H[0] = A->H[A->size - 1];
    A->H[A->size - 1] = buffer;
    
    A->size--;
    buildHeap(A, A->H, A->size);
    if(flag == 2){
        printHeap(A);
    }
    return returnVal;

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
        std::cout << "Array out of bounds, larger than heap size" << std::endl;
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