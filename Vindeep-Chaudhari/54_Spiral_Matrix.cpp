/**
 * Problem Link - https://leetcode.com/problems/spiral-matrix/
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int i = 0, j = 0;
        
        vector <int> spiral;
        
         int m = matrix.size(),
            n = matrix[0].size();
        
        vector< vector<int>> visited (m, vector<int> (n, 0));
        
       
        
        int count = 0;
        
        string movingDirection = "R";
        
        while ( i < m && j < n ) {
            
            // cout<<"i - "<<i<<" j - "<<j<<endl;
            
            // if(i >= m || j >= n) break;
            
            count++;
            visited[i][j] = 1;
            spiral.push_back(matrix[i][j]);
            
            if(visited[i][j]) break;
            
            if(movingDirection == "R") {
                if(j+1 < n && !visited[i][j+1]) j++;
                else {
                    movingDirection = getNextMovingDirection(movingDirection, i, j);
                }
            } else if(movingDirection == "D") {
                if(i+1 < m && !visited[i+1][j]) i++;
                else {
                    movingDirection = getNextMovingDirection(movingDirection, i, j);
                }
            } else if(movingDirection == "L") {
                if(j-1 >= 0 && !visited[i][j-1]) j--;
                else {
                    movingDirection = getNextMovingDirection(movingDirection, i, j);
                }
            } else if(movingDirection == "U") {
                if(i-1 >= 0 && !visited[i-1][j]) i--;
                else{
                    movingDirection = getNextMovingDirection(movingDirection, i, j);   
                }
            }
            
        }
        
        return spiral;
        
    }
    
    string getNextMovingDirection(string direction, int &i, int &j) {
        
        if(direction == "R") {
            i++;
            return "D";
        } else if (direction == "D") {
            j--;
            return "L";
        } else if (direction == "L") {
            i--;
            return "U";
        } else {
            j++;
            return "R";
        }
        
    }
};