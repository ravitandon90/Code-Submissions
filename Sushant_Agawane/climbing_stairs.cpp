class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int next = 2, prev = 1, ans;
        for (int i = 3; i <= n; i++) {
            ans = prev + next;
            prev = next;
            next = ans;
        }
        return ans;
    }
};