class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long mx1=LONG_MIN, mx2=LONG_MIN, mx3=LONG_MIN, n=nums.size();
        // Finding 1st maximum
        for(int i=0;i<n;i++){
            mx1=max(mx1, (long)nums[i]);
        }
        // Finding 2nd maximum
        for(int i=0;i<n;i++){
            if(mx1!=nums[i] && mx2<nums[i]){
                mx2=nums[i];
            }
        }
        // Finding 3rd maximum
        for(int i=0;i<n;i++){
            if(mx2!=nums[i] && mx1!=nums[i] && mx3<nums[i]){
                mx3=nums[i];
            }
        }
        return (mx3 == LONG_MIN) ? mx1 : mx3;
    }
};