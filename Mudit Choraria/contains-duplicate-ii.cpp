class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > k) {
                mp.erase(nums[i - k - 1]);
            }
            if(mp.find(nums[i]) != mp.end()) {
                return true;
            } 
            mp[nums[i]]++;
        }
        return false;
    }
};