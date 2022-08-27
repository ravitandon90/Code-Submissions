// Time complexity - O(n), linear traversal
// Space Complexity - O(1), constant

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[n-1][0], y2 = coordinates[n-1][1];
        int dx = x2-x1;
        int dy = y2-y1;
        for (int i = 0; i < n ; i++)
        {
            int slopeX = coordinates[i][0] - coordinates[0][0];
            int slopeY = coordinates[i][1] - coordinates[0][1];
                        
            // slope for any 2 points on a straight line must remain same
            // dy/dx = slopeY/slopeX
            // dy * slopeX == slopeY * dx            
            if( slopeX * dy != slopeY * dx) 
                return false;
        }
        return true;
    }
};