class Solution {
public:
    int firstUniqChar(string s) {
        int i, n=s.size(), A[26]={0};
        for(i=0;i<n;i++) {
            A[s[i]-'a']++;
        }
        for(i=0;i<n;i++) {
            if(A[s[i]-'a']==1) return i;
        }
        return -1;
    }
};