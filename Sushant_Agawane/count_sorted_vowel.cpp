class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> ans(5,1);
        int sum = 0;
        for(int i = 2; i <= n; i++) {
            for(int i = 3; i >= 0; i--) {
                ans[i] += ans[i+1];
            }
        }
        //now return the summation as we have stored the count of pairs in it.
        for(auto i:ans) {
            sum = sum + i;
        }
        return sum;
    }
};