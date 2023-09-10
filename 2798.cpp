// ? 2798. Number of Employees Who Met the Target
// ? https://leetcode.com/problems/number-of-employees-who-met-the-target/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
{
    int count = 0;

    for (auto i : hours)
    {
        if (i >= target)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    // TOO lazy to write driver code
}