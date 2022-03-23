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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool isFirst = true;
        
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            
            if (!t) {
                isFirst = true;
                if (q.size() != 0) {
                    q.push(NULL);
                }
            } else {
                if (isFirst) {
                    res.push_back(t->val);
                    isFirst = false;
                }
                if (t->left) {
                    q.push(t->left);
                }
                
                if (t->right) {
                    q.push(t->right);
                }
                
            }
        }
        return res;
    }
};























