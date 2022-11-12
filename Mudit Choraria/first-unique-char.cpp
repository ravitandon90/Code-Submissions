class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(128);
        for(auto c: s) {
            count[c]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(count[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
