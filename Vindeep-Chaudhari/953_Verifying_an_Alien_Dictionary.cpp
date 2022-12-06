/**
 * Problem Link - https://leetcode.com/problems/verifying-an-alien-dictionary/
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() == 1) return true;

        unordered_map<char, int> dict;
        for(int i = 0; i < order.length(); i++) {
            dict[order[i]] = i;
        }

        for(int i = 0; i < words.size()-1; i++) {
            string first = words[i];
            string second = words[i+1];

            int fI = 0;
            int sI = 0;
            while(fI < first.length() && sI < second.length()) {
                if(dict[first[fI]] > dict[second[sI]]) return false;
                else if(dict[first[fI]] < dict[second[sI]]) break;
                else {
                    fI++;
                    sI++;

                    if(sI >= second.size() && fI < first.length()) return false;
                }    
            }
        }

        return true;
    }
};