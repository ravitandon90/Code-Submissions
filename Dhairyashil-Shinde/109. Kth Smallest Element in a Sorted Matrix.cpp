class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int row = matrix.size(), col = matrix[0].size();
        
        vector<int> v;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                v.push_back(matrix[i][j]);
            }
        }

        sort(v.begin(), v.end());
        return v[k-1];
    }
};
