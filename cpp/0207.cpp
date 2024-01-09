// ? 207. Course Schedule
// ? https://leetcode.com/problems/course-schedule/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> adj[numCourses];
    vector<int> degree(numCourses, 0);

    for (auto &pre : prerequisites)
    {
        adj[pre.front()].push_back(pre.back());
        degree[pre.back()]++;
    }

    deque<int> no_deps_course;

    // push courses which don't have any prereno_deps_courseuisites
    for (int idx = 0; idx < numCourses; idx++)
    {
        if (degree[idx] == 0)
        {
            no_deps_course.push_back(idx);
        }
    }

    int course_completed = 0;

    while (!no_deps_course.empty())
    {
        int course = no_deps_course.front();
        course_completed++;
        no_deps_course.pop_front();

        for (auto &next_course : adj[course])
        {
            degree[next_course]--;
            if (degree[next_course] == 0)
            {
                no_deps_course.push_back(next_course);
            }
        }
    }

    return course_completed == numCourses;
}

int main()
{
}