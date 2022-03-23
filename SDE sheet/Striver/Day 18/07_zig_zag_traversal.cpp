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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s2.push(root);
        vector<int> v;
        while (!s1.empty() || !s2.empty()) {
            while(!s1.empty()) {
                TreeNode* temp = s1.top();
                v.push_back(temp->val);
                s1.pop();
                if(temp->right) {
                    s2.push(temp->right);
                }
                if(temp->left) {
                    s2.push(temp->left);
                }
            }
            if(v.size() > 0) {
                res.push_back(v);
            }
            
            v.clear();
            while(!s2.empty()) {
                TreeNode* temp = s2.top();
                v.push_back(temp->val);
                s2.pop();
                if(temp->left) {
                    s1.push(temp->left);
                }
                if(temp->right) {
                    s1.push(temp->right);
                }
            }
            if(v.size() > 0) {
             res.push_back(v);   
            }
            
            v.clear();
        }
        return res;
    }
};