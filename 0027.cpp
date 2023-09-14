// ? 27. Remove Element
// ? https://leetcode.com/problems/remove-element/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int pos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[pos] = nums[i];
            pos++;
        }
    }

    return pos;
}

int removeElementReally(vector<int> &nums, int val)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) == val)
        {
            nums.erase(nums.begin() + i);
            i--;
        }
    }

    return nums.size();
}

int main()
{
    vector<int> v{0, 1, 2, 2, 3, 0, 4, 2};

    cout << removeElement(v, 2);
}