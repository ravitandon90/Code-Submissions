/**
 * Problem Link - https://leetcode.com/problems/pascals-triangle/
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> triangle;
        for(int index = 1; index <= numRows; index++) {
            if(index == 1) {
                triangle.push_back({1});
            } else if (index == 2) {
                triangle.push_back({1,1});
            } else {                
                vector <int> row;
                row.push_back(1);
                for(int i = 0, j = i+1; i < triangle[index-2].size()-1; i++,j++) {
                    row.push_back(triangle[index-2][i]+triangle[index-2][j]);
                }
                row.push_back(1);
                
                triangle.push_back(row);
            }
        }
        
        return triangle;
        
    }
};

