/**
 * Problem Link - https://leetcode.com/problems/maximum-units-on-a-truck/
 */

class Solution {
public:
    static bool sortDesc( vector<int> &a,vector<int> &b) {
       return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), sortDesc);
        
        int noOfBoxes = 0;
        for(int i = 0; i < boxTypes.size(); i++) {
            if(truckSize <= 0) break;
            
            if(truckSize <= boxTypes[i][0]) {
                noOfBoxes += truckSize * boxTypes[i][1];
                truckSize -= truckSize;
            } else {
                noOfBoxes += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
        }
        
        return noOfBoxes;
    }
};