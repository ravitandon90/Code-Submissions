class Solution {
public:
    int hIndex(vector<int>& citations) {
        reverse(citations.begin(), citations.end());
        int l = 0, r = citations.size() - 1, ans = 0;
        while(l <= r) {
            const int h =  l + (r - l) / 2;
            if(citations[h] >= h + 1) {
                ans = h + 1;
                l = h + 1;
            } else {
                r = h - 1;
            }
        }
        return ans;
    }
};