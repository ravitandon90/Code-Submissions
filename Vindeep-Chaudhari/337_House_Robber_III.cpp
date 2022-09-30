/**
 * Problem Link - https://leetcode.com/problems/house-robber-iii/
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
    int robDFS(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if(root == NULL) return 0;
        
        if(dp.count(root)) return dp[root];
        int dontRob = robDFS(root -> left, dp) + robDFS(root -> right, dp);
        int robRoot = root -> val;
        
        if(root -> left) robRoot += robDFS(root -> left -> left, dp) + robDFS(root -> left -> right, dp);
        if(root -> right) robRoot += robDFS(root -> right -> left, dp) + robDFS(root -> right -> right, dp);
        return dp[root] = max(dontRob, robRoot);
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        
        return robDFS(root, dp);
    }
};