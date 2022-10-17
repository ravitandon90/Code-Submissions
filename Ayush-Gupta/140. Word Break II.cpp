class Solution {
public:
    void fun(string s, unordered_set<string> &st, vector<string> &ans, int ind, string curr){
        if(ind == s.size()){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        string temp = "";
        for(int i=ind; i<s.size();i++){
            temp += s[i];
            if(st.find(temp) != st.end()) 
                fun(s, st, ans, i+1, curr+temp+" ");
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin() , wordDict.end());
        vector<string> ans;
        fun(s, st, ans, 0, "");
        return ans;
    }
};
