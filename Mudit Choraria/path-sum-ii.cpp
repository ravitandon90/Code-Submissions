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
    vector<vector<int>> ans;
    void traverse(TreeNode* root, int targetSum, vector<int>& path) {
        if(!root) {
            return;
        }
        path.push_back(root->val);
        if(root->val == targetSum && !root->left && !root->right) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        traverse(root->left, targetSum - root->val, path);
        traverse(root->right, targetSum - root->val, path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        traverse(root, targetSum, path);
        return ans;
    }
};