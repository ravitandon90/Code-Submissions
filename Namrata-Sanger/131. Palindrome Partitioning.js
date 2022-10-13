/*
Day 30
131. Palindrome Partitioning
Link: https://leetcode.com/problems/palindrome-partitioning/submissions/
Level: Medium
*/

var partition = function(s) {
    const ret = [], path = [];
    
    const isPalindrome = (i, j, s) =>{
        while(i < j - 1){
            if(s[i] !== s[j-1]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    
    const backtrack = (i, j, s) =>{
        if(i === s.length){
            ret.push([...path]);
            return;
        }
        
        for(let index = j; index <= s.length; ++index){
            if(isPalindrome(i, index, s)){
                path.push(s.slice(i, index));
                backtrack(index, index+1, s);
                path.pop();
            }
        }
    };
    
    backtrack(0, 1, s);
    return ret;
};
