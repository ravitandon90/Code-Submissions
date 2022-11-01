class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        if(i < 0 || j < 0 || i >= m || j >= n) {
            return false;
        }
        return true;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if(i == m) {
            return j;
        }
        if(isValid(i, j, m, n)) {
            if(grid[i][j] == 1) {
                // fall right
                if(isValid(i, j + 1, m, n) && grid[i][j + 1] == 1) {
                    return dfs(grid, i + 1, j + 1);
                }
            } else {
                // fall left
                if(isValid(i, j - 1, m, n) && grid[i][j - 1] == -1) {
                    return dfs(grid, i + 1, j - 1);
                }
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        for(int i = 0; i < grid[0].size(); i++) {
            res.push_back(dfs(grid, 0, i));
        }
        return res;
    }
};