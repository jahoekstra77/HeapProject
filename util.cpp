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

/*
Function:       nextCommand(i, v, f)
Input(s):       i - index, key, or size
                v - value of increase key
                f - flag value (to print or not)
Output:         char of command character
Description:    Determines the command of the user and stores the corresponding
                parameters in integers passed by value
*/
char nextCommand(int *i, int *v, int *f){
    char c;
    std::cin >> c;
    // Change character to upper case
    c = c & 0xDF;
    while(true){
        switch (c){
            // Skipping over spaces, tabs, and newline characters
            case ' ':
            case '\t':
            case '\n':
                break;
            // If stop, read, or write no more characters/numbers needed
            case 'S':
            case 'R':
            case 'W':
                break;
            // If creating heap, find the intended size and put in i
            case 'C':
                std::cin >> *i;
                break;
            // If inserting, take flag and key value
            case 'I':
                std::cin >> *f;
                std::cin >> *i;
                break;
            // If deleting max, take flag value
            case 'D':
                std::cin >> *f;
                break;
            // If increasing key, take the flag, index, and key values
            case 'K':
                std::cin >> *f;
                std::cin >> *i;
                std::cin >> *v;
                break;
            // If command not recognized, inform user of invalid command
            default:
                std::cout << "Invalid Command\n";
                // Clear input if invalid command is entered
                std::cin.sync();
                break;
        }
        // Clear input for next command
        std::cin.sync();
        return c;
    }
    
}

/*
Function:   readFile(heap)
Input(s):   heap - heap object which file's contents will be written into
Output:     None
*/
void readFile(HEAP *heap){
    int n;
    int val;

    std::ifstream file;
    file.open("HEAPinput.txt");

    
    if(file.is_open()){
        file >> n;
        if(heap->capacity < n){
            std::cout << "Error: array size exceeds heap capacity\n";
            return;
        }
        *heap = initialize(heap->capacity);
        
        heap->size += n;
        for (int i = 0; i < n; i++){
            file >> val;
            heap->H[i].key = val;
        }
        for (int i = heap->size/2; i >= 0; i--){
            maxHeapify(heap, i);
        }
        file.close();
    } else {
        std::cout <<"File 'HEAPinput.txt' not in directory" << std:: endl;
    }
}

