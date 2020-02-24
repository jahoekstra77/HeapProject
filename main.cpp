#include <iostream>
using namespace std;
#include "max-heap.h"
int main(){
    HEAP maxHeap = initialize(5);
    ELEMENT A[5];
    A[0].key = 13;
    A[1].key = 2;
    A[2].key = 1;
    A[3].key = 9;
    A[4].key = 24;
    cout << "Orignal Array:\n" << "[ ";
    for (int i = 0; i < maxHeap.size; i++){
        cout << A[i].key << " ";
    }
    cout << "]" <<endl;

    heapSwap(&maxHeap, 0, 1);
    cout << "[ ";
    for (int i = 0; i < maxHeap.size; i++){
        cout << A[i].key << " ";
    }
    cout << "]" <<endl;
    
    buildHeap(&maxHeap, A, 5);
    printHeap(maxHeap);
    return 0;
}