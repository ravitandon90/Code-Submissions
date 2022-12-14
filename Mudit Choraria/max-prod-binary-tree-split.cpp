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
    vector<int> allSums;
    long ans = 0;
    long MOD = 1e9 + 7;
    long sum(TreeNode* root) {
        if(root == nullptr) {
           return 0;
        }
        long left = sum(root->left);
        long right = sum(root->right);
        allSums.push_back(root->val + left + right);
        return allSums.back();
    }
    int maxProduct(TreeNode* root) {
        long totalSum = sum(root);
        for (const long sum : allSums) {
            ans = max(ans, sum * (totalSum - sum));
        }
      
        return ans % MOD;
    }
};