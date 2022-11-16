class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int k = n/2;
        sort(nums.begin(), nums.end());
        int cnt = 1; // Every element appears at least one time
        
        for(int i=1; i<n; i++) {
            
            if(nums[i-1] == nums[i]) 
                cnt++;
            else if(nums[i-1] != nums[i]) 
                cnt = 1;

            if(cnt > k) 
                return nums[i];
        }
        return -1;
    }
};
