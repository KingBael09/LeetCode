// ? 1491. Average Salary Excluding the Minimum and Maximum Salary
// ? https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// Sort of inefficient method
double average(vector<int> &salary)
{
    sort(salary.begin(), salary.end());

    double avg = 0;

    for (int i = 1; i < salary.size() - 1; i++)
    {
        avg += salary[i];
    }

    return avg / (salary.size() - 2);
}

// No need of sorting
int betterAverage(vector<int> &salary)
{
    int mn = INT_MAX, mx = INT_MIN;

    double sum = 0;

    for (auto i : salary)
    {
        sum += i;
        mn = min(mn, i);
        mx = max(mx, i);
    }

    sum -= mn + mx;

    return sum / (salary.size() - 2);
}

int main()
{
    vector<int> salary = {4000, 3000, 1000, 2000};
    cout << average(salary);
}