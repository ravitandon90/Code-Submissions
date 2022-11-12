class Solution {
public:
    int firstUniqChar(string s) {

        // to store character and its count present in given string
        unordered_map<char, int> m;

        // elements are present in 'unordered_map' in order of 
        // how we put those elements in 'unordered_map'
        int n = s.length();
        for(int i=n-1; i>=0; i--) { // so put elements from back
            m[s[i]]++;      // bcoz we want ' first non-repeating character'
        }

        char ans; // store ans character
        bool isExist = false;
        for(auto i:m) {
            if(i.second == 1) {
                ans = i.first; // store character
                isExist = true;
                break;
            }
        }

        // when non-repeating character does not exist
        if(isExist == false) {
            goto here;
        }

        for(int i=0; i<n; i++) {
            if(s[i] == ans) { // search that character
                return i; // return it's index
            }
        }

        here:
        return -1;
    }
};
