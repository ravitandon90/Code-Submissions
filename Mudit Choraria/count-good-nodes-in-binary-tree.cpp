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
    int goodNodes(TreeNode* root, int mx = INT_MIN) {
        // if the root is null, we return 0
        if(!root) {
            return 0;
        }
        // if the current node value is greater than the maximum value so far, its a good node
        return (root->val >= mx ? 1 : 0)
            // the second part is the result of the left sub-tree
            + goodNodes(root->left, max(root->val, mx))
            // the third part is the result of the right sub-tree
            + goodNodes(root->right, max(root->val, mx));
    }
};