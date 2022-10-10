class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int ans = 0;
        for(int i = 0; i + 2 < nums.size(); i++) {
            if(i && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int checkSum = nums[i] + nums[l] + nums[r];
                if(abs(checkSum - target) < diff) {
                    diff = abs(checkSum - target);
                    ans = checkSum;
                }
                if(checkSum == target) {
                    return target;
                } else if(checkSum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }   
        return ans;
    }
};