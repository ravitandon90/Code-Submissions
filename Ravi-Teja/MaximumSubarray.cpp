class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=INT_MIN, sum=0;
        for(auto x: nums){
            sum+=x;
            if(x > sum){
                sum=x;
            }
            mx=max(sum, mx);
        }
        return mx;
    }
};
