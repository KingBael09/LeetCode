// ? 1189. Maximum Number of Balloons
// ? https://leetcode.com/problems/maximum-number-of-balloons/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// This might be the dumbest solution ever, but hey it works!
int maxNumberofBalloons(string text)
{
    unordered_map<char, int> m{
        {'b', 0},
        {'a', 0},
        {'l', 0},
        {'l', 0},
        {'o', 0},
        {'o', 0},
        {'n', 0},

    };

    int count = INT_MAX;

    for (int i = 0; i < text.length(); i++)
    {

        if (m.find(text[i]) != m.end())
        {
            m[text[i]]++;
        }
    }

    for (auto i : m)
    {
        if (i.first == 'l' || i.first == 'o')
        {
            count = min(i.second / 2, count);
        }
        else
        {
            count = min(i.second, count);
        }
    }

    return count;
}

int maxNumberOfBaloonsFaster(string text)
{
    int b = 0, a = 0, l = 0, o = 0, n = 0;

    for (int i = 0; i < text.length(); i++)
    {
        {
            if (text[i] == 'b')
                b++;
            else if (text[i] == 'a')
                a++;
            else if (text[i] == 'l')
                l++;
            else if (text[i] == 'o')
                o++;
            else if (text[i] == 'n')
                n++;
        }
    }

    l /= 2; // balloon contains 2 l's
    o /= 2; // balloon contains 2 o's

    return min({b, a, l, o, n});
}

int main()
{
    string s = "krhizmmgmcrecekgyljqkldocicziihtgpqwbticmvuyznragqoyrukzopfmjhjjxemsxmrsxuqmnkrzhgvtgdgtykhcglurvppvcwhrhrjoislonvvglhdciilduvuiebmffaagxerjeewmtcwmhmtwlxtvlbocczlrppmpjbpnifqtlninyzjtmazxdbzwxthpvrfulvrspycqcghuopjirzoeuqhetnbrcdakilzmklxwudxxhwilasbjjhhfgghogqoofsufysmcqeilaivtmfziumjloewbkjvaahsaaggteppqyuoylgpbdwqubaalfwcqrjeycjbbpifjbpigjdnnswocusuprydgrtxuaojeriigwumlovafxnpibjopjfqzrwemoinmptxddgcszmfprdrichjeqcvikynzigleaajcysusqasqadjemgnyvmzmbcfrttrzonwafrnedglhpudovigwvpimttiketopkvqw";
    cout << maxNumberofBalloons(s);
}