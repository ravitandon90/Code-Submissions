class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> v(n+2);
        v[0]=0; v[1]=1;
        for(int i=1;i<=(n/2);i++) {
            v[2*i]=v[i];
            v[2*i+1]=v[i]+v[i+1];
        }
        return *max_element(v.begin(), v.end()-1);
    }
};