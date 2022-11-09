class Solution {
public:
    int maximumScore(int a, int b, int c) {
        a = min(a, b + c);
        b = min(b, a + c);
        c = min(c, a + b);
        return (a + b + c) >> 1;
    }
};
