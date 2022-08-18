/*
242. Valid Anagram
Link :  https://leetcode.com/problems/valid-anagram/submissions/
*/

/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */

/* Solution 1 */
var isAnagram = function(s, t) {
    let xor = 0;
    let hashmap = {};
    if(s.length === t.length){
        for(let i=0; i<s.length; i++){
           hashmap[s[i]] =  hashmap[s[i]] ? hashmap[s[i]]+1 : 1;
        }
        for(let i=0; i<t.length; i++){
            if(hashmap[t[i]] && (hashmap[t[i]] -1) > -1){
                hashmap[t[i]] = hashmap[t[i]] - 1;
            }else{
                return false;
            }
        }
    }else{
            return false;
    }
    return true;
};


/* Solution 2 */
var isAnagram = function(s, t) {
    s = s.split("").sort().join("");
    t = t.split("").sort().join("");
    
    return s === t;
};
