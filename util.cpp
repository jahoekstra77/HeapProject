/*
Filename:       util.cpp
Author:         Jake Hoekstra
Date:           2/27/20
Description:    This file implements the I/O commands for reading values and 
                implementing them into a heap data structure
*/
#include <iostream>
#include "util.h"
#inlcude "heap.h"

const int MAX_INPUT = 7;

void run(){
    char inStr[MAX_INPUT] = "ZZZZZZZ";
    while (inStr[0] =! 'S'){
        std::cin >> inStr;
        if (inStr[0] == 'C'){
            HEAP heap = initialize((int)inStr[2]);
        }
    }
}

void readFile(){

}