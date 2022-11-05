class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> one1, one2;
        map<pair<int, int>, int> mp;
        int n = img1.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1) {
                    one1.push_back({i, j});
                }
                if(img2[i][j] == 1) {
                    one2.push_back({i, j});
                }
            }
        }
        for(auto i: one1) {
            for(auto j: one2) {
                mp[{j.first - i.first, j.second - i.second}]++;
            }
        }
        int ans = 0;
        for(auto i: mp) {
            ans = max(ans, i.second);
        }
        return ans;
    }
    // int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    //     vector<int> LA, LB;
    //     int N = A.size();
    //     unordered_map<int, int> count;
    //     for (int i = 0; i < N * N; ++i)
    //         if (A[i / N][i % N] == 1)
    //             LA.push_back(i / N * 100 + i % N);
    //     for (int i = 0; i < N * N; ++i)
    //         if (B[i / N][i % N] == 1)
    //             LB.push_back(i / N * 100 + i % N);
    //     for (int i : LA) for (int j : LB) count[i - j]++;
    //     int res = 0;
    //     for (auto it : count) res = max(res, it.second);
    //     return res;
    // }
};