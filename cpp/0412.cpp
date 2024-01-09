// ? 412. Fizz Buzz
// ? https://leetcode.com/problems/fizz-buzz/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 15;
    vector<string> answer;

    for (int i = 0; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            answer.push_back("FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            answer.push_back("Fizz");
        }
        else if (i % 5 == 0)
        {
            answer.push_back("Buzz");
        }
        else
        {
            string curStr = to_string(i);
            answer.push_back(curStr);
        }
    }

    for (auto z : answer)
    {
        cout << z << endl;
    }
}