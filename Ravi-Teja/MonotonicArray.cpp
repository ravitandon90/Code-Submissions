class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increase=true, decrease=true;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                decrease=false;
            }
            else if(nums[i] > nums[i+1]){
                increase=false;
            }
            if(!increase & !decrease){
                return false;
            }
        }
        return increase || decrease;
    }
};