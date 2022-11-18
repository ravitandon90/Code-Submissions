class Solution {
public://332. Reconstruct Itinerary
    void solve(string x,map<string,vector<string>>&mp,vector<string>&ans){
        while(!mp[x].empty()){
            int n=mp[x].size()-1;
            string s=mp[x][n];
            mp[x].pop_back();
            solve(s,mp,ans);
        }
        ans.push_back(x);
        return ;
    }
    static bool comp(string a,string b){
        if(a>b) return true;
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
        map<string,vector<string>> mp;
        
        for(int i=0;i<t.size();i++){
            mp[t[i][0]].push_back(t[i][1]);
        }
        
        auto it=mp.begin();
        while(it!=mp.end()){
            sort(it->second.begin(),it->second.end(),comp);
            it++;
        }
        vector<string> ans;
        solve("JFK",mp,ans);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};



    