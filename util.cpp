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
Function:       run()
Input(s):       None
Output:         None
Description:    Determines the user's commands and executes them. Uses an always
                true while loop to continually 
*/
void run(){
    std::string input;
    HEAP *heap = new HEAP;
    bool init = false;
    while (true){

        // Get user command
        std::cout << "COMMAND: ";
        std::cin >> input;
        int flag, 
            index, 
            key,
            val;
                
        // Bitwise to uppercase
        input[0] = input[0] & 0xDF;

        // Switch statement to determine which command is being issued
        switch (input[0]){
            case 'P':
                printHeap(heap);
                break;
            // S is the termination case, returns to main
            case 'S': 
                std::cout << "Terminating..." << std::endl;
                return;
            // C initializes a new heap with the user entered capacity
            case 'C':
                std::cin >> flag;
                if (flag <= 0){
                    std::cout << "Error: invalid heap capacity" << std::endl;
                }
                *heap = initialize(flag);
                init = true;
                break;
            // R reads the 'HEAPinput.txt' into a heap
            case 'R':
                if (!init){ // Ensures heap has been initialized
                    std::cout << "Heap not initialized [USE 'C n']\n";
                    break;
                }
                readFile(heap);
                break;
            // W writes the heap's size and value to the console
            case 'W':
                if (!init){ // Ensures heap has been initialized
                    std::cout << "Error: heap not initialized\n";
                    break;
                }
                std::cout << heap->size << std::endl;
                for (int i = 0; i < heap->size; i++){
                    std::cout << heap->H[i].key << std::endl;
                }
                break;
            // I inserts a value into the heap
            case 'I':
                if (!init){ // Ensures heap has been initialized
                    std::cout << "Error: heap not initialized\n";
                    break;
                }
                std::cin >> flag;
                std::cin >> key;
                insert(heap, flag, key);
                break;
            // D deletes the maximum value in the heap and outputs it to console
            case 'D':
                if (!init){ // Ensures heap has been initialized
                    std::cout << "Error: heap not initialized\n";
                    break;
                }
                std::cin >> flag;
                std::cout << deleteMax(heap, flag).key << std::endl;
                break;
            // K increases the key value of an element already in the heap
            case 'K':
                if (!init){ // Ensures heap has been initialized
                    std::cout << "Error: heap not initialized\n";
                    break;
                }
                std::cin >> flag;
                std::cin >> index;
                std::cin >> val;
                increaseKey(heap, flag, index, val);
                break;
            // If the command entered is not valid, inform the user
            default:
                std::cout << "Invalid Command, please try again" << std::endl;
                break;
        }
        
        // Clear input buffer
        while ((getchar()) != '\n'); 
        input = "";
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
        if(heap->capacity < n + heap->size){
            std::cout << "Cannot read, would be above heap capacity\n";
            return;
        }
        for (int i = 0; i < n; i++){
            file >> val;
            insert(heap, 1, val);
        }
    } else {
        std::cout <<"File 'HEAPinput.txt not in directory" << std:: endl;
    }
}

