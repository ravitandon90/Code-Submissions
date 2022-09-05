/**
 * @param {string} s
 * @param {number[]} shifts
 * @return {string}
 */
 /*
 Day 18
 848. Shifting Letters
 Link: https://leetcode.com/problems/shifting-letters/
 Level: Medium
 */
var shiftingLetters = function(s, shifts) {
    let sum = 0;
    for(let i = shifts.length-1; i>=0; i--){
        sum += shifts[i]%26;
        shifts[i] = String.fromCharCode((sum+s.charCodeAt(i) - 97) % 26 + 97);
    }
    return shifts.join('');
    
};
