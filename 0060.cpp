// ? 60. Permutation Sequence
// ? https://leetcode.com/problems/permutation-sequence/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string getPermutation(int n, int k)
{
    string s;
    for (int i = 0; i < n; i++)
    {
        s.push_back(i + '1');
    }

    while (--k)
    {
        next_permutation(s.begin(), s.end());
    }

    return s;
}

string anotherGetPermutation(int n, int k)
{
    string s(n, '0');

    iota(s.begin(), s.end(), '1');

    while (--k)
    {
        next_permutation(s.begin(), s.end());
    }

    return s;
}

/*--------------------------------------------Brute Force--------------------------------------------*/

void helper(int idx, string &s, vector<string> &ans, int n)
{
    if (idx == n)
    {
        ans.push_back(s);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        swap(s[idx], s[i]);
        helper(idx + 1, s, ans, n);
        swap(s[idx], s[i]);
    }
}

string getPermutationBruteForce(int n, int k)
{
    string s(n, '0');
    vector<string> ans;

    iota(s.begin(), s.end(), '1');

    helper(0, s, ans, n);
    sort(ans.begin(), ans.end());

    return ans[k - 1];
}

/*--------------------------------------------Optimal--------------------------------------------*/

string getPermutationOptimal(int n, int k)
{
    int fact = 1;

    vector<int> numbers;

    for (int i = 1; i < n; i++)
    {
        fact *= i;
        numbers.push_back(i);
    }

    numbers.push_back(n);

    string ans = "";

    k--;

    while (true)
    {
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);

        if (numbers.empty())
        {
            break;
        }

        k %= fact;
        fact /= numbers.size();
    }

    return ans;
}

int main()
{
    cout << getPermutationBruteForce(3, 3);
}