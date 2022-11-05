class Solution {
public:
    map<pair<int,string>,bool> find;
    bool helper(int i, int n, unordered_map<string,int> &mp, string &s, string &temp){
        if(i>=n){
            if(mp.count(temp)>0){
                return true;
            }
            return false;
        }
        if(find.count({i, temp}) > 0){
            return find[{i, temp}];
        }
        bool ans=false;
        temp.push_back(s[i]);
        ans=ans || helper(i+1, n, mp, s, temp);
        temp.pop_back();
        string store=temp;
        if(mp.count(temp) > 0){
            temp="";
            temp.push_back(s[i]);
            ans= ans || helper(i+1, n, mp, s, temp);
            temp.pop_back();
        }
        temp=store;
        return find[{i, temp}]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto word: wordDict){
            mp[word]++;
        }
        string temp="";
        return helper(0, s.length(), mp, s, temp);
    }
};
