/*
Filename:       main.cpp
Author:         Jake Hoekstra
Date:           2/20/20
Description:    The driver program for Project 1
*/
#include <iostream>
#include <vector>
#include <limits>
#include "heap.h"
#include "util.h"

const int N = 6;
const int CAP = 10;

int main(){
    HEAP heap = initialize(CAP);
    std::vector<ELEMENT> V;
    std::cout << "Original Array:\t";
    ELEMENT E;
    std::cout << "[";
    for (int i = 0; i < N; i++){
        E.key = rand() % 99 + 1;
        V.push_back(E);
        std::cout << E.key << " ";
    }
    std::cout << "]\n";
    buildHeap(&heap, V, N);
    printHeap(&heap);

    return 0;
}