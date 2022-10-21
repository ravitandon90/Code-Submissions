class Solution {
public:
    int rev(int n) {
        int x = 0;
        while(n) {
            x = x * 10 + n % 10;
            n /= 10;
        }
        return x;
    }
    bool sumOfNumberAndReverse(int num) {
        vector<int> nums(1e5 + 1);
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = rev(i);
            if(i + nums[i] == num) {
                return true;
            }
        }
        return false;
    }
};