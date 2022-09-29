class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number=0;
        for(auto x: nums){
            number=number^x;
        }
        return number;
    }
};