/*
题意：
    给定一棵二叉树的中序遍历 inorder
    和后序遍历 postorder，
    根据两个遍历序列构造原二叉树。

思路：
    后序遍历顺序是：
        左 -> 右 -> 根

    所以后序区间最后一个元素一定是当前子树根节点。

    在中序遍历中找到根节点位置：
        根左边属于左子树；
        根右边属于右子树。

    根据中序左子树的节点数量，
    再划分后序遍历中的左右子树范围，
    最后递归构造左右子树。

    使用哈希表提前记录每个节点值在 inorder 中的位置，
    避免每次递归都线性查找。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include "Algorithm_150.h"

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    unordered_map<int, int> index;

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int inLeft,
                    int inRight, int postLeft, int postRight)
    {
        // 当前子树为空
        if (inLeft > inRight)
        {
            return nullptr;
        }

        // 后序遍历最后一个节点一定是当前根节点
        int rootVal = postorder[postRight];
        TreeNode *root = new TreeNode(rootVal);

        // 根节点在中序遍历中的位置
        int rootIndex = index[rootVal];

        // 左子树节点数量
        int leftSize = rootIndex - inLeft;

        // 构造左子树
        root->left = build(inorder, postorder, inLeft, rootIndex - 1, postLeft, postLeft + leftSize - 1);

        // 构造右子树
        root->right = build(inorder, postorder, rootIndex + 1, inRight, postLeft + leftSize, postRight - 1);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            index[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, static_cast<int>(inorder.size()) - 1, 0, static_cast<int>(postorder.size()) - 1);
    }
};