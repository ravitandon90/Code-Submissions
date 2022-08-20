class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        // sort by desc order of num of units per box
        // because we have a limit on the number of boxes, not units
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes), cmp);
        int maxUnits = 0;
        for(auto& box: boxTypes) {
            if(truckSize <= 0) {
                break;
            }
            maxUnits += min(truckSize, box[0]) * box[1];
            truckSize -= box[0];
        }
        return maxUnits;
    }
};

// TC: O(N log N), where N is the size of boxTypes
// SC: O(1)