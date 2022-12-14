class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0, curr = 0;
        for(int i = 0; i < nums.size(); i++) {
            int tmp = max(pre + nums[i], curr);
            pre = curr;
            curr = tmp;
        }
        return curr;
    }
};