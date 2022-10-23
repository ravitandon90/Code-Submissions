class Solution {
public:
    int getClosestDiff(map<int, int>& mp, int num) {
        auto it = mp.lower_bound(num);
        if(it == mp.begin()) {
            return abs(it->first - num);
        } else if(it == mp.end()) {
            it = prev(it);
            return abs(it->first - num);
        } else {
            return min(abs(it->first - num), abs(prev(it)->first - num));
        }
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int v) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > k) {
                mp.erase(nums[i - k - 1]);
            }
            if(mp.size() && getClosestDiff(mp, nums[i]) <= v) {
                return true;
            }
            mp[nums[i]]++;
        }
        return false;
    }
};