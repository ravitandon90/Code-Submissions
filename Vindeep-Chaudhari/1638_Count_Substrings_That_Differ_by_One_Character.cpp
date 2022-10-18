/**
 * Problem Link - https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
 */

class Solution {
public:
    int countSubstrings(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        vector<vector<int>> sameStr (sLen+1, vector<int>(tLen+1, 0));
        
        for(int i = 1; i <= sLen; i++){
            for(int j = 1; j <= tLen; j++){
                if(s[i-1] == t[j-1]){
                    sameStr[i][j] = 1 + sameStr[i-1][j-1];
                }
            }
        }
        
        vector<vector<int>>diffStr (sLen+1, vector<int>(tLen+1,0));
        int count = 0;
        
        for(int i = 1; i <= sLen; i++){
            for(int j = 1; j <= tLen; j++){
                if(s[i-1] != t[j-1]){
                    diffStr[i][j] = 1 + sameStr[i-1][j-1]; 
                } else {
                    diffStr[i][j] = diffStr[i-1][j-1];
                }
                count += diffStr[i][j];
            }
        }
        
        return count;
    }
};

