class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool ans[3] = {false, false, false};
        for(int i = 0; i < triplets.size(); i++) {
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                if(target[0] == triplets[i][0]) {
                    ans[0] = true;
                }
                if(target[1] == triplets[i][1]) {
                    ans[1] = true;
                }
                if(target[2] == triplets[i][2]) {
                    ans[2] = true;
                }
            }
        }
        return ans[0] && ans[1] && ans[2];
    }
};
