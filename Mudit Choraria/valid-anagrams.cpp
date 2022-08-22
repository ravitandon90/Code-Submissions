class Solution {
public:
    bool isAnagram(string s, string t) {
        // this is a frequency map of alphabets
        vector<int> mp(26, 0);
        // increasing counter for the first word
        for(auto i: s) {
            mp[i - 'a']++;
        }
        // decreasing counter for the first word
        for(auto i: t) {
            mp[i - 'a']--;
        }
        // if the value for any letter is non-zero, it means there is some mismatch
        for(auto i: mp) {
            if(i) return false;
        }
        return true;
    }
};

// Space Complexity: O(1)
// Time Complexity: O(1) (we are using vector for frequency map)