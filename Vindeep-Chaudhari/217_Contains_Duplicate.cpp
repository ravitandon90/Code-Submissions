/**
 * Problem Link - https://leetcode.com/problems/contains-duplicate/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto n: nums) {
            if(mp[n]) {
                return true;
            }
            mp[n]++;
        }

        return false;
    }
};
