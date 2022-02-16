#include<stdio.h>
#include<stdlib.h>
#include "vec_arrays.h"
#include "vec_arrays.c"

#define NEWLINE printf("\n");

int main(){
    printf("Executing VecArray.main...\n"); 
    testDetermineCapacity();

    VecArray* vecArrayPtr = NewVecArray(3); 
    isValidAddress(vecArrayPtr); 

    for (int i = 0; i < 5; i++)
    {
        VecArrayPush(vecArrayPtr, i*5); 
    }

    printArray(vecArrayPtr, ' ');

    for (int i = 0; i < 5; i++)
    {
        VecArrayPush(vecArrayPtr, i*5); 
    }
    printf("Get index values at 0, 2, 4, 6 -->>"); 
    printf("%d, %d, %d, %d\n", getValAt(vecArrayPtr, 0), getValAt(vecArrayPtr, 2), getValAt(vecArrayPtr, 4), getValAt(vecArrayPtr, 6));
    printf("25 at index: %d\n", VecArrayFindVal(vecArrayPtr, 25)); 
    printf("35 at index: %d\n", VecArrayFindVal(vecArrayPtr, 35)); 
    printf("24 at index: %d\n", VecArrayFindVal(vecArrayPtr, 24)); 

    printArray(vecArrayPtr,','); 

    VecArrayRemoveVal(vecArrayPtr,0); 
    VecArrayRemoveVal(vecArrayPtr,0); 
    VecArrayRemoveVal(vecArrayPtr,10); 
    VecArrayRemoveVal(vecArrayPtr,15); 

    VecArrayPop(vecArrayPtr);
    VecArrayPop(vecArrayPtr);


    printArray(vecArrayPtr,','); 

    VecArrayInsertFirst(vecArrayPtr, 700);
    VecArrayInsertAt(vecArrayPtr, 1, 101); 
    VecArrayInsertAt(vecArrayPtr, 2, 102); 
    VecArrayInsertAt(vecArrayPtr, 3, 103); 

    printArray(vecArrayPtr,','); 

    printf("All Test Passed\n");

    return 0; 
}