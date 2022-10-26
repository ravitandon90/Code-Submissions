class Solution {
public:
    int findJudge(int n, vector<vector<int>>& a) {
        unordered_map<int, int> mp, mpp;
        for(auto x: a) mp[x[0]]++, mpp[x[1]]++;
        for(int i=1;i<=n;i++) {
            if(mp[i]==0 && mpp[i]==n-1) return i;
        }
        return -1;
    }
};