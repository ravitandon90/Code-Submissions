class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] + k;
            k = nums[i] / 10;
            nums[i] = nums[i] % 10;
        }
        //so this will handle carry and everything till array length
        //now if K digits are still remaining
        while(k) {
            nums.push_back(k%10);
            k = k / 10;
        }
        
        reverse(nums.begin(), nums.end());
        return nums;
    }
};