#ifndef bigdiv
#include <iostream>
#include <vector>

struct bigint
{
    std::vector<int> num;

    bigint(int x)
    {
        while (x > 0)
        {
            num.insert(num.begin(), x % 10);
            x /= 10;
        }
    }

    // bigint mult(int x)
    // {
    // }
};

std::string divide(int nume, int den, int req)
{
    int dow = 0;
    bigint res(0);
    bigint div(nume);
    int i = 0, len = div.num.size();
    for (int j = 0; j < div.num.size(); j++)
        std::cout << div.num[j];

    while (i < req)
    {
        dow *= 10;
        if (i < len)
            dow += div.num[i];
        if (dow >= den)
        {
            res.num.push_back(dow / den);
            dow %= den;
        }
        else if (res.num.size() > 0 && i < len)
            res.num.push_back(0);
        // std::cout << "hi";
        i++;
    }

    std::cout << "\n";

    for (int j = 0; j < res.num.size(); j++)
        std::cout << res.num[j];
    std::cout << "\n";
    return "res";
}

#endif