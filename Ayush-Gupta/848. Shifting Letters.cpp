class Solution {
public:
    string shiftingLetters(string s, vector<int>& A) {
        int i,n=A.size(); 
        for(i=n-2;i>=0;i--) A[i] = (A[i] + A[i+1]) % 26;
        for(i=0;i<n;i++) s[i] = (s[i] - 'a' + A[i]) % 26 + 'a';
        return s;
    }
};