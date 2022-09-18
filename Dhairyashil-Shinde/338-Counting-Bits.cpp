class Solution {
public:
    
    
// example:
// 0  = 0              = 0 = 0000
// 1  = 2^0            = 1 = 0001
// 2  = 2^1            = 1 = 0010
// 3  = 2^1 + 1        = 2 = 0011
// 4  = 2^2            = 1 = 0100
// 5  = 2^2 + 1        = 2 = 0101
// 6  = 2^2 + 2        = 2 = 0110
// 7  = 2^2 + 3        = 3 = 0111
// 8  = 2^3            = 1 = 1000
// 9  = 2^3 + 1        = 2 = 1001
// 10 = 2^3 + 2        = 2 = 1010
// 11 = 2^3 + 3        = 3 = 1011
// 12 = 2^3 + 2^2      = 2 = 1100
// 13 = 2^3 + 2^2 + 1  = 3 = 1101
// 14 = 2^3 + 2^2 + 2  = 3 = 1110
// 15 = 2^3 + 2^2 + 3  = 4 = 1111
    
    vector<int> countBits(int n) {        
        if (n == 0)
            return {0};
        
        vector<int> ans{0, 1};
        int twos = 1;
        
        for (int i = 2; i <= n; i++) {
            
            int diff = 1;
            
            if (twos * 2 == i)
                twos *= 2;
            else if (twos * 2 < i) {
                diff = ans[(i - (twos * 2))] + 1;
            }
            else {
                diff = ans[(i - twos)] + 1;
            }
            
            ans.push_back(diff);
        }
        return ans;
    }
};
