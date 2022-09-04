/*
Day 17
987. Vertical Order Traversal of a Binary Tree
Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
Level : Hard
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
 * @return {number[][]}
 */


function dfs(node,obj,coOrdinates){
    if(node == null){
        return;
    }
    let leftCoOrdinates = [coOrdinates[0]+1,coOrdinates[1]-1];
    let rightCoOrdinates = [coOrdinates[0]+1,coOrdinates[1]+1];
    let level = coOrdinates[0];
    if(obj[coOrdinates[1]]){
        if(obj[coOrdinates[1]][coOrdinates[0]]){
             obj[coOrdinates[1]][coOrdinates[0]].push(node.val);
        }
        else{
            obj[coOrdinates[1]][coOrdinates[0]] = [node.val];
        }
    } else{
        obj[coOrdinates[1]] = { [coOrdinates[0]] : [node.val] } ;
    }
    dfs(node.left,obj,leftCoOrdinates);
    dfs(node.right,obj,rightCoOrdinates);
}
var verticalTraversal = function(root) {
    let coOrdinates = [0,0];
    let obj = {};
    dfs(root,obj,coOrdinates);
    
    let sorted = Object.keys(obj).sort((a,b)=> {
        return a-b;
    });
    
    obj = sorted.reduce((red,curr)=>{
        red.push(obj[curr]);
        return red;
    },[]);
    
    sorted = obj.reduce((red,curr,index)=>{
       
        let newData = Object.keys(curr).sort((a,b)=>a-b).reduce((red1,curr1)=>{
            // console.log(red1);
            red1.push(...curr[curr1].sort((a,b)=>a-b));
            return red1;
        },[]);
        red.push([...newData]);
        return red;
    },[]);
    
    return sorted;
};
