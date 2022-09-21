class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size(), cnt=(1<<n), add=0, res=0;
        for(int i=0;i<cnt;i++){
            add=0;
            for(int j=0;j<n;j++){
                if((i&(1<<j))>0){
                    add=add^(nums[j]);
                }
            }
            res+=add;
        }
        return res;
    }
};