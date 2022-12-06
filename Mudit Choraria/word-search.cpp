class Solution {
public:
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int curr) {
        if(i < 0 || i == m || j < 0 || j == n) {
            return false;
        }
        if(board[i][j] != word[curr] || board[i][j] == '*') {
            return false;
        }
        if(curr == word.size() - 1) {
            return true;
        }

        char cache = board[i][j];
        board[i][j] = '*';

        bool isExist = dfs(board, word, i + 1, j, curr + 1) 
        || dfs(board, word, i - 1, j, curr + 1)
        || dfs(board, word, i, j + 1, curr + 1)
        || dfs(board, word, i, j - 1, curr + 1);

        board[i][j] = cache;
        return isExist;
    }
};