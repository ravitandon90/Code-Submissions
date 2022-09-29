class Solution {
public:
    int countVowelStrings(int n) {
        int cnt=1, ans=5, res=1;
        for(int i=1;i<=n;i++){
            res=res*ans;
            res=res/cnt;
            ans++;
            cnt++;
        }
        return res;
    }
};