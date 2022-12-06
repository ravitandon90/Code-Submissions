class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        vector<vector<string>> ans;
        if(n==0) return ans;
        if(n==1) return {{strs[0]}};
        
        unordered_map< string, vector<string> > m;
        
        for(int i=0; i<n; i++) {
            
            string toSort = strs[i];
            
            // Sorting the string
            sort(toSort.begin(), toSort.end()); 
            
            // Map = Key (Sorted String) -> Value (Initial String)
            m[toSort].push_back(strs[i]); 
        }
        
        // Traversing the map and adding the vectors of string to ans
        for(auto i : m) {
            ans.push_back(i.second);
        }
        return ans;
    }
    
    /*
    // Below Code will give the TLE 
    // for test case: https://leetcode.com/submissions/detail/831924466/testcase/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        vector<vector<string>> ans;
        if(n==0) return ans;
        
        vector<bool> vis(n, false);
        
        string s1;
        string s2;
        
        for(int i=0; i<n; i++) { 
            
            if(vis[i] == true) continue;
            
            s1 = strs[i];
            sort(s1.begin(), s1.end());
            
            vector<string> temp;
            temp.push_back(strs[i]);
            
            for(int j=i+1; j<n; j++) {
                
                if(vis[j] == true) continue;
                
                s2 = strs[j];
                sort(s2.begin(), s2.end());
                
                if(s1 == s2) {
                    temp.push_back(strs[j]);
                    vis[j] = true;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
    */
    
};
