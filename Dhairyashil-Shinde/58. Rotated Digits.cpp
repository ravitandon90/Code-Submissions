class Solution {
public:
    
    bool isRotationValid(int n) {
        
        bool ans = false;
        while(n) {
            
            // will get the last digit of the whole number bu %
            int digit = n % 10; 
            
            if (digit == 3 || digit == 4 || digit == 7)
                return false;
            else if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                ans = true;
            
            // We are removing the digit which we just considered from the number by '/'
            n /= 10;
        }
        return ans;
    }
    
    int rotatedDigits(int N) {
        
        int goodCnt = 0;
        
        for (int i = 1; i <= N; i++) {
            
            if (isRotationValid(i))
                goodCnt++;
        }
        return goodCnt;
    }
};
