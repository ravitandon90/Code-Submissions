/**
 * Problem Link - https://leetcode.com/problems/check-if-it-is-a-straight-line/
 */

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2) return true;

        auto pointOne = coordinates[0];
        auto pointTwo = coordinates[1];
        
        int dx = pointTwo[0] - pointOne[0];
        int dy = pointTwo[1] - pointOne[1];
        
        for(int i = 1; i < coordinates.size(); i++) {
            auto point = coordinates[i];
            
            if(dy * (pointOne[0] - point[0]) != dx * (pointOne[1] - point[1])) {
                return false;
            }
        }
        
        return true;
    }
};

// Time Complexity - O(n)
// Spcae Complexity - O(1)