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

void MergeSort(int* pArray,int num)
{
    int* pArrayA = NULL;
    int numA = 0;
    int* pArrayB = NULL;
    int numB = 0;

    if(num > 1)
    {
        numA = num>>1;
        pArrayA = (int*)malloc(sizeof(int)*numA);
        numB = num - numA;
        pArrayB = (int*)malloc(sizeof(int)*numB);

        memcpy(pArrayA,pArray,sizeof(int)*numA);
        memcpy(pArrayB,pArray+numA,sizeof(int)*numB);//!

        MergeSort(pArrayA,numA);
        MergeSort(pArrayB,numB);

        Merge(pArrayA,numA,pArrayB,numB,pArray,num);

        free(pArrayA);
        free(pArrayB);
    }
}

void Merge(int* pArray1,int num1,int* pArray2,int num2,int* pResult,int numr)
{
    int i = 0,j = 0,k = 0;

    while(i < num1 && j < num2)
    {
        if(pArray1[i] < pArray2[j])
        {
            pResult[k] = pArray1[i]; i++;
        }
        else
        {
            pResult[k] = pArray2[j]; j++;
        }
        k++;
    }

    if(i < num1)
    {
        memcpy(pResult+k,pArray1+i,sizeof(int)*(num1-i));//!
    }
    else
    {
        memcpy(pResult+k,pArray2+j,sizeof(int)*(num2-j));//!
    }
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
















