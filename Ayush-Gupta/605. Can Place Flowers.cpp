class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int k) {
        a.insert(a.begin(), 0);
        a.push_back(0);
        int i, n=a.size();
        for(i=1;i<n-1;i++) {
            if(a[i-1]==0 && a[i]==0 && a[i+1]==0) {
                k--;
                i++;
            }
        }
        return k<=0;
    }
};