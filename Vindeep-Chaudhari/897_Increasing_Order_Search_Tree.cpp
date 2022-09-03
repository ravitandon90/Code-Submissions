/**
 * Problem Link - https://leetcode.com/problems/increasing-order-search-tree/
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
    TreeNode* ans;
    void inOrderTraversal(TreeNode* root) {
        if(root == NULL) return;
        
        inOrderTraversal(root->left);
        root->left = NULL;
        ans->right = root;
        ans = root;
        inOrderTraversal(root->right);     
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummyNode = new TreeNode(-1);
        ans = dummyNode;
        
        inOrderTraversal(root);
        
        return dummyNode->right;
    }
};