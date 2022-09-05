class Solution {
public:
    int numDecodings(string s) {
        long K = 1e9 + 7;     
        int n = s.size();
        if(n == 0 || s[0] == '0') {
            return 0;
        }
        long lastCharScore = getScore(s[0]);
        long lastSecondCharScore = 1;
        
        for(int i = 1; i < n; i++){
            long ans = (getScore(s[i]) * lastCharScore) % K + (getScore(s[i], s[i - 1]) * lastSecondCharScore) % K;
            ans %= K;
            lastSecondCharScore = lastCharScore;
            lastCharScore = ans;   
        }
        return lastCharScore;
    }
    
private:
    int getScore(char lastChar) {
        return lastChar == '*' ? 9 : lastChar != '0';
    }
    int getScore(char lastChar, char lastSecondChar) {
        if(lastChar == '*' && lastSecondChar == '*') {
            return 15;
        }
        if(lastSecondChar == '*') {
            if(lastChar >= '0' && lastChar <= '6') {
                return 2;
            } else {
                return 1;
            }
        }
        if(lastChar == '*') {
            if(lastSecondChar == '1') {
                return 9;
            } else if(lastSecondChar == '2') {
                return 6;
            } else {
                return 0;
            }
        }
        return lastSecondChar == '1' || (lastSecondChar == '2' && lastChar <= '6');
    }
};