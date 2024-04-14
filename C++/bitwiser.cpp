#include<iostream>

int main(){
    unsigned int a=0,c=8765,res;
    int b=0;
    for (int i=0;i<32;i++){
        a<<=1;
        a|=1;
        b<<=1;
        b|=1;
    }
    res=c^a;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;
}