class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        
        int n = arr.size();
        int bits = 0;
        int ans;
        
        for (int i=0; i < n; ++i) {
            bits |= arr[i];
        }
            
        ans = bits * pow(2, n-1);
        
        return ans;
    }
};
