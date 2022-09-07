class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = LONG_MIN;  // the maximum
        long max2 = LONG_MIN;  // 2nd maximum
        long max3 = LONG_MIN;  // 3rd maximum

        for(auto i: nums) {
            if(i > max1) {
                max3 = max2;
                max2 = max1;
                max1 = i;
            } else if(i > max2 && max1 > i) {
                max3 = max2; 
                max2 = i;
            } else if(i > max3 && max2 > i) {
                max3 = i;
            }
        }
        
        return max3 == LONG_MIN ? max1 : max3;
    }
};