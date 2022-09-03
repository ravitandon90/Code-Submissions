/**
 * Problem Link - https://leetcode.com/problems/accounts-merge/
 */

 class Solution {
public:
    void DFSUtil(string accountEmail, unordered_map<string, vector<string>>& adj, unordered_map<string, bool>& visited, vector<string>& emails ) {
        visited[accountEmail] = true;
        emails.push_back(accountEmail);
        
        for(auto email : adj[accountEmail]) {
            if(!visited[email]) {
                DFSUtil(email, adj, visited, emails);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> adj;
        
        for(auto account: accounts) {
            string accountEmail = account[1];
            for(int i = 2; i < account.size(); i++) {
                string email = account[i];
                adj[accountEmail].push_back(email);
                adj[email].push_back(accountEmail);
            }
        }
        
        vector<vector<string>> mergedAccounts;
        unordered_map<string, bool> visited;
        for(auto account: accounts) {
            string accountName = account[0];
            string accountEmail = account[1];
            
            if(!visited[accountEmail]) {
                vector<string> emails;
                emails.push_back(accountName);
                DFSUtil(accountEmail, adj, visited, emails);
                
                sort(emails.begin()+1, emails.end());
                mergedAccounts.push_back(emails);
            }
        }
        
        return mergedAccounts;
    }
};

// Time complexity - O(NElogNE), N - no of accounts, E - no of Emails
// Space complexity - O(NE)