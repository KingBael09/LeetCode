// ? 535. Encode and Decode TinyURL
// ? https://leetcode.com/problems/encode-and-decode-tinyurl/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
private:
    unordered_map<string, string> map;
    int counter = 0;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string shortUrl = "bit.ly/" + to_string(counter++);
        map[shortUrl] = longUrl;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return map[shortUrl];
    }
};

class DumbSolution
{
public:
    string encode(string longUrl)
    {
        return longUrl;
    }
    string decode(string shortUrl)
    {
        return shortUrl;
    }
};

class AnotherSolution
{
private:
    string generate(int seed = 10)
    {
        string base = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

        string result = "";

        while (seed--)
        {
            result += base[rand() % base.length()];
        }

        return result;
    }

    unordered_map<string, string> map;

public:
    string encode(string longUrl)
    {
        string shortUrl = "bit.ly/" + generate();

        map[shortUrl] = longUrl;

        return shortUrl;
    }
    string decode(string shortUrl)
    {
        return map[shortUrl];
    }
};

int main()
{
}