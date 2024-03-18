#include<iostream>
#include<chrono>
#include<cstdlib>
#include<thread>

void arrprint(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        std::cout<<arr[i]<<' ';
    }
    std::cout<<std::endl;
}   

void merge(int *arr,int *ar,int *br,int lena,int lenb)
{
    int i=0,j=0,k=0;
    while (j<lena && k<lenb)
    {
        if(ar[j]<br[k])
            arr[i++]=ar[j++];
        else
            arr[i++]=br[k++];
    }

    while (j<lena)
        arr[i++]=ar[j++];

    while (k<lenb)
        arr[i++]=br[k++];
    
}

void devide(int *arr,const int len){
    const int mid=len/2;
    const int pnt=len-mid;
    int *ara = new int[mid];
    int *arb = new int[pnt];
    int j=0;
    if (len = 1 )
        return;

    for (int i=0;i<len;i++)
    {
        if(i<mid)
            ara[i]=arr[i];
        else
        {
            arb[j++]=arr[i];
        }
    }
    
    devide(ara,mid);
    devide(arb,pnt);

    merge(arr,ara,arb,mid,pnt);
}


void mergesort(int *arr, int len){

    devide(arr,len);
}

int *arrmaker(const int len)
{
    int *arr = new int[len];
    for(int i=0;i<len;i++)
        arr[i]=rand();
        // arr[i]=rand()%100;
    return arr;
}

void lenview(int len)
{
    int num=0;
    while(len>0)
    {
        num++;
        len/=10;
    }
    std::cout<<"length is :"<<num<<std::endl;
}

int main()
{

    const int len=100000000;
    lenview(len);
    // const int len=100;
    int *arr=arrmaker(len);
    mergesort(arr,len);
    // arrprint(arr,len);
    return 0;
    // std::cout<<len;
}