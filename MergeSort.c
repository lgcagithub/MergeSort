#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MergeSort.h"


int ReadDate(char* filename, int** pArrayOut,int* pNum)
{
    int index = 0;
    FILE* input = fopen(filename,"r");
    if(!input)
    {
        printf("Open %s failed!\n",filename);
        return 0;
    }

    fscanf(input,"%d",pNum);
    if(*pNum <= 0) return 0;

    if(*pArrayOut)
    {
        free(*pArrayOut);
        *pArrayOut = NULL;
    }

    *pArrayOut = (int*)malloc(sizeof(int)*(*pNum));
    while(index < *pNum)
    {
        fscanf(input,"%d",&(*pArrayOut)[index]);
        index++;
    }

    fclose(input);
    return 1;
}

void Merge(int* pArray1, int num1, int* pArray2, int num2, int* pResult, int numr)
{
	int i = 0, j = 0, k = 0;

	while (i < num1 && j < num2)
	{
		if (pArray1[i] < pArray2[j])
		{
			pResult[k] = pArray1[i]; i++;
		}
		else
		{
			pResult[k] = pArray2[j]; j++;
		}
		k++;
	}

	if (i < num1)
	{
		memcpy(pResult + k, pArray1 + i, sizeof(int)*(num1 - i));//!
	}
	else
	{
		memcpy(pResult + k, pArray2 + j, sizeof(int)*(num2 - j));//!
	}
}

void MergeSortInternal(int* pArray, int num, int* helperBuffer)
{
	if (num <= 1) return;

	int numA = num >> 1;
	int* pArrayA = pArray;
	int numB = num - numA;
	int* pArrayB = pArray + numA;

	MergeSortInternal(pArrayA, numA, helperBuffer);
	MergeSortInternal(pArrayB, numB, helperBuffer + numA);

	memcpy(helperBuffer, pArrayA, sizeof(int)*numA);
	memcpy(helperBuffer + numA, pArrayB, sizeof(int)*numB);//!

	Merge(helperBuffer, numA, helperBuffer + numA, numB, pArray, num);
}

void MergeSort(int* pArray,int num)
{
	//只分配一次内存，排序的时候不会递归动态分配内存，否则空间复杂度为nlog n
	int* helperBuffer = (int*)malloc(sizeof(int) * num);

	if(helperBuffer) MergeSortInternal(pArray, num, helperBuffer);

	free(helperBuffer);
}

void PrintDate(int* pArray, int num)
{
    int index = 0;
    while(index < num)
    {
        printf("%d ",pArray[index]);
        index++;
    }
    printf("\n");
}
















