class Solution {
public:

    /*
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        int n = nums.size();
        int i = 0;
        int j = i+1;
        
        while(i<=j) {
            
            if( nums[i]+nums[j] == target ) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if ( nums[i]+nums[j] != target && j!=n-1 ) {
                j++;
            }
            else if ( nums[i]+nums[j] != target && j==n-1 ) {
                i++;
                j = i+1;
            }
            
        }
        
        return ans;
    }
    */

    vector<int> twoSum(vector<int>& nums, int target) {
        
        for (int i = 0; i < nums.size(); i++) 
            for (int j = i + 1; j < nums.size(); j++) 
                if (nums[j] == target - nums[i]) 
                    return {i,j};
        
        return {}; // Return Empty Vector
    }
};
