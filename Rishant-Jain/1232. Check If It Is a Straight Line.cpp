class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& A) {
        int n = A.size();
        if (n <=2 ) return 1;
        
        for (int i = 0 ; i < n - 2 ; i++) {
            int x1 = A[i][0], y1 = A[i][1];
            int x2 = A[i+1][0], y2 = A[i+1][1];
            int x3 = A[i+2][0], y3 = A[i+2][1];
            
            if ((y2 - y1)*(x3 - x2) != (y3 - y2)*(x2 - x1)) return 0;
        }
        return 1;
    }
};