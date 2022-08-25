/*
Day 9
986. Interval List Intersections
Link : https://leetcode.com/problems/interval-list-intersections/
Level : Medium
*/

/**
 * @param {number[][]} firstList
 * @param {number[][]} secondList
 * @return {number[][]}
 */
var intervalIntersection = function(firstList, secondList) {
    let i=0,j=0;
    let intersection = [];
    while(i<firstList.length && j<secondList.length){
        let s1 = firstList[i][0];
        let s2 = secondList[j][0];
        let e1 = firstList[i][1];
        let e2 = secondList[j][1];
        
        if(s2 < e1 && s1 < e2){
            intersection.push([Math.max(s1,s2),Math.min(e1,e2)]);
        }else if(s1 == e2 && e1 > e2){
            intersection.push([s1,s1]);
        }else if(s2 == e1 && e1 < e2){
            intersection.push([e1,e1]);
        } 
        e1 < e2 ? i++ : j++;       
    }
    return intersection;
};
