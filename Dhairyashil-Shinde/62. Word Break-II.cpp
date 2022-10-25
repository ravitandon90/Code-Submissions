class Solution {
public:
    
    void dfs(string s,string sentence, unordered_set<string>& setting,vector<string> &ans) {
        
        if(s.empty()) {
            sentence.pop_back();
            ans.push_back(sentence);
            return;
        }
        
        int n = s.size();
        for(int i = 1; i <= n; i++) {
            if(!setting.count(s.substr(0, i))) continue;
            dfs(s.substr(i), sentence + s.substr(0, i) + " ", setting, ans);
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        vector<string> ans;
        unordered_set<string> setting;
        setting.insert(wordDict.begin(), wordDict.end());
        dfs(s, "", setting, ans);
        return ans;
    }
};
