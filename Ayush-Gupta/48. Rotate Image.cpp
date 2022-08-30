class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, n = matrix.size();
        for(i=0; i<n; i++) {
            for(j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(i=0; i<n; i++) reverse(matrix[i].begin(), matrix[i].end());
    }
};