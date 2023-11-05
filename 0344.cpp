// ? 344. Reverse String
// ? https://leetcode.com/problems/reverse-string/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int main()
// {
//     vector<char> s{
//         'h',
//         'e',
//         'l',
//         'l',
//         'o',
//     };
//     vector<char> oth;

//     oth = s;

//     for (int i = s.size() - 1; i >= 0; i--)
//     {
//         s.at(s.size() - 1 - i) = oth[i];
//     }

//     for (auto i : s)
//     {
//         cout << i;
//     }
// }

// ! Better Solution

int main()
{
    vector<char> s{'h', 'e', 'l', 'l', 'o'};

    int start = 0;
    int last = s.size() - 1;

    while (start < last)
    {
        swap(s.at(start++), s.at(last--));
    }

    for (auto i : s)
    {
        cout << i;
    }
}