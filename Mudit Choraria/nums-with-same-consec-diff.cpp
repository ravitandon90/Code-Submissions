class Solution {
private:
    vector<int> ans;
    bool isValid(int n) {
        return n >= 0 && n <= 9;
    }
public:
    void bfs(int n, int k, int len, int num) {
        if(len == n) {
            ans.push_back(num);
            return; 
        }
        int prev = num % 10 - k;
        int next = num % 10 + k;
        if(isValid(prev)) {
            bfs(n, k, len + 1, num * 10 + prev);
        }
        if(prev != next && isValid(next)) {
            bfs(n, k, len + 1, num * 10 + next);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i <= 9; i++) {
            bfs(n, k, 1, i);
        }
        return ans;
    }
};