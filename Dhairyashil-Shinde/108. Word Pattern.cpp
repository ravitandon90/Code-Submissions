class Solution {
public:

    /*
    // Incomplete Code
    void uncommonFromSentences(string s1, unordered_map<string, vector<int>> &m) {

        string temp = "";
        int index = 0;
        for(int i=0; i<s1.length(); i++) {
            
            if(i==s1.length()-1) {
                temp += s1[i];
                if(temp.length()!=0) {
                    // m[temp].push_back(i);
                    m[temp].push_back(index);
                }
                break;
            }

            if(s1[i] == ' ') {
                if(temp.length()!=0) {
                    // m[temp].push_back(i);
                    m[temp].push_back(index);
                }

                index++;

                temp = ""; 
                continue; 
            }
            temp += s1[i]; 
        }
    }

    bool wordPattern(string pattern, string s) {
        
        unordered_map<char, vector<int>> m1;
        unordered_map<string, vector<int>> m2;

        uncommonFromSentences(s, m2);

        for(int i=0; i<pattern.length(); i++) {
            m1[pattern[i]].push_back(i);
        }

        // Traverse through two maps simul. and check if those vectors are same in m1 and m2 for every key out there
        // unable to implement that

        return true;
    }
    */

    bool wordPattern(string pattern, string s) {

        unordered_map< char, set<string> >mp;
        unordered_map< string, set<char> > mp2;
        
        s+=" ";
        
        int k=0;
        
        for(int i=0, j=0; i<s.size(); j++, k++, i++){
            
            string p="";
            
            while(s[i]!=' ') {
                p+=s[i];
                i++;
            }
            
            mp[pattern[j]].insert(p);
            
            mp2[p].insert(pattern[j]);
        }

        // cout<<k;
        
        if(mp.size()!=mp2.size() or k!=pattern.size()) {
            return 0;
        }

        for(auto &b: mp2) {
            if(b.second.size()>1) {
                return 0;
            }
        }

        return 1;
    }

};
