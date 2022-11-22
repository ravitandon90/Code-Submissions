class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0, ans = 0;
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            if(prefix == k) {
                ans++;
            }
            int target = prefix - k;
            if(mp.find(target) != mp.end()) {
                ans += mp[target];
            }
            mp[prefix]++;
        }
        return ans;
    }
};