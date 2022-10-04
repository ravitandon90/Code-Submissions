/**
 * Problem Link - https://leetcode.com/problems/is-subsequence/
 */

// One

class Solution {
public:
    bool isSubsequence(string s, string t) {
    
        if(s.length() == 0) return true;
        if(s.length() > t.length() || t.length() == 0) return false;
        
        int j = 0;
        for(int i = 0; i < t.length(); i++) {
            if(j >= s.length()) return true;
            
            if(t[i] == s[j]){
                j++;
            }
        }
        
        if(j >= s.length()) return true;
        
        return false;
    }
};

// Follow - up 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> store;
        
        for(int i = 0; i < t.length(); i++) {
            store[t[i]].push_back(i);
        }
        
        int prevInd = -1;
        for(int i = 0; i < s.length(); i++) {
            
            auto it = store.find(s[i]);
            if(it == store.end()) return false;
            
            vector<int> indices = it->second;
            int ind = upper_bound(indices.begin(), indices.end(), prevInd) - indices.begin();
            
            if(ind == indices.size()) return false;
            
            prevInd = indices[ind];
        }
        
        return true;
    }
};