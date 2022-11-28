class Solution {
public:
    
    void solve(string& tiles, unordered_set<string>& hash, string word, int idx){
        if(idx==tiles.size()) {
            if(word.size()==0) return;
            hash.insert(word);
            return;
        }
        for(int i=0; i<tiles.size(); ++i){
            if(tiles[i]=='*') continue;
            char tile = tiles[i];
            tiles[i] = '*';
            word.push_back(tile);
            solve(tiles, hash, word, idx+1);
            word.pop_back();
            solve(tiles, hash, word, idx+1);
            tiles[i] = tile;
        }
    }
    
    int numTilePossibilities(string tiles) {
        unordered_set<string> hash;
        solve(tiles, hash, "",0);
        return hash.size();
    }
};
