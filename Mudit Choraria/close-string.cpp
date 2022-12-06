class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) {
            return false;
        }
        vector<int> A(26, 0);
        vector<int> B(26, 0);
        for(int i = 0; i < word1.size(); i++) {
            A[word1[i] - 'a']++;
            B[word2[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            // set of char should be same
            if((A[i] != 0 && B[i] == 0) || (A[i] != 0 && B[i] == 0)) {
                return false;
            }
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for(int i = 0; i < 26; i++) {
            // set of char count should be same
            if(A[i] != B[i]) {
                return false;
            }
        }
        return true;
    }
};