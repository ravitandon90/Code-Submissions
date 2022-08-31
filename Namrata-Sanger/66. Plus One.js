/*
Day 13
66. Plus One
Link: https://leetcode.com/problems/plus-one/
Level : Easy
*/

/**
 * @param {number[]} digits
 * @return {number[]}
 */

var plusOne = function(digits) {
    let carrier = 1;
    for(let i=digits.length - 1; i>=0; i--){
        let add = digits[i] + carrier;
        add = add.toString();
        if(add.length > 1){
                carrier = parseInt(add[0]);    
                digits[i] = parseInt(add[1]);
        }else{
            digits[i] = parseInt(add[0]);
            carrier = 0;
            break;
        }
    }
    if(carrier){
        digits = [carrier,...digits];
    }
    return digits;
};
