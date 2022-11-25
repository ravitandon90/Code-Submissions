class Solution {
public:

    /*
    // Incomplete Code... Complete this After you get time
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        unordered_map<char, int> m, copym;
        for(int i=0; i<licensePlate.length(); i++) {
            if(licensePlate[i] >= 'A' && licensePlate[i] <= 'Z') {
                licensePlate[i] = tolower(licensePlate[i]);
                m[licensePlate[i]]++;
            }
            else if(licensePlate[i] >= 'a' && licensePlate[i] <= 'z') {
                m[licensePlate[i]]++;
            }
        }

        string ans = "";
        string temp = "";
        stack<string> st;
        for(int i=0; i<words.size(); i++) {

            temp = words[i];
            copym = m;
            for(int j=0; j<temp.length(); j++) {
                if(copym[temp[j]] > 0) {
                    copym[temp[j]]--;
                }
            }

            cout << copym.size() << endl;

            for(auto p : copym) {
                cout << p.first << " -> " << p.second << endl;
            }

            int cntZero = 0;
            for(auto p : copym) {
                if(p.second == 0) {
                    cntZero++;
                }
            }

            string prev_temp;
            if(copym.size() == cntZero) {
                
                if(st.size() != 0) {
                    prev_temp = st.top();

                    if(prev_temp.length() > temp.length()) {
                        st.pop();
                        st.push(temp);
                    }

                }
                else {
                    st.push(temp);
                }
            }
            ans = st.top();
        }
        return ans;
    }
    */

    
    string shortestCompletingWord(string str, vector<string>& words) 
    {
        unordered_map<char,int>mp1;
        for(int i=0;i<str.length();i++)
        {
            char ch = str[i];
            if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z'))
            {
            char temp = char(tolower(ch));
            mp1[temp]++;	
            }	
        }        
        string ans = "";
        for(int i=0;i<words.size();i++)
        {
            string s = words[i];
            unordered_map<char,int>mp2;
            
            for(int j=0;j<s.length();j++)
            {
                char ch = s[j];
                if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z'))
                {
                char temp = char(tolower(ch));
                mp2[temp]++;	
                }	
            }
            bool flag=true;  //asuming it to be a completeing word
            
            for(auto it = mp1.begin() ; it!=mp1.end() ; it++)
            {
                char ch = it->first;
                int freq = it -> second;
                
                if(mp2.find(ch)==mp2.end())
                {
                flag=false;
                break;
                    
                }
                if(mp2.find(ch)!=mp2.end() and mp2[ch]<freq)
                {
                    flag=false;
                    break;
                }
            }
            
            if(flag==true)
            {
                if(ans.length()==0)
                {
                    ans = s;
                }
                else if(ans.length()>0 and s.length()<ans.length())
                {
                    ans = s;
                }
            }
        }
        return ans;
    }
};
