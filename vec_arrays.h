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

VecArray* NewVecArray(int capacity);

void DeleteVecArray(VecArray *vecPtr);

void VecResize(VecArray *vecPtr, int inputSize);

int determineCapacity(int length);

void vecArrayUpsize(VecArray *vecPtr);

void vecArrayDownsize(VecArray *vecPtr);

int VecArraySetSize(VecArray *vecPtr);

void VecArrayPush(VecArray *vecPtr, int item);

void printArray(VecArray *vecPtr, char seperator);

int getCapacity(VecArray *vecPtr);

int getValAt(VecArray *vecPtr, int index);

bool getIsEmpty(VecArray *vecPtr);

void VecArrayInsertAt(VecArray *vecPtr, int index, int value);

void VecArrayInsertFirst(VecArray *vecPtr, int value);

int VecArrayPop(VecArray *vecPtr);

void VecArrayDeleteIndex(VecArray *vecPtr, int index);

void VecArrayRemoveVal(VecArray *vecPtr, int value);

int VecArrayFindVal(VecArray *vecPtr, int value);

void isValidAddress(void *p);

// Test funcs

void testDetermineCapacity();
