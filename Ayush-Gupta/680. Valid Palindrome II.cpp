class Solution {
public:
    bool f(string s,int l,int h)
    {
        while(l<=h)
        {
            if(s[l++]!=s[h--]) return 0;
        }
        return 1;
    }
    bool validPalindrome(string s) 
    {
        int i,j;
        i=0; j=s.size()-1;
        if(f(s,i,j)) return 1;
        while(s[i]==s[j])
        {
            i++; j--;
        }
        if(f(s,i+1,j)||f(s,i,j-1)) return 1;
        return 0;
    }
};