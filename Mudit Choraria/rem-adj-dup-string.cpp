class Solution {
public:
    string removeDuplicates(string s) {
        int k = 2;
        vector<pair<char, int>> stk;
        for(char c: s) {
            if(!stk.empty() && stk.back().first == c) {
                stk.back().second++;
            } else {
                stk.push_back({c, 1});
            }
            if(stk.back().second == k) {
                stk.pop_back();
            }
        }
        s.clear();
        for(const auto& [character, count] : stk) {
            s.append(count, character);
        }
        return s;
    }
};