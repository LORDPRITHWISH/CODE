#include <iostream>
#include <cstdlib>
#include "test.h"

struct boob
{
    int val;

    boob(int x)
    {
        val = x;
    }
    void op(int z)
    {
        std::cout << val + z;
    }
};

int main()
{
    // for(int i=0;i<100;i++)
    // std::cout<<rand()<<' ';

    // std::cout<<'\n';
    // for(int i;i<221;i++)
    //     std::cout<<'H';
    // if(1) std::cout<<"bad";
    // else std::cout<<"good";
    // std::string str="0123456789";
    // std::cout<<str.substr(0,5);
    // str+=66;
    // std::cout<<str;
    // int a= str.find("a");
    // std::cout<<a;

    // int bin=0;
    // for (int i = 0; i < 4; i++)
    // {
    //     bin <<= 1;
    //     bin |= 1;
    // }
    // std::cout<<bin;
    // std::cout<<add(5)<<std::endl;
    // std::cout<<add(15)<<std::endl;
    // std::cout<<add(5)<<std::endl;
    // boob ab(1000);
    // ab.op(25);
    // unsigned int mod = 1;
    // unsigned int val = 1;
    // for (int i = 0; i < 31; i++)
    //     mod = mod << 1;
    // for (int i = 0; i < 31; i++)
    //     val = val << 1;
    // mod += 4;
    // mod += mod;
    // long long int res = mod % val;
    // std::cout << mod << '\n';
    // std::cout << val << '\n';
    // std::cout << res << '\n';
    int a[9];
    for (int i=0;i<10;i++)
    a[i]=i*100+i+10;
    for (int i=0;i<10;i++)
    std::cout<<a[i]<<"\n";
    std::cout<<sizeof(a)/sizeof(int);

}