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
// solution 1
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

// solution 2
var rangeSumBST = function(root, low, high) {
    let left = 0, right = 0;
    
    if(root == null){
        return 0;
    }
    
    left = rangeSumBST(root.left,low,high);
    right = rangeSumBST(root.right,low,high);
    
    return left + right + (root.val >= low && root.val <= high ? root.val : 0);
};

// solution 3
var rangeSumBST = function(root, low, high) {
    let left = 0, right = 0 ;
    
    if(root == null){
        return 0;
    }
    if(root.val > low ){
         left = rangeSumBST(root.left,low,high);
    }
        console.log(root.val);

    if(root.val < high){
        right = rangeSumBST(root.right,low,high);    
    }
    return left + right + (root.val >= low && root.val <= high ? root.val : 0);
};
