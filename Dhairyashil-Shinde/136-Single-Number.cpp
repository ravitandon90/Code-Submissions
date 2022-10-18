class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        int ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<n; i++) {
            
            if(nums[i] == nums[i-1]) {
                i++;
            }
            else if(nums[i] != nums[i-1]) {
                ans = nums[i-1];
                return ans;
            }
        }
        return nums[n-1];
    }
};
