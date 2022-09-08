/*
Day 20
414. Third Maximum Number
Link: https://leetcode.com/problems/third-maximum-number/
Level: Easy 
*/

var thirdMax = function(nums) {
  let len = nums.length;
  
  nums.sort((a, b) => b - a);
  
  let count = 0;
  for (let i = 0; i < len; i++) {
    if (!nums[i+1] || nums[i] !== nums[i+1]) {
      count++;
      if (count === 3) return nums[i];
    }
  }

  return nums[0];
};
