/**
 * Problem Link -https://leetcode.com/problems/target-sum/
 */

class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, int target, int sum, vector<int> v, int index) {
        if(index == candidates.size()) return;
        
        if(sum == target) {
            ans.push_back(v);
            return;
        } else if(sum > target) {
            return;
        }
        
        for(int i = index; i < candidates.size(); i++) {
            v.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, sum, v, i);
            v.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0, {}, 0);
        return ans;
    }
};
