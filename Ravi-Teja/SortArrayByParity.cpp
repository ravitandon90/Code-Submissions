class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i<j){
            while(i<j && nums[i]%2==0){
                i++;
            }
            while(i<j && nums[j]%2!=0){
                j--;
            }
            if(i<j){
                swap(nums[i], nums[j]);    
                i++;
                j--;
            }
        }
        return nums;
    }
};