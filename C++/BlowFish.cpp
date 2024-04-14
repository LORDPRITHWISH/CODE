#include <iostream>
#include "blowhead.h"

void test(std::string mes)
{
    std::string cypher = encode(mes);
    std::string res = decode(cypher);
    // std::cout<<"\n\n";
    // std::cout << mes;
    // std::cout << "\n\n";
    std::cout << "cypher: " << cypher;
    std::cout << "\n\n";
    std::cout << "result: " << res;
}

int main()
{
    setS();
    std::string key = "darklord";
    keyset(key);
    std::string mess = "amigo how are you doing what is the mater with you";
    // test(mess);
    test("hello");

    return 0;
}