class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> indices(plantTime.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(),
             [&](int i, int j) { return growTime[i] > growTime[j]; });
        int result = 0, curPlantTime = 0;
        for (int i : indices) {
            curPlantTime += plantTime[i];
            result = max(result, curPlantTime + growTime[i]);
        }
        return result;
    }
    // static bool cmp(pair<int, int>& a, pair<int, int>& b) {
    //     if(a.second != b.second) {
    //         return a.second > b.second;
    //     }
    //     return a.first > b.first;
    // }
    // int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    //     vector<pair<int, int>> gp;
    //     for(int i = 0; i < plantTime.size(); i++) {
    //         gp.push_back({plantTime[i], growTime[i]});
    //     }
    //     sort(gp.begin(), gp.end(), cmp);
    //     int ans = 0, curr = 0;
    //     for(auto i: gp) {
    //         ans = max(curr + i.first + i.second, ans);
    //         curr += i.first;
    //     }
    //     return ans;
    // }
};