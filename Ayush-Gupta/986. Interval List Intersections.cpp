class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int i = 0, j = 0, n = a.size(), m = b.size(), lo, hi;
        while(i < n && j < m) {
            lo = max(a[i][0], b[j][0]);
            hi = min(a[i][1], b[j][1]);
            if(lo <= hi) ans.push_back({lo, hi});
            if(a[i][1] < b[j][1]) i++;
            else j++;
        }
        return ans;
    }
};