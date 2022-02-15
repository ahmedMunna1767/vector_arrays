VecArray *NewVecArray(int capacity)
{
    int vectorCapacity = determineCapacity(capacity);

    VecArray *vecArrayPtr = malloc(sizeof(VecArray));
    isValidAddress(vecArrayPtr);

    vecArrayPtr->size = 0;
    vecArrayPtr->capacity = vectorCapacity;
    vecArrayPtr->data = (int *)malloc(sizeof(int) * vecArrayPtr->capacity);

    return vecArrayPtr;
}

void VecResize(VecArray *vecPtr, int inputSize)
{
    int curSize = vecPtr->size;

    if (curSize < inputSize)
    {
        if (curSize == vecPtr->capacity)
            vecArrayUpsize(vecPtr);
    }
    else if (curSize > inputSize)
    {
        if (curSize < (vecPtr->capacity / shrinkFactor))
            vecArrayDownsize(vecPtr);
    }
}

void vecArrayUpsize(VecArray *vecPtr)
{
    printf("Need to Upsize from %d to %d\n", vecPtr->capacity, determineCapacity(vecPtr->capacity));
    int *newData = (int *)realloc(vecPtr->data, sizeof(int) * determineCapacity(vecPtr->capacity));
    isValidAddress(newData);
    vecPtr->data = newData;
    vecPtr->capacity = determineCapacity(vecPtr->capacity);
    printf("Successfull Upsizing\n");
}

void vecArrayDownsize(VecArray *vecPtr)
{

    int newCapacity = vecPtr->capacity / growthFactor;
    if (newCapacity < minCapacity)
    {
        newCapacity = minCapacity;
    }

    if (newCapacity != vecPtr->capacity)
    {
        int *newData = (int *)realloc(vecPtr->data, sizeof(int) * newCapacity);
        isValidAddress(newData);
        vecPtr->data = newData;
        vecPtr->capacity = newCapacity;
    }
}

void DeleteVecArray(VecArray *vecPtr)
{
    free(vecPtr->data);
    free(vecPtr);
}

void isValidAddress(void *p)
{
    if (p == NULL)
    {
        printf("Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

int determineCapacity(int length)
{
    const int minCapacity = 1;
    int capacity = minCapacity;
    while (length > capacity)
    {
        capacity = capacity * growthFactor;
    }
    return capacity * growthFactor;
}

int VecArrayGetSize(VecArray *vecPtr)
{
    return vecPtr->size;
}

void VecArrayPush(VecArray *vecPtr, int item)
{
    VecResize(vecPtr, vecPtr->size + 1);
    int *loc = (vecPtr->data) + vecPtr->size;
    *loc = item;
    vecPtr->size = vecPtr->size + 1;
}

void printArray(VecArray *vecPtr, char seperator)
{
    printf("Size of the Array %d.\nCapacity Of the array %d. \nItems :  ", vecPtr->size, vecPtr->capacity);

    for (int i = 0; i < vecPtr->size; i++)
    {
        printf(" %d%c ", *(vecPtr->data + i), seperator);
    }
    printf("\n");
}

int getCapacity(VecArray *vecPtr)
{
    return vecPtr->capacity;
}

int getValAt(VecArray *vecPtr, int index)
{
    if (index < 0 || index >= vecPtr->size)
    {
        printf("Index is negative or equal or greater than size of the array.\n");
        exit(EXIT_FAILURE);
    }
    return *((vecPtr->data) + index);
}

bool getIsEmpty(VecArray *vecPtr)
{
    return !vecPtr->size;
}

void VecArrayInsertAt(VecArray *vecPtr, int index, int value)
{
    VecResize(vecPtr, vecPtr->size + 1);
    void* dest = vecPtr->data + index + 1; 
    void* src = vecPtr->data + index; 
    int sliceLen = vecPtr->size - index; 
    memmove(dest, src, sliceLen * sizeof(int));
    *(vecPtr->data + index) = value;
    vecPtr->size = vecPtr->size + 1;
}

void VecArrayInsertFirst(VecArray *vecPtr, int value)
{
    VecResize(vecPtr, vecPtr->size + 1);
    void* dest = vecPtr->data + 1; 
    void* src = vecPtr->data; 
    int sliceLen = vecPtr->size; 
    memmove(dest, src, sliceLen * sizeof(int));
    *vecPtr->data = value;
    vecPtr->size = vecPtr->size + 1;
}

int VecArrayPop(VecArray *vecPtr)
{
    VecArrayDeleteIndex(vecPtr,vecPtr->size - 1);
}

void VecArrayDeleteIndex(VecArray *vecPtr, int index)
{
    if (index < 0 || index >= vecPtr->size)
    {
        exit(EXIT_FAILURE);
    }
    VecResize(vecPtr, vecPtr->size - 1);
    void* dest = vecPtr->data + index; 
    void* src = vecPtr->data + index + 1; 
    int sliceLen = vecPtr->size - index; 
    memmove(dest, src, sliceLen * sizeof(int));
    vecPtr->size = vecPtr->size - 1;
}

void VecArrayRemoveVal(VecArray *vecPtr, int value)
{
    int index = VecArrayFindVal(vecPtr,value);
    if(index != -1) VecArrayDeleteIndex(vecPtr, index);  
}

int VecArrayFindVal(VecArray *vecPtr, int value)
{
    for (int i = 0; i < vecPtr->size; i++)
    {
        if (value == *(vecPtr->data + i))
            return i;
    }
    return -1;
}

// Test Funcs
void testDetermineCapacity()
{
    assert(determineCapacity(10) == 32);
    assert(determineCapacity(3) == 8);
    assert(determineCapacity(4) == 8);
    assert(determineCapacity(16) == 32);
    assert(determineCapacity(7) == 16);
    assert(determineCapacity(10) == 32);
}
