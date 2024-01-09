// ? 384. Shuffle an Array
// ? https://leetcode.com/problems/shuffle-an-array/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
private:
    vector<int> orignal;

public:
    Solution(vector<int> &nums)
    {
        this->orignal = nums;
    }

    vector<int> reset()
    {
        return this->orignal;
    }

    vector<int> shuffle()
    {
        vector<int> shuffled = orignal;
        int size = shuffled.size();
        for (int i = 0; i < size; i++)
        {
            int j = rand() % size;
            swap(shuffled[i], shuffled[j]);
        }

        return shuffled;
    }
};

int main()
{
}