class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i=0, j=0;i<nums.size();i++) {
            if(nums[i]%2==0) {
                swap(nums[i], nums[j++]);
            }
        }
        return nums;
    }
};