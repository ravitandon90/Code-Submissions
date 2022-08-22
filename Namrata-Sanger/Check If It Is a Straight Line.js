/*
Day 6
1232. Check If It Is a Straight Line
Link: https://leetcode.com/problems/check-if-it-is-a-straight-line/
*/


/**
 * @param {number[][]} coordinates
 * @return {boolean}
 */

/*

(y2-y1)/(x2-x1) == (y3-y2)/(x3-x2)
the below condition will avoid divide by 0 calculation.
condition to check : (y2-y1) * (x3-x2) == (y3-y2) * (x2-x1)

*/
var checkStraightLine = function(coordinates) {
    let y_difference = (coordinates[1][1] - coordinates[0][1]);
    let x_difference = (coordinates[1][0]- coordinates[0][0])
    let i = 2;
    while(i < coordinates.length){
        let lhs = y_difference * ( coordinates[i][0]-coordinates[i-1][0]);
        let rhs = x_difference * (coordinates[i][1]-coordinates[i-1][1]);
        if(lhs != rhs){
            return false;
        }
        i = i+1;
    }
    return true;
};
