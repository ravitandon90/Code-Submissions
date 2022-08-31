class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int count;  
        for(int i = 0; i < nums.size()-1; i+=2) {
            int val = nums[i+1];
            int size = nums[i];
            count = 0;
            ans.insert(ans.begin()+count, size, val);
            count = count + nums[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};