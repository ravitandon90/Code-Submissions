class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int cnt = 1; 
        // Cnt = 1 bcoz any element is present in array already at least 1 time
        
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] == nums[i]) 
                cnt++;
            if(cnt >= 2) 
                return true;
        }
        return false;
    }
};
