/*
题意：
    给定字符串 s，
    忽略所有非字母数字字符，
    并且忽略字母大小写，
    判断处理后的字符串是否为回文串。

思路：
    使用双指针。

    left 从字符串左边开始，
    right 从字符串右边开始。

    如果 left 指向的字符不是字母或数字，
    就向右移动。

    如果 right 指向的字符不是字母或数字，
    就向左移动。

    当左右两边都指向有效字符时，
    将它们转成小写后比较。

    如果不同，返回 false；
    如果相同，继续向中间移动。

    当 left >= right 时，
    说明所有字符都匹配，返回 true。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};