/**
 * Problem Link - https://leetcode.com/problems/merge-intervals/
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if (intervals.size() == 1) return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < intervals.size(); i++) {
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back({intervals[i][0], intervals[i][1]});
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        
        return ans;
        
    }
};