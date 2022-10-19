class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        map<int, int> nmp;
        for(auto num: nums) {
            if(num < 0) {
                nmp[num]++;
            }
        }
        for(auto num: nums) {
            if(nmp.find(-num) != nmp.end()) {
                ans = max(num, ans);
            }
        }
        return ans;
    }
};