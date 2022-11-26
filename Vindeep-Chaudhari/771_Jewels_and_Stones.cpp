/**
 * Problem Link - https://leetcode.com/problems/jewels-and-stones/
 */

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> jmp;
        for(auto c: jewels) {
            jmp[c]++;
        }

        int cnt = 0;
        for(auto s: stones) {
            if(jmp[s] && jmp[s] > 0) {
                cnt++;
            }
        }

        return cnt;
    }
};
