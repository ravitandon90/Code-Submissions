/**
 * Problem Link - https://leetcode.com/problems/decompress-run-length-encoded-list/
 */

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        
        vector<int> ans;
        for(int i = 0; i < nums.size()-1; i+=2) {
            int freq = nums[i];
            int val = nums[i+1];
            
            while(freq > 0) {
                ans.push_back(val);
                freq--;
            }
        }
        
        return ans;
    }
};