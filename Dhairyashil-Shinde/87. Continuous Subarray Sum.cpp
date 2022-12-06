class Solution {
public:
    
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        // curr_sum will keep track of sum from start till ith
        int curr_sum = 0;

        // declare a hashmap
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            
            // update curr_sum
            curr_sum += nums[i];

            // if multiple of k found 
            if(curr_sum % k == 0 && i > 0)
                return true;

            if(mp.count(curr_sum % k) && (i - mp[curr_sum % k] >= 2))
                return true;

            // if curr_sum % k is not present in map then insert it into map
            if(mp.count(curr_sum % k) == 0)
                mp[curr_sum % k] = i;
        }

        return false;
    }
};
