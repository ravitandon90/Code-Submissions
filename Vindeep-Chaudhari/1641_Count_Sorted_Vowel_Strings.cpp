/**
 * Problem Link - https://leetcode.com/problems/count-sorted-vowel-strings/
 */

class Solution {
public:
    int countVowelStrings(int n) {
        
        if(n == 1) {
            return 5;
        }
        
        vector<int> dp (5, 1);
        int count = 0;
        
        while(n > 1) {
            for(int i = 3; i >= 0; i--) {
                dp[i] += dp[i+1];
            }
            n--;
        }
        
        for(int i: dp) {
            count += i;
        }
        
        return count;   
    }
};
