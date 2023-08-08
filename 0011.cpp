// ? 11. Container With Most Water
// ? https://leetcode.com/problems/container-with-most-water/submissions/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getTwoSum(vector<int> height)
{

    int start = 0;
    int end = height.size() - 1;
    int maxCapacity = -INT_MAX;

    while (start < end)
    {
        int leftHeight = height[start];
        int rightHeight = height[end];
        int baseHeight = min(leftHeight, rightHeight);
        int capacity = (end - start) * (baseHeight);

        if (leftHeight < rightHeight)
        {
            start++;
        }
        else
        {
            end--;
        }

        maxCapacity = max(maxCapacity, capacity);
    }

    return maxCapacity;
}

int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

    int ans = getTwoSum(height);

    cout << ans << endl;
}