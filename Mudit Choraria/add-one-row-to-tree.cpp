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



/* 
// SOLUTION 1
class Solution {
public:
    void addRow(TreeNode* root, int val, int depth) {
        if(root == nullptr) {
            return;
        }
        if(depth == 2) {
            TreeNode* head = new TreeNode(val);
            head->left = root->left;
            root->left = head;
            
            head = new TreeNode(val);
            head->right = root->right;
            root->right = head;
            
            return;
        } else {
            addRow(root->left, val, depth - 1);
            addRow(root->right, val, depth - 1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* head = new TreeNode(val);
            head->left = root;
            return head;
        }
        addRow(root, val, depth);
        return root;
    }
};
*/

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth, bool isLeft = true) {
        if(depth == 1) {
            TreeNode* left = isLeft ? root : nullptr;
            TreeNode* right = isLeft ? nullptr : root;
            return new TreeNode(val, left, right);
        }
        
        if(root) {
            root->left = addOneRow(root->left, val, depth - 1, true);
            root->right = addOneRow(root->right, val, depth - 1, false);
        }
            
        return root;
    }
};