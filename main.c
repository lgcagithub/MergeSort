#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"

int main()
{
    int* pArray = NULL;
    int num = 0;

    if(ReadDate("input.txt",&pArray,&num))
    {
        PrintDate(pArray,num);

        MergeSort(pArray,num);

        PrintDate(pArray,num);
    }

    return 0;
}
