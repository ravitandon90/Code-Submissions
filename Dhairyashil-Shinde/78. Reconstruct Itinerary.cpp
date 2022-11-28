class Solution {
public:
    
    vector<string> res;
    
    // adjacency list
    
    unordered_map<string, multiset<string>> mp;
    
    bool dfs(string u, int n)
    {
        // if we have traversed all the edges, then return 1
        
        if(res.size() == n + 1)
            return true;
        
        // if if there is no. adjacent of curr node, then return false
        
        if(mp[u].size() == 0)
            return false;
        
        multiset<string> s = mp[u];
        
        // check for all the adjacents of curr node
       
        for(auto v : s)
        {   
            // find the address of adjacent node
            
            auto it = mp[u].find(v);
            
            // erase the adjacent node
            
            mp[u].erase(it);
            
            // push the adjacent node into res
            
            res.push_back(v);
            
            // if the curr path lead to result then return true
            
            if(dfs(v, n))
                return true;
            
            // else backtrack
            
            else
            {
                res.pop_back();
                
                mp[u].insert(v);
            }
        }
        
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        int n = tickets.size();
        
        // make adjacency list
       
        for(int i = 0; i < tickets.size(); i++)
        {
            string u = tickets[i][0];
            
            string v = tickets[i][1];
            
            mp[u].insert(v);
        }
        
        // push the initial value
        
        res.push_back("JFK");
        
        dfs("JFK", n);
       
        return res;
    }
};
