// ? 1. Two Sum
// ? https://leetcode.com/problems/two-sum/

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

//! O(n^2) Solution

#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// int main()
// {
//     int arr[10] = {1, 2, 55, 6, 7, 8, 9, 3, 19, 13};

//     int target = 12;

//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = i + 1; j < 10; j++)
//         {
//             if (arr[i] + arr[j] == target)
//             {
//                 cout << i << " => " << arr[i] << " " << j << " => " << arr[j] << " is equal to : " << target << endl;
//             }
//         }
//     }
// }

//! Second Approach

int main()
{
    int target = 9;
    vector<int> arr = {2, 7, 11, 15};

    unordered_map<int, int> umap;

    vector<int> ar;
    int len = arr.size();

    for (int i = 0; i < len; i++)
    {
        int n = arr[i];
        int counter = target - n;

        // umap[n]= i because algo must look into the available map so that it dosen't find iteself
        if (umap.count(counter))
        {
            ar.push_back(umap[counter]);
            ar.push_back(i);
        }
        umap[n] = i;
    }

    for (auto x : ar)
    {
        cout << x << " ";
    }
}
