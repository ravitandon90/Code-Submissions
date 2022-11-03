class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        int ans = 0;
        for(auto word: words) {
            string rev = word;
            swap(rev[0], rev[1]);
            if(mp.find(rev) != mp.end()) {
                if(--mp[rev] == 0) {
                    mp.erase(rev);
                }
                ans += 4;
            } else {
                mp[word]++;
            }
        }
        for(auto i: mp) {
            if(i.first[0] == i.first[1]) {
                return ans + 2;
            }
        }
        return ans;
    }
};