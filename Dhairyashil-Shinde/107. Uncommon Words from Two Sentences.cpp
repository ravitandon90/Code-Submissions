class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        // concatenating strings s1 and s2 into s1
        // adding space at the end of s1 so that words dont mix into each other
        s1 += " "; 
        s1 += s2;

        vector<string> ans;
        unordered_map<string, int> m;

        string temp = "";
        for(int i=0; i<s1.length(); i++) {
            
            // Case when we are considering last word of the string
            if(i==s1.length()-1) {
                temp += s1[i];
                if(temp.length()!=0) {
                    m[temp]++;
                }
                break;
            }

            // when we found space it means 'temp' string contains 1 word
            if(s1[i] == ' ') {
                if(temp.length()!=0) {
                    m[temp]++;
                }
                temp = ""; // make string empty for considering next word
                continue; // skip to next iteration, dont add space to temp
            }

            temp += s1[i]; // make 'string' (word) by concatenating 'char'
        }


        for(auto i:m) {
            if(i.second == 1) { // appears exactly once
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};
