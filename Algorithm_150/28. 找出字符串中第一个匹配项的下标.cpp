/*
题意：
    给定两个字符串 haystack 和 needle，
    返回 needle 在 haystack 中第一次出现的下标。

    如果 needle 不是 haystack 的子串，
    返回 -1。

思路：
    枚举 haystack 中所有可能作为匹配起点的位置 i。

    对每个起点 i，
    从 needle 的第一个字符开始逐个比较：

        haystack[i + j]
        和
        needle[j]

    如果所有字符都相同，
    说明从 i 开始成功匹配，
    直接返回 i。

    如果所有可能起点都没有匹配成功，
    返回 -1。

时间复杂度：O((n - m + 1) * m)，最坏 O(n * m)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        // needle 比 haystack 长，不可能匹配
        if (m > n)
        {
            return -1;
        }

        // 枚举所有可能的匹配起点
        for (int i = 0; i <= n - m; ++i)
        {
            int j = 0;

            // 从当前位置开始逐字符匹配
            while (j < m && haystack[i + j] == needle[j])
            {
                ++j;
            }

            // needle 全部匹配成功
            if (j == m)
            {
                return i;
            }
        }

        return -1;
    }
};