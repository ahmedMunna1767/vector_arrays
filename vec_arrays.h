#include <assert.h>
#include <stdbool.h>
#include <string.h>

const int minCapacity = 16;
const int growthFactor = 2;
const int shrinkFactor = 4;

typedef struct VECARRAY
{
    int size;
    int capacity;
    int *data;
} VecArray;

// array methods

// initialize a new array
VecArray* NewVecArray(int capacity);

// delete array
void DeleteVecArray(VecArray *vecPtr);

// resize function for dynamic length. 
void VecResize(VecArray *vecPtr, int inputSize);

// what should be the capacity based on the required length
int determineCapacity(int length);

// increase size (capacity)
void vecArrayUpsize(VecArray *vecPtr);

// decrease size (capacity)
void vecArrayDownsize(VecArray *vecPtr);

// set array size
int VecArraySetSize(VecArray *vecPtr);

// push element at the end
void VecArrayPush(VecArray *vecPtr, int item);

// print array data with desired seperator
void printArray(VecArray *vecPtr, char seperator);

// get array capacity
int getCapacity(VecArray *vecPtr);

// get element at index
int getValAt(VecArray *vecPtr, int index);

// check if empty
bool getIsEmpty(VecArray *vecPtr);

// insert element at  desired index
void VecArrayInsertAt(VecArray *vecPtr, int index, int value);

// push element at the begining of the array
void VecArrayInsertFirst(VecArray *vecPtr, int value);

// delete the last element 
int VecArrayPop(VecArray *vecPtr);

// delete element at an index
void VecArrayDeleteIndex(VecArray *vecPtr, int index);

// remove the first value found
void VecArrayRemoveVal(VecArray *vecPtr, int value);

// return index of a element
int VecArrayFindVal(VecArray *vecPtr, int value);

// check if valid memory allocated 
void isValidAddress(void *p);

// Test funcs
void testDetermineCapacity();
