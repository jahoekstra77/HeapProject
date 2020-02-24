#ifndef sub_H_
#define sub_H_
#include "max-heap.cpp"

class ELEMENT;
class HEAP;
HEAP initialize(int n);
void buildHeap(HEAP *heap, ELEMENT *A, int n);
void maxHeapify(HEAP *A, int i);
void heapSwap(HEAP *A, int i, int j);

#endif