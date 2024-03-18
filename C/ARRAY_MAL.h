#ifndef MY_FUNCTION_H_

#include<stdio.h>
#include<stdlib.h>

int* arrdec(int len){
    int *arr=(int *)malloc(len*sizeof(int));

    srand(0);

    for(int i=0;i<len;i++)
        arr[i]=rand()%100;
    return arr;
}

void priarr(int *arr,int len){
    for(int i=0;i<len;i++)
        printf("%d , ",arr[i]);
    printf("\n");
}

#endif
