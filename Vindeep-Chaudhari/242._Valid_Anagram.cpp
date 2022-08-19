/**
 * Problem Link - https://leetcode.com/problems/valid-anagram/
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> tFreq;
        for(int i = 0; i < t.length(); i++) {
            tFreq[t[i]]++;
        }
        
        int totalLength = s.length();
        for(int i = 0; i < s.length(); i++) {
            if(!tFreq[s[i]] || tFreq[s[i]] <= 0) {
                return false;
            }
            
            tFreq[s[i]]--;
            totalLength--;
        }
        
        if(totalLength == 0) return true;
        
        return false;
    }
};