class Solution {
public:
    
    vector<int> dp;
    int numDecodings(string s) {
        //Here for finding all possbile scenarios we have to use concept of Recursion and Backtracking.
        // we have to take care of all of the Base Cases.
        dp.resize(s.size());
        dp.assign(s.size(), -1);
        return countWays(0, s);
    }
    
    int countWays(int i, string s) {
        if(i >= s.size()) return 1;
        //this is for if character is 0
        else if(s[i] == '0') return 0;
        // this is for last character
        else if(i == s.size()-1) return 1;
        else if(dp[i] != -1) return dp[i];
        else if(s[i] == '1' || (s[i] == '2') && (s[i+1] >= 48 && s[i+1] <= 54)) {
            return dp[i]= countWays(i+1, s) + countWays(i+2, s);
        }
        return dp[i]=countWays(i+1, s);
    }
    
};