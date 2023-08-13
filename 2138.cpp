// ? 2138. Divide a String Into Groups of Size k
// ? https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> getAnswer(string s, int k, char fill)
{
    vector<string> ans;

    int len = s.length();
    int rem = len % k;

    int feasibleLen = len - rem;

    int itr = 0;

    while (itr < feasibleLen)
    {
        ans.push_back(s.substr(itr, k));

        itr = itr + k;
    }

    if (rem > 0)
    {
        string temp = s.substr(feasibleLen);

        while (temp.length() < k)
        {
            temp.push_back(fill);
        }

        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    string s = "abcdefghij";
    char fill = 'x';

    int k = 3;

    vector<string> ans = getAnswer(s, k, fill);

    for (auto i : ans)
    {
        cout << i << endl;
    }
}