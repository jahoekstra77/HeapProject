# build an C++ executable named myprog from file1.cpp and file2.cpp

# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -std=c++11 always use the C++11 standard 

CFLAGS = -g -Wall -std=c++11

# run 'make myprog' to generate the executable
# if any code file has been updated, running 'make myprog' will re-build the executable

myprog: file1.cpp file2.cpp
	$(CC) $(CFLAGS) -o myprog file1.cpp file2.cpp

# run 'make clean' to remove the executable

clean: 
    $(RM) myprog