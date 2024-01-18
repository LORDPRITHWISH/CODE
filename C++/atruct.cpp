#include<iostream>

struct trial
{
    int aa,bb;
    trial(int a,int b)
    {
        aa=a;bb=b;
    }

    int add()
    {
        return aa+bb;
    }
};


int main()
{
    trial dd(5,10);
    std::cout<<dd.add();
    std::cout<<"good";
    return 0;
}