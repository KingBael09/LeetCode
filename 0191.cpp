// ? https://leetcode.com/problems/number-of-1-bits/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int main()
// {
//     uint32_t n = 00000000000000000000000000001011;
//     string str;
//     str = bitset<32>(n).to_string();
//     int count = 0;

//     for (int i = 0; i <= str.length() - 1; i++)
//     {
//         if (str[i] == '1')
//         {
//             count++;
//         }
//     }

//     return count;
// }

// ! Better Approach

int main()
{
    uint32_t n = 00000000000000000000000000001011;
    int count = 0;
    while (n != 0)
    {
        count += n & 1;
        n >>= 1;
    }
}
