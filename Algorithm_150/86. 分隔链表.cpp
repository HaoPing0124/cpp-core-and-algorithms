/*
题意：
    给定链表 head 和整数 x，
    将链表分成两个部分：

        1. 所有小于 x 的节点放在前面；
        2. 所有大于等于 x 的节点放在后面。

    同时要求保持两个分区中节点原来的相对顺序。

思路：
    使用两个虚拟头结点分别构造两条链表。

    smallDummy：
        保存所有值 < x 的节点。

    largeDummy：
        保存所有值 >= x 的节点。

    遍历原链表：
        如果当前节点值 < x，
        就接到 small 链表尾部；

        否则，
        接到 large 链表尾部。

    遍历结束后：
        将 small 链表尾部连接到 large 链表头部。

    最后必须把 large 链表尾部的 next 设为 nullptr，
    防止保留原链表中的旧连接形成错误链路或环。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode smallDummy(0);
        ListNode largeDummy(0);

        ListNode *small = &smallDummy;
        ListNode *large = &largeDummy;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                large->next = head;
                large = large->next;
            }

            head = head->next;
        }

        // 防止 large 尾节点保留原链表中的旧 next
        large->next = nullptr;

        // 小链表后面接大链表
        small->next = largeDummy.next;

        return smallDummy.next;
    }
};