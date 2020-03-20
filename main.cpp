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

int main(){
    // Variables
    char c;
    int i, v, f;
    HEAP heap;
    bool init = false;

    while(true){
        c = nextCommand(&i, &v, &f);
        switch (c) {
            // Exits the program when S is entered
            case 'S': 
                std::cout << "COMMAND: " << c << "\n";
                exit(0);
            // Initializes the heap to size i
            case 'C':
                std::cout << "COMMAND: " << c << " " << i << "\n";
                if (i >= 0){
                    heap = initialize(i);
                    init = true;
                } else {
                    std::cout << "Error: invalid heap capacity\n";
                }
                break;
            // Read the key values from "HEAPinput.txt"
            case 'R':
                std::cout << "COMMAND: " << c << "\n";
                if (!init){
                    std::cout << "Error: heap not initialized\n";
                } else {
                    readFile(&heap);
                }
                break;
            // Write command prints heap
            case 'W':
                std::cout << "COMMAND: " << c << "\n";
                if (!init){
                    std::cout << "Error: heap not initialized\n";
                } else {
                    printHeap(&heap);
                }
                break;
            // Inserts element with key value i
            case 'I':
                std::cout << "COMMAND: " << c << " " << f << " " << i << "\n";
                if (!init){
                    std::cout << "Error: heap not initialized\n";
                } else if (f != 1 && f != 2){
                    std::cout << "Error: invalid flag value\n";
                } else {
                    insert(&heap, f, i);
                }
                break;
            // Deletes maximum element
            case 'D':
                std::cout << "COMMAND: " << c << " " << f << "\n";
                if (!init){
                    std::cout << "Error: heap not initialized\n";
                } else if (heap.size <= 0){
                    std::cout << "Error: heap empty" << std::endl;
                } else if (f != 1 && f != 2){
                    std::cout << "Error: invalid flag value\n";
                } else {
                    deleteMax(&heap, f).key;
                }
                break;
            // Increases the key value at index i to v.
            case 'K':
                std::cout << "COMMAND: " << c << " " << f << " " << i;
                std::cout << " " << v << "\n";
                // Decrement index for first element at 1
                i = i - 1;
                if (!init){
                    std::cout << "Error: heap not initialized\n";
                } else if (heap.size <= 0){
                    std::cout << "Error: heap empty" << std::endl;
                } else if (f != 1 && f != 2){
                    std::cout << "Error: invalid flag value\n";
                } else {
                    increaseKey(&heap, f, i, v);
                }
                break;
            default: 
                break;
        }  
    }
    return 0;
}