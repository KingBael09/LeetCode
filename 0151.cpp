// ? 151. Reverse Words in a String
// ? https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// Not a good solution
string reverseWords(string s)
{
    stack<string> st;
    s += ' ';
    int start = 0, end = 0;

    while (s[start] == ' ')
    {
        start++;
    }
    end = start;

    for (int i = end; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            st.push(s.substr(start, i - start + 1));
            start = i + 1;
            while (s[start] == ' ')
            {
                start++;
            }
            while (s[i] == ' ')
            {
                i++;
            }
        }
    }

    s.clear();

    while (!st.empty())
    {
        s.append(st.top());
        st.pop();
    }

    s.pop_back();

    return s;
}

vector<string> split(string s)
{
    vector<string> v;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        v.push_back(word);
    }

    return v;
}

string reverseWordsBetter(string s)
{
    vector<string> v = split(s);

    s.clear();

    for (int i = v.size() - 1; i >= 0; i--)
    {
        s.append(v[i] + ' ');
    }

    s.pop_back();

    return s;
}

/**
 *  Other Method
 */

stack<string> splitStack(string s)
{
    stack<string> st;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        st.push(word);
    }

    return st;
}

string reverseWordsBetterWithStack(string s)
{
    stack<string> st = splitStack(s);

    s.clear();

    while (!st.empty())
    {
        s += st.top() + ' ';
        st.pop();
    }

    s.pop_back();

    return s;
}

int main()
{
    // cout << reverseWords("a good   example");
    cout << reverseWordsBetter("   a good   example");
}