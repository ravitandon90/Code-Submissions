/*
Day 8
274. H-Index
Link: https://leetcode.com/problems/h-index/
Level:  Medium
*/

/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function(citations) {
    let flag = false;
    citations = citations.sort((a,b)=>a-b);
    let loop_counter = citations[citations.length-1];
    while(!flag){
        let condition = citations.filter(d => d >= loop_counter).length >= loop_counter;
        if(!condition){
            loop_counter--;
        }
        flag = condition;
    }
    return loop_counter;
};
