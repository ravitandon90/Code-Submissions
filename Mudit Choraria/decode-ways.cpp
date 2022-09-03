class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0') {
            return 0;
        }
        int ans = 1;
        int dec1 = 1;
        int dec2 = 1;
        
        for(int i = 1; i < n; i++){
            ans = 0;
            if(s[i] > '0' && s[i] <= '9') {
                ans += dec1;
            }
            if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7') {
                ans += dec2;
            }

            dec2 = dec1;
            dec1 = ans;   
        }
        return ans;
    }
};