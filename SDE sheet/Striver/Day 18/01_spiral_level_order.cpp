// letcode

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        s1.push(root);
        vector<int> v;
        while(!s1.empty() || !s2.empty()) {
            v.clear();
            while(!s1.empty()) {
                TreeNode* temp = s1.top();
                s1.pop();
                v.push_back(temp->val);
                
                if(temp->left) {
                    s2.push(temp->left);
                }
                if(temp->right) {
                    s2.push(temp->right);
                }
            }
            while(!s2.empty()) {
                TreeNode* temp = s2.top();
                s2.pop();
                s1.push(temp);
            }
            res.push_back(v);
        }
    return res;   
    }
};








