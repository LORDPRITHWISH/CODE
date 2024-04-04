#include<iostream>
#include<math.h>

std::string tobi(int n,int l)
{
    std::string bin="";
    while(n>0)
    {
        bin=(char)(n%2+48)+bin;
        n/=2;
    }
    for (int i=bin.length();i<l;i++)
         bin='0'+bin;
    return bin;
}


int frobi(std::string bin){
    int n=0;
    int len=bin.length();
    for(int i=len-1;i>=0;i--)
        n+=((int)bin[len-1-i]-48)*pow(2,i);
    return n;

}

std::string cypher(){
    std::string base = "";
    for(int i=65;i<=90;i++)
    base+=i;
    for(int i=97;i<=122;i++)
    base+=i;
    for(int i=48;i<=57;i++)
    base+=i;
    base+='+';
    base+='/';
    return base;
}

std::string encode(std::string str){
    std::string raw = "";
    std::string res = "";
    std::string code = cypher();
    for(int i:str)
        raw+=tobi(i,8);
    int len = raw.length();
    while (len%6)
    {
        raw+='0';
        len++;
    }
    for(int i=0;i<len;i+=6)
        res+=code[frobi(raw.substr(i,6))];
    return res;
}

std::string decode(std::string str){
    std::string raw = "";
    std::string res = "";
    std::string code = cypher();
    for(char i:str)
    raw+=tobi(code.find(i),6);
    int len = (raw.length()/8)*8;
    raw=raw.substr(0,len);
    for(int i=0;i<len;i+=8)
        res+=frobi(raw.substr(i,8));
    return res;
}



int main(){
    int x='-';
    // std::string str="it is a good day";
    std::string str="pop";
    std::string res="";
    int c=1;
    switch(c){
        case 1 :
        res =encode(str);
        break;
        case 2 :
        res=decode(str);
        break;
        case 3 :
        res=decode(encode(str));
        break;
        default :
        res="NaC\n";
    }
    std::cout<<res;
    // std::cout<<tobi(4,8);
    return 0;
}