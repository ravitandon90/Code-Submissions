class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, prev = 0;
        for(int i = 1; i < colors.size(); i++) {
            if(colors[i] == colors[prev]) {
                if(neededTime[i] > neededTime[prev]) {
                    swap(neededTime[i], neededTime[prev]);
                }
                ans += neededTime[i];
            } else {
                prev = i;
            }
        }
        return ans;
    }
};