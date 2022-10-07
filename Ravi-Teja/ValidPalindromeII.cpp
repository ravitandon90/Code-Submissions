class Solution {
public:
    pair<int,int> isPalindrome(string &s, int i, int n){
        int l=i, r=n;
        while(l<r){
            if(s[l]!=s[r]){
                return {l,r};
            }
            l++;
            r--;
        }
        return {l,r};
    }
    bool validPalindrome(string s) {
        pair<int,int> result=isPalindrome(s, 0, s.length()-1);
        if(result.first>=result.second){
            return true;
        }
        pair<int,int> result2=isPalindrome(s, result.first+1, result.second);
        if(result2.first>=result2.second){
            return true;
        }
        result2=isPalindrome(s, result.first, result.second-1);
        return result2.first>=result2.second;
    }
};
