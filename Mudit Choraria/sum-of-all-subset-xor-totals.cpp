class Solution {
public:
    int ans = 0;
    void res(int curr, int id, vector<int>& nums) {
        if(id == nums.size()) {
            ans += curr;
            return;
        }
        res(curr ^ nums[id], id + 1, nums);
        res(curr, id + 1, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        // res(0, 0, nums);
        // return ans;
        return accumulate(begin(nums), end(nums), 0, bit_or<>()) << nums.size() - 1;
    }
};