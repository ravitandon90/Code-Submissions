class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = size(nums);
        int l = 0, r = n - 1;
        while(l < r) {
            if(nums[l] % 2 && nums[r] % 2 == 0) {
                swap(nums[l], nums[r]);
            }
            if(nums[l] % 2 == 0) {
                l++;
            }
            if(nums[r] % 2) {
                r--;
            }
        }
        return nums;
    }
};