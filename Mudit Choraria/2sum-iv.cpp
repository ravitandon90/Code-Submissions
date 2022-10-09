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
//  https://www.youtube.com/watch?v=ssL3sHwPeb4

class BSTIterator {
private:
    stack<TreeNode*> myStack;
    bool reverse;
    
    void pushAll(TreeNode* root) {
        while(root) {
            myStack.push(root);
            root = reverse ? root->right : root->left;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmp = myStack.top();
        myStack.pop();
        reverse ? pushAll(tmp->left) : pushAll(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        while(i < j) {
            if(i + j == k) {
                return true;
            } else if(i + j > k) {
                j = r.next();
            } else {
                i = l.next();
            }
        }
        return false;
    }
};