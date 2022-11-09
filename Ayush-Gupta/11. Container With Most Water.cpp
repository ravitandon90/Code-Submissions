class Solution {
public:
    int maxArea(vector<int>& a) {
        int lo = 0, hi = a.size() - 1, ans = 0;
        while(lo < hi) {
            ans = max(ans, min(a[lo], a[hi]) *(hi - lo));
            if(a[lo] < a[hi]) lo++;
            else hi--;
        }
        return ans;
    }
};