#ifndef heap_H_
#define heap_H_
#include <vector>

struct ELEMENT;
struct HEAP;

HEAP    initialize(int n);
void    buildHeap(HEAP *heap, std::vector<ELEMENT> A, int n);
void    maxHeapify(HEAP *A, int i);
void    insert(HEAP *A, int flag, int key);
ELEMENT deleteMax(HEAP *A, int flag);
void    increaseKey(HEAP *A, int flag, int index,int value);
void    printHeap(HEAP *A);

#endif