/**
 * Problem Link - https://leetcode.com/problems/intersection-of-two-arrays/
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     
        unordered_map<int, bool> records, intersection;
        
        for(auto n: nums2) {
            records[n] = true;
        }
        
        for(auto n: nums1) {
            if(records.find(n) != records.end()) {
                intersection[n] = true;
            }
        }
        
        vector<int> ans;
        for(auto ele : intersection) {
            ans.push_back(ele.first);
        }
        
        return ans;
    }
};