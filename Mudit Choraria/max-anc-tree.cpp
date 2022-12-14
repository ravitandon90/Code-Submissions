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
    int ans = 0;
    void maxAnc(TreeNode* root, int currMax, int currMin) {
        if(root == nullptr) {
            return;
        }
        ans = max(ans, abs(currMax - root->val));
        ans = max(ans, abs(currMin - root->val));
        currMax = max(currMax, root->val);
        currMin = min(currMin, root->val);
        maxAnc(root->left, currMax, currMin);
        maxAnc(root->right, currMax, currMin);
    }
    int maxAncestorDiff(TreeNode* root) {
        maxAnc(root, root->val, root->val);
        return ans;
    }
};