// ? 341. Flatten Nested List Iterator
// ? https://leetcode.com/problems/flatten-nested-list-iterator/description

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
private:
    int idx;
    vector<int> flatList;
    vector<NestedInteger> nestedList;

    void flattinator(vector<NestedInteger> &nestedList)
    {

        for (auto &ni : nestedList)
        {
            if (ni.isInteger())
            {
                flatList.push_back(ni.getInteger());
            }
            else
            {
                auto li = ni.getList();
                flattinator(li);

                // flattinator(ni.getList()); // This complains about not being refrence but takes less memory as is
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        this->idx = 0;
        this->nestedList = nestedList;
        flattinator(nestedList);
    }

    int next()
    {
        return flatList[idx++];
    }

    bool hasNext()
    {
        return idx < flatList.size();
    }
};

int main()
{
}