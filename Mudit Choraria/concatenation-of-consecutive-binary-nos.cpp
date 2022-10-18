class Solution {
public:
    int getBinaryLength(int n)
    {
        int length = 0;
        while (n > 0) {
            length += 1;
            n /= 2;
        }
    return length;
    }
    long long MOD = 1e9 + 7;
    int concatenatedBinary(int n) {
        long long prev = 1;
        for(int i = 2; i <= n; i++) {
            int x = getBinaryLength(i);
            prev = ((prev << x) % MOD + i % MOD) % MOD;
        }
        return (int) prev;
    }
};