class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) {
            return false;
        }
        int c1 = INT_MAX, c2 = INT_MAX;
        for(int i: nums) {
            if(i <= c1) {
                c1 = i;
            }
            else if(i <= c2) {
                c2 = i;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
