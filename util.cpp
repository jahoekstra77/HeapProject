/*
Filename:       util.cpp
Author:         Jake Hoekstra
Date:           2/27/20
Description:    This file implements the I/O commands for reading values and 
                implementing them into a heap data structure
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "util.h"
#include "heap.h"

const int MAX_INPUT = 7;

void run(){
    std::string input (7, 'x');
    HEAP *heap = new HEAP;
    while (true){
        // Get user command
        std::cout << "Please enter a command: ";
        std::cin >> input;

        switch (input[0]){
            case 'S': 
                return;
            case 'C':
                *heap = initialize((int)input[2]);
                break;
            case 'R':
                readFile(heap);
                printHeap(heap);
                break;
        }
    }
}

void readFile(HEAP *heap){
    int n;
    
    std::ifstream file;
    file.open("HEAPinput.txt");
    std::vector<ELEMENT> V;
    
    if(file.is_open()){
        file >> n;
        V.resize(n);
        for (int i = 0; i < n; i++){
            file >> V[i].key;
        }
    }
    buildHeap(heap, V, n);
}

