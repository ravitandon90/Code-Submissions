class Solution {
public:
    void dfs(int n, string &s, vector<string> &result){
        if(n<0){
            result.push_back(s);
            return;
        }
        dfs(n-1, s, result);
        if(s[n]>='a' && s[n]<='z'){
            s[n]=(s[n]-'a')+'A';
        }
        else if(s[n]>='A' && s[n]<='Z'){
            s[n]=(s[n]-'A')+'a';
        }
        else{
            return;
        }
        dfs(n-1, s, result);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        dfs(s.length()-1, s, result);
        return result;
    }
};