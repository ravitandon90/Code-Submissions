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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxSumDown(root);
        return ans;
    }
private:
    int maxSumDown(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int leftPathSum = max(0, maxSumDown(root->left));
        int rightPathSum = max(0, maxSumDown(root->right));
        ans = max(ans, root->val + leftPathSum + rightPathSum);
        return root->val + max(leftPathSum, rightPathSum);
    }
};