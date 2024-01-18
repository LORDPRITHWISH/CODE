#include<stdio.h>

struct trial
{
    int aa,bb;
};


int main()
{
    struct trial dd;
    dd.aa=100;
    dd.bb=99;

    printf("%d",dd.aa+dd.bb);
    return 0;
}