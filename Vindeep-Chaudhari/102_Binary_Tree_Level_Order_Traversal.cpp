/**
 * Problem Link - https://leetcode.com/problems/binary-tree-level-order-traversal
 */

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
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;
        
        queue <TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            int n = q.size();
            
            vector<int> level;
            
            for(int i = 0; i < n; i++) {
                TreeNode* popped = q.front();
                q.pop();
                level.push_back(popped->val);
                
                if(popped->left) {
                    q.push(popped->left);
                }
                
                if(popped->right) {
                    q.push(popped->right);
                }
            }   
            
            ans.push_back(level);
        }
        
        return ans;
    }
};