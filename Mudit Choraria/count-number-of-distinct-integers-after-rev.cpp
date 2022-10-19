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
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        for(auto num: s) {
            s.insert(rev(num));
        }
        return s.size();
    }
};