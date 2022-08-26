/**
 * Problem Link - https://leetcode.com/problems/merge-two-binary-trees/
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
    TreeNode* preOrder(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return NULL;
        
        TreeNode* temp = root1;
        if(root1 != NULL && root2 != NULL) {
            root1->val = root1->val + root2->val;
        } else if (root1 == NULL) {
            root1 = root2;
        } else  {
            root1 = root1;
        }
        
        root1->left = preOrder(temp ? temp->left: NULL, root2 ? root2->left : NULL);
        root1->right = preOrder(temp ? temp->right : NULL, root2 ? root2->right : NULL);
        
        return root1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        
        TreeNode* root = new TreeNode();
        TreeNode* ans =  preOrder(root1, root2);
       
        return ans;
    }
};