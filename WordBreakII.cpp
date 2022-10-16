class Solution {
public:
    void helper(int i, int n, unordered_set<string> &seen, string &s, vector<string> &result, string &word){
        if(i>=n){
            word.pop_back();
            result.push_back(word);
            return;
        }
        string newword="", temp="";
        for(int j=i;j<n;j++){
            temp.push_back(s[j]);
            if(seen.count(temp)){
                newword=word+temp;
                newword.push_back(' ');
                helper(j+1, n, seen, s, result, newword);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> seen;
        for(auto x: wordDict){
            seen.insert(x);
        }
        vector<string> result;
        string word="";
        helper(0, s.length(), seen, s, result, word);
        return result;
    }
};
