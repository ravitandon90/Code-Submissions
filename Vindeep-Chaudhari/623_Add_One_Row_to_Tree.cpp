/**
 * Problem Link - https://leetcode.com/problems/add-one-row-to-tree/
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL) {
            if (depth == 1)
                return new TreeNode(val);
            else 
                return NULL;
        } 
        
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;
            newRoot -> right = NULL;
            return newRoot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int curDepth = 1;
        while(q.empty() == false) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();

                
                if(curDepth == depth - 1) {
                    TreeNode* tempLeft = curr->left;
                    curr->left = new TreeNode(val);
                    curr->left->left = tempLeft;
                    
                    TreeNode* tempRight = curr->right;
                    curr->right = new TreeNode(val);
                    curr->right->right = tempRight;
                } else {
                    if(curr->left) {
                        q.push(curr->left);
                    }
                
                    if(curr->right) {
                        q.push(curr->right);
                    }
                }
                  
            }
            
            if(curDepth == depth - 1) {
                break;
            }
            
            curDepth++;

        }
        
        return root;
    }
};
