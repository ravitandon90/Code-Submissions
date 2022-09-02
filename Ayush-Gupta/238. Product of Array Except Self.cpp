class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int i, n = a.size();
        vector<int> left(n), right(n);
        left[0] = 1; right[0] = 1;
        for(i=1; i<n; i++) left[i] = left[i-1] * a[i-1];
        reverse(a.begin(), a.end());
        for(i=1; i<n; i++) right[i] = right[i-1] * a[i-1];
        reverse(right.begin(), right.end());
        for(i=0; i<n; i++) left[i] = (left[i] * right[i]);
        return left;
    }
};