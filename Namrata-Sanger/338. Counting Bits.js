/*
Day 34
338. Counting Bits
Link: https://leetcode.com/problems/counting-bits/submissions/
Level: Easy
*/

/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) {
    let arr =[]
    if(n==0)
        arr=[0]
    if(n==1)
        arr=[0,1]
    if(n>1){
        arr=[0,1]
    for(let i=2;i<=n;i++){
        let val = countOne(i)
        arr.push(val)
    }
    }
    return arr
};

function countOne(val){
    let c=0;
    while(val>0){
      if(val%2===1)
          c++;
     val=val>>1
    }
    return c;
}
