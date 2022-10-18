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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return 0;
        }
        return traverse(root, targetSum)
            + pathSum(root->left, targetSum)
            + pathSum(root->right, targetSum);
    }
private:
    int traverse(TreeNode* root, long targetSum) {
        if(!root) {
            return 0;
        }
        return (targetSum == root->val)
            + traverse(root->left, targetSum - root->val)
            + traverse(root->right, targetSum - root->val);
    }
};