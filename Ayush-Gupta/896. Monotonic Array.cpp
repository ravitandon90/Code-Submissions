class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        int up = 0, down = 0, i, n = a.size();
        for(i=1; i<n; i++) {
            if(a[i-1] < a[i]) up = 1;
            else if(a[i-1] > a[i]) down = 1;
        }
        return (up > 0 && down > 0) ? (0)  : (1);
    }
};