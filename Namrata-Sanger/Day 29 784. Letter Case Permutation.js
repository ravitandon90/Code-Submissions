/*
Day 29
784. Letter Case Permutation
Level : Medium
Link: https://leetcode.com/problems/letter-case-permutation/
*/
var letterCasePermutation = function(s) {
    
    let res = [];
    
    let len = s.length;
    
    const backTrack = (computed, pending) => {
        if(computed.length == len) { // we can match and exit
            res.push(computed);
            return;
        } 
        for(let g=0; g<pending.length; g++){
            let cur = pending[g];
            if(!isNaN(cur))// digits
                computed = computed + cur;
            else {
                backTrack(computed + cur.toLowerCase(), pending.slice(g+1));  // lower case
                backTrack(computed + cur.toLowerCase().toUpperCase(), pending.slice(g+1)); //uppercase
            }
        }
        if(computed.length ==len) res.push(computed) // if only digits
    }
    
    backTrack('', s)
    
    return res;
};
