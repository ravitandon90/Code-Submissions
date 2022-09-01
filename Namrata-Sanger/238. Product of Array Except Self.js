/*
Day 14
238. Product of Array Except Self
Link: https://leetcode.com/problems/product-of-array-except-self/
Level: Medium
*/

/*
 * @param {number[]} nums
 * @return {number[]}
*/

// time complexity - O(n)
// space complexity - O(1)
var productExceptSelf = function(nums) {
    let product = new Array(nums.length).fill(1);
    let mul = 1;
    
    for(let i=0; i<nums.length; i++){
        mul = mul  * nums[i];
        product[i] = mul ;
    }
    
    mul = 1;
    //calculating the product
    for(let i=nums.length-1; i>0; i--){
        product[i] = mul * product[i-1];
        mul *= nums[i];
    }
    product[0] = mul;
    return product;
};
