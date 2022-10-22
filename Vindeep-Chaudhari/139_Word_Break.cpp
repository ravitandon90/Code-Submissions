/**
 * Problem Link - https://leetcode.com/problems/word-break/
 */

// Trie + memoized

class TrieNode {
    public:
    unordered_map<char, TrieNode*> children;
    bool isTerminal = false;
};

class Trie {
    public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        
        for(int i = 0; i< word.length(); i++) {
            if(node->children.find(word[i]) == node->children.end()) {
                node->children[word[i]] = new TrieNode();
            }
            
            node = node->children[word[i]];
        }
        
        node->isTerminal = true;
    };
    
    bool search(string word) {
          TrieNode* node = root;

          for(int i = 0; i < word.length(); i++) {
            if(node->children.find(word[i]) == node->children.end()) {
              return false;
            }

            node = node->children[word[i]];
          }

          return node->isTerminal;
    };
};

class Solution {
public:
    bool solve(Trie* t, string& s, int start, int n, vector<vector<int>>& dp) {
        if(start == n) return true;
        
        if(dp[start][n] != -1) {
            return dp[start][n];
        }
        
        for(int i = start; i < n; ++i) {
            string str = s.substr(start, i - start + 1);
            if(t->search(str)) {
                if(solve(t, s, i+1, n, dp)) {
                    return dp[start][n] = true;
                }
            }
        }
        
        return dp[start][n] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* t = new Trie();
        
        for(int i = 0; i < wordDict.size(); i++) {
            t->insert(wordDict[i]);
        }
        
        vector<vector<int>> dp (s.length()+1, vector<int> (s.length()+1, -1));
        
        return solve(t, s, 0, s.length(), dp);
        
    }
};



// Map + memoized

class Solution {
public:
    bool solve(unordered_map<string,bool>& mp, string& s, int start, int n, vector<vector<int>>& dp) {
        if(start == n) return true;
        
        if(dp[start][n] != -1) {
            return dp[start][n];
        }
        
        for(int i = start; i < n; ++i) {
            string str = s.substr(start, i - start + 1);
            if(mp.find(str) != mp.end()) {
                if(solve(mp, s, i+1, n, dp)) {
                    return dp[start][n] = true;
                }
            }
        }
        
        return dp[start][n] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mp;
        
        for(int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]] = true;
        }
        
        vector<vector<int>> dp (s.length()+1, vector<int> (s.length()+1, -1));
        
        return solve(mp, s, 0, s.length(), dp);
        
    }
};



