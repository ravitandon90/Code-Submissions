/*
Day 15
307. Range Sum Query - Mutable
Link: https://leetcode.com/problems/range-sum-query-mutable/
Level: Medium
*/

var NumArray = function (nums) {
    this.arr = nums;
    this.sum = 0;

    for (let val of this.arr) { this.sum += val }
};

NumArray.prototype.update = function (index, val) {
    this.sum = this.sum - this.arr[index] + val;
    this.arr[index] = val;
    return null;
};

NumArray.prototype.sumRange = function (left, right) {
    let totalElementRequired = right - left + 1;

    if (this.arr.length == totalElementRequired) { return this.sum }
    else {
        let s1 = 0;
        let s2 = 0;
        let total = 0;

        for (let i = 0; i < left; i++) {
            s1 += this.arr[i];
        }
        for (let j = (right + 1); j < this.arr.length; j++) {
            s2 += this.arr[j];
        }

        total = this.sum - (s1 + s2);
        return total
    }
};
