class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1);
        
        for(auto citation: citations) {
            ++count[min(citation, n)];
        }
        
        int acc = 0, ans = 0;
        for(int i = n; i >= 0; i--) {
            acc += count[i];
            if(acc >= i) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};