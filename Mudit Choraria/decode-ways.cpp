class Solution {
public:
    int numDecodings(string s) {        
        int n = s.size();
        if(n == 0 || s[0] == '0') {
            return 0;
        }
        int ans = 1;
        int lastCharScore = 1;
        int lastSecondCharScore = 1;
        
        for(int i = 1; i < n; i++){
            ans = getScore(s[i]) * lastCharScore + getScore(s[i], s[i - 1]) * lastSecondCharScore;
            lastSecondCharScore = lastCharScore;
            lastCharScore = ans;   
        }
        return ans;
    }
    
private:
    int getScore(char prev) {
        return prev > '0' && prev <= '9';
    }
    int getScore(char lastChar, char lastSecondChar) {
        return lastSecondChar == '1' || (lastSecondChar == '2' && lastChar <= '6');
    }
};