class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &x){
        int l=0, r=x.length()-1;
        while(l<r){
            if(x[l]!=x[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void helper(int i, int n, string &s, vector<string> &temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        string res="";
        for(int j=i;j<n;j++){
            res.push_back(s[j]);
            if(isPalindrome(res)){
                temp.push_back(res);
                helper(j+1, n, s, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ans.clear();
        vector<string> temp;
        helper(0, s.length(), s, temp);
        return ans;
    }
};