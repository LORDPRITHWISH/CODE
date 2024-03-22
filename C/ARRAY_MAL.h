#ifndef MY_FUNCTION_H_

#include<stdio.h>
#include<stdlib.h>

int* arrdec(int len){
    int *arr=(int *)malloc(len*sizeof(int));
    srand(0);
    int mod=100;
    while (len>(mod/10))
        mod*=10;    

    for(int i=0;i<len;i++)
        arr[i]=rand()%mod;
    return arr;
}

void priarr(int *arr,int len){
    for(int i=0;i<len;i++)
        printf("%d , ",arr[i]);
    printf("\n");
}

#endif
