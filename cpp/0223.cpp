// ? 223. Rectangle Area
// ? https://leetcode.com/problems/rectangle-area/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int area1 = (ax2 - ax1) * (ay2 - ay1);
    int area2 = (bx2 - bx1) * (by2 - by1);

    // Max of left extremes and min of right extremes.
    int common_x1 = max(ax1, bx1);
    int common_y1 = max(ay1, by1);
    int common_x2 = min(ax2, bx2);
    int common_y2 = min(ay2, by2);

    int common_area = 0;
    if (common_x1 < common_x2 && common_y1 < common_y2)
    {
        common_area = (common_x2 - common_x1) * (common_y2 - common_y1);
    }

    return area1 + area2 - common_area;
}

int computeAreaMinified(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

    if (!(bx1 >= ax2 || bx2 <= ax1 || by1 >= ay2 || by2 <= ay1))
    {
        area -= (min(ax2, bx2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1));
    }

    return area;
}

int main()
{
}