#ifndef darklord
#include <iostream>
#include "divition.h"
#include "pi.h"

const std::string HEXCHR = "0123456789ABCDEF";

unsigned int S[4][255];

unsigned int K[18];

unsigned int tobi(std::string hex)
{
    int len = hex.length();
    unsigned int bin = 0;
    for (int i = 0; i < len; i++)
    {
        bin <<= 4;
        bin |= HEXCHR.find(hex[i]);
    }
    return bin;
}

std::string tohex(unsigned int bin)
{
    unsigned int val = 15, ext;
    std::string hex = "";
    for (int i = 0; i < 8; i++)
    {
        ext = bin & val;
        bin >>= 4;
        hex = HEXCHR[ext] + hex;
    }

    return hex;
}

void setS()
{
    for (int i; i < 18; i++)
        K[i] = tobi(hexpi());
    for (int i; i < 4; i++)
        for (int j; j < 255; j++)
            S[i][j] = tobi(hexpi());
}

void keyset(std::string key)
{
    int len = key.length();
    if (len > 56)
        key = key.substr(0, 56);
    const int ars = key.length() / 4;
    unsigned int k[ars];
    for (i = 0; i < ars; i++)
        for (int j = 0; j < 4; j++)
        {
            k[i] <<= 8;
            k[i] |= key[4 * i + j];
        }
    int j = 0;
    for (int i = 0; i < 18; i++)
    {
        K[i] ^= k[j++];
        j %= ars;
    }
}

unsigned int fop(unsigned int bin)
{
    unsigned int a[4];
    unsigned int val = 255;
    unsigned int res;
    for (int i = 0; i < 4; i++)
    {
        a[i] = S[i][bin & val];
        bin >>= 8;
    }
    res = a[0] + a[1];
    res ^= a[2];
    res += a[3];

    return res;
}

std::string totxt(unsigned int bin)
{
    std::string res;
    int val = 255, ext;
    for (int i = 0; i < 4; i++)
    {
        ext = bin & val;
        bin >>= 8;
        if (ext > 0)
            res = (char)ext + res;
    }

    return res;
}

std::string encoblock(unsigned int ls, unsigned int rs, int lev = 0)
{
    if (lev == 16)
    {
        ls ^= K[16];
        rs ^= K[17];
        return (tohex(rs) + tohex(ls));
    }
    ls ^= K[lev];
    rs ^= fop(ls);
    return encoblock(rs, ls, lev + 1);
}

std::string decoblock(unsigned int ls, unsigned int rs, int lev = 17)
{
    if (lev == 1)
    {
        ls ^= K[1];
        rs ^= K[0];
        // std::cout << totxt(rs) + totxt(ls);
        return (totxt(rs) + totxt(ls));
    }
    ls ^= K[lev];
    rs ^= fop(ls);
    return decoblock(rs, ls, lev - 1);
}

std::string encode(std::string text)
{
    std::string res;
    int lb = 0, rb = 0, j = 0;
    int len = text.length();
    while (len % 4)
    {
        text += " ";
        len++;
    }
    // std::cout << len << "\n";
    for (int i = 0; i < len; i++)
    {
        if (j < 4)
        {
            lb <<= 8;
            lb |= text[i];
        }
        else if (j < 8)
        {
            rb <<= 8;
            rb |= text[i];
        }
        if (j == 7)
        {
            res += encoblock(lb, rb);
            lb = 0;
            rb = 0;
            j = 0;
        }
        j++;
    }
    return res;
}

std::string decode(std::string text)
{
    std::string res;
    int lb = 0, rb = 0, j = 0;
    int len = text.length();
    for (int i = 0; i < len; i += 16)
    {
        lb = tobi(text.substr(i, 8));
        rb = tobi(text.substr(i + 8, 8));
        res += decoblock(lb, rb);
    }
    return res;
}

#endif
