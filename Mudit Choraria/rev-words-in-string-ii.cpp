class Solution {
    public:
        void reverseWords(vector < char > & s) {
            reverse(begin(s), end(s)); 
            reverseWords(s, s.size()); 
        }

    private:
        void reverseWords(vector < char > & s, int n) {
            int i = 0;
            int j = 0;

            while (i < n) {
                while (i < j || i < n && s[i] == ' ') 
                    ++i;
                while (j < i || j < n && s[j] != ' ') 
                    ++j;
                reverse(begin(s) + i, begin(s) + j); 
            }
        }
};
