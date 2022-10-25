class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "", b = "";
        for(auto c: word1) {
            a += c;
        }
        for(auto c: word2) {
            b += c;
        }
        return a == b;
    }
};