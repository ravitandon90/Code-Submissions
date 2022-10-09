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
    bool ans = false;
    set<int> s;
    void tr(TreeNode* root, int k) {
        if(root == nullptr) {
            return;
        }
        if(s.count(root->val)) {
            ans = true;
            return;
        }
        s.insert(k - root->val);
        tr(root->left, k);
        tr(root->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        tr(root, k);
        return ans;
    }
};