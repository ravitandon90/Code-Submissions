/**
 * Problem Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        

        unordered_map <char, int> mp;
        int maxLen = 0;
        int start = 0;
        for(int i = 0; i < s.length(); i++) {
            if(mp[s[i]] && mp[s[i]] > start) {
                start = mp[s[i]];
            }
            mp[s[i]] = i+1;
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};