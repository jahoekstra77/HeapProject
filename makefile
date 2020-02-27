# build an C++ executable named myprog from main.cpp, heap.cpp, and util.cpp

# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -std=c++11 always use the C++11 standard 

CFLAGS = -g -Wall -std=c++11

# run 'make main' to generate the executable
# if any code file has been updated, running 'make main' will re-build the 
# executable

main: main.cpp heap.cpp util.cpp
	$(CC) $(CFLAGS) -o main main.cpp heap.cpp util.cpp

# run 'make clean' to remove the executable and o files
clean: 
	$(RM) *.o *.exe