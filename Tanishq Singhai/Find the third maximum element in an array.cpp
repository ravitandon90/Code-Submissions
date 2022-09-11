class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // TC - O(N)
        // SC - O(1)
        long n = nums.size(), first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] == first || nums[i] == second || nums[i] == third)
                continue;
            if (nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            } else if (nums[i] > second) {
                third = second;
                second = nums[i];
            } else if (nums[i] > third) {
                third = nums[i];
            }
        }
        return third == LONG_MIN ? first : third;
    }
};
