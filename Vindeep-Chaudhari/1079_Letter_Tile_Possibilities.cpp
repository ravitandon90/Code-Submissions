/**
 * Problem Link - https://leetcode.com/problems/letter-tile-possibilities
 */

class Solution {
public:
    void backtrack(string tiles, set<string>& ans, int index, string seq, vector<bool>& visited) {
        if(index == tiles.length()) {
            return;
        }

        for(int i = 0; i < tiles.length(); i++) {
            if(visited[i] == false) {
                visited[i] = true;
                ans.insert(seq+tiles[i]);
                backtrack(tiles, ans, index+1, seq+tiles[i], visited);
                visited[i]   = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        set<string> ans;
        vector<bool> visited (tiles.length(), false);

        backtrack(tiles, ans, 0, "", visited);

        for(auto i : ans) cout<<i<<" ";

        return ans.size();
    }
};