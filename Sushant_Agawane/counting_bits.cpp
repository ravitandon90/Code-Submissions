class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int sum, temp;
        for(int i = 0; i <= n; i++) {
            sum = 0;
            temp = i;
            while(temp != 0) {
                sum = sum + (temp%2);
                temp = temp / 2;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};