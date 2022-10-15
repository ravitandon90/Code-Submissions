class Solution {
public:
    int f(int n) {
        int rem, flag=0;
        while(n) {
            rem=n%10;
            if(rem==3 || rem==4 || rem==7) return 0;
            if(rem==2 || rem==5 || rem==6 || rem==9) flag=1;
            n /= 10;
        }
        return flag;
    }
    int rotatedDigits(int n) {
        int i, ans=0;
        for(i=1;i<=n;i++) if(f(i)) ans++;
        return ans;
    }
};