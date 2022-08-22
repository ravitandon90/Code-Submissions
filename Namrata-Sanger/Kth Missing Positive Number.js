
/*
Day 5
1539. Kth Missing Positive Number
Leet code: https://leetcode.com/problems/kth-missing-positive-number/
*/

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
// time complexity  - O(N)
var findKthPositive = function(arr, k) {
    let number = 1;
    let digit;
    while(k>0){
        if(!arr.includes(number)){
            digit = number;
            k--;
        }
        number++;
    }
    return digit;
};


// time complexity  - O(logN)
var findKthPositive = function(arr, k) {
    let low = 0;
    let high = arr.length - 1;
    let closetMid = 0;
    while(low <= high){
        let mid = low + Math.floor((high - low)/2);
        if(arr[mid] - (mid+1) < k){
            closetMid = mid + 1;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return k + closetMid;
};
