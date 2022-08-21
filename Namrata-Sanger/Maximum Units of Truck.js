/*
Day 4
1710. Maximum Units on a Truck
Link : https://leetcode.com/problems/maximum-units-on-a-truck/
*/


/**
 * @param {number[][]} boxTypes
 * @param {number} truckSize
 * @return {number}
 */
var maximumUnits = function(boxTypes, truckSize) {
    boxTypes.sort((a,b)=> {
        return b[1] - a[1]
    });
    let units = 0;
    for(let i = 0; i < boxTypes.length; i++){
        if(truckSize - boxTypes[i][0] > 0){
            units = units +  boxTypes[i][0] * boxTypes[i][1];
            truckSize = truckSize - boxTypes[i][0];
        }else{
            units = units + boxTypes[i][1] * truckSize;
            truckSize = 0;
        }
    }
    return units;
};
