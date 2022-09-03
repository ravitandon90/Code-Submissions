class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, n = digits.size();
        for(i=n-1; i>=0; i--) {
            if(digits[i] == 9) digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};