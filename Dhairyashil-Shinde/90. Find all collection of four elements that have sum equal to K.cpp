class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int T) {
        unordered_set<int> seen;
        set<multiset<int>> ans_set;
        int n = size(nums);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    int need = T - (nums[i] + nums[j] + nums[k]);
                    if(seen.count(need)) 
                        ans_set.emplace(multiset<int>{nums[i], nums[j], nums[k], need});
                }                
            }
            seen.insert(nums[i]);
        }
        vector<vector<int>>ans(size(ans_set));
        for_each(begin(ans_set), end(ans_set), [&, i(0)](auto& el) mutable { ans[i++] = vector<int>(begin(el), end(el)); });
        return ans;
    }
};
