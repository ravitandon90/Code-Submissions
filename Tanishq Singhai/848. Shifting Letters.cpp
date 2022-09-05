class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
    string shiftingLetters(string s, vector<int>& shifts) {
        for (int i = shifts.size() - 2; i >= 0; i--)
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        for (int i = 0; i < shifts.size(); i++)
            s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
        return s;
    }
};
