#include<stdio.h>
#include<stdlib.h>
#include "../ARRAY_MAL.h"

void swap(int *a,int *b)    {
    int t= *a;
    *a= *b;
    *b= t;
}

void check(int *arr,int len,int po){
    int lc=po*2+1,rc=(po+1)*2;
    if(lc<len){
        if(rc<len){
            if(arr[po]<arr[lc]){
                if(arr[rc]>arr[lc]){
                    swap(arr+po,arr+rc);
                    check(arr,len,rc);
                }
                else{
                    swap(arr+po,arr+lc);
                    check(arr,len,lc);
                }
            }
            else if (arr[po]<arr[rc])
            {
                swap(arr+po,arr+rc);
                check(arr,len,rc);
            }
            
        }
        else if(arr[po]<arr[lc])
            swap(arr+po,arr+lc);
    }
}

void heapify(int *arr,int len){
    for(int i=len-1;i>=0;i--)
        check(arr,len,i);
}

void remroot(int *arr,int len){
    swap(arr,arr+len-1);
    check(arr,len-1,0);
}

void heap(int *arr,int len) {
    heapify(arr,len);
    for(int i=0;i<len;i++)
        remroot(arr,len-i);
    // swap(arr,arr+9);
}

int main()  {
    const int len=10;
    int* arr=arrdec(len);
    priarr(arr,len);
    heap(arr,len);
    priarr(arr,len);
    free(arr);
}   