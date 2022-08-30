/*
Day 12
938. Range Sum of BST
Link: https://leetcode.com/problems/range-sum-of-bst/
Level : Easy
*/


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var rangeSumBST = function(root, low, high) {
    let add = 0;
    
    let BST = function(root, low, high) {
        if(root == null){
            return add;
        }  
        if(root.val >= low && root.val <= high){
            add += root.val;
        }
        BST(root.left,low,high);
        BST(root.right,low,high);
    }
    
    BST(root,low,high);
    return add;
};
