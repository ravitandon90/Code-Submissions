class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> A(250, -1);
        int ans = 0;
        A[0] = 0;
        A[1] = 1;
        for(int i = 0; i <= n; i++) {
            A[2*i] = A[i];
            A[2*i + 1] = A[i] + A[i + 1]; 
            ans = max(ans, A[i]);
        }
        return ans;
    }
};