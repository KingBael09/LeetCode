// ? 365. Water and Jug Problem
// ? https://leetcode.com/problems/water-and-jug-problem/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
{
    const int steps[] = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};

    int total = jug1Capacity + jug2Capacity;

    deque<int> q;

    vector<bool> visited(total + 1, false);

    q.push_back(0);

    visited[0] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop_front();

        if (curr == targetCapacity)
        {
            return true;
        }

        for (auto const &action : steps)
        {
            int new_curr = curr + action;

            if (new_curr >= 0 && new_curr <= total && !visited[new_curr])
            {
                q.push_back(new_curr);
                visited[new_curr] = true;
            }
        }
    }

    return false;
}

bool canMeasureWater2(int jug1Capacity, int jug2Capacity, int targetCapacity)
{
    int answer = gcd(jug1Capacity, jug2Capacity);

    return targetCapacity % answer == 0 && (jug1Capacity + jug2Capacity >= targetCapacity);
}

int main()
{
}