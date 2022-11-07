// leetcode

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int solve(TreeNode *root, int &m)
    {
        if (!root)
            return 0;

        int l = max(0, solve(root->left, m));
        int r = max(0, solve(root->right, m));
        if (m < root->val + l + r)
        {
            m = root->val + l + r;
        }
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;

        int m = INT_MIN;
        solve(root, m);
        return m;
    }
};