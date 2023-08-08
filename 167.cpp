// ? 167. Two Sum II - Input Array Is Sorted
// ? https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> getTwoSum(int target, vector<int> numbers)
{
    vector<int> ans;
    int start = 0;
    int end = numbers.size() - 1;

    while (true)
    {
        int sum = numbers[start] + numbers[end];

        if (sum > target)
        {
            // reduce the end pointer
            end--;
        }
        else if (sum < target)
        {
            // increase the start pointer
            start++;
        }
        else
        {
            // Incrementing the indexes to match 1-indexing for the answer
            ans.push_back(start + 1);
            ans.push_back(end + 1);
            return ans;
        }
    }
}

// Actually this is not better, infact this takes more time, but is more memory efficient
vector<int> betterTwoSum(int target, vector<int> numbers)
{
    vector<int> ans;
    int start = 0;
    int end = numbers.size() - 1;

    while (end > start)
    {
        int sum = numbers[start] + numbers[end];

        if (sum > target)
        {
            // reduce the end pointer
            end--;
        }
        else if (sum < target)
        {
            // increase the start pointer
            start++;
        }
        else
        {
            // Incrementing the indexes to match 1-indexing for the answer
            ans.push_back(start + 1);
            ans.push_back(end + 1);
            return ans;
        }
    }

    return ans;
}

int main()
{
    vector<int> numbers{2, 7, 11, 15};
    int target = 9;

    vector<int> ans = getTwoSum(target, numbers);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}