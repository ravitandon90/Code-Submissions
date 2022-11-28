/**
 * Problem Link - https://leetcode.com/problems/find-a-peak-element-ii/
 */

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        long startCol = 0, endCol = mat[0].size()-1;
        while(startCol <= endCol) {
            int midCol = startCol + (endCol - startCol)/2;
            
            // cout<<"start -- "<<startCol<<" mid -- "<<midCol<<" endCol -- "<<endCol<<endl;
            
            int maxRow = 0;
            for(int i = 0; i < mat.size(); i++) {
                maxRow = mat[i][midCol] >= mat[maxRow][midCol] ? i : maxRow;
            }
            
            int currentElement = mat[maxRow][midCol];
            int leftElement = midCol-1 >= 0 ? mat[maxRow][midCol-1] : -1;
            int rightElement = midCol+1 <= mat[0].size()-1 ? mat[maxRow][midCol+1] : -1;

            
            if(currentElement > leftElement && currentElement > rightElement) {
                return {maxRow, midCol};
            } else if(currentElement > leftElement) {
                startCol = midCol + 1;
            } else {
                endCol = midCol - 1;
            }
        }
        return {0,0};
        
    }  
};