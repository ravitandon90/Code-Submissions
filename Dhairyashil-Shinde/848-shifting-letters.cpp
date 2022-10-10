class Solution {
public:
    
    string shiftingLetters(string s, vector<int>& shifts) {
        
        int n = s.length();
        long long int sum = 0;
        
        for(int i = n-1;i>=0;i--){
            
            sum = (sum + shifts[i])%26 ; 
            
            long long int temp = s[i]-'a';
            
            temp = (temp + sum)%26;
            
            s[i] = 'a' + temp;
            
        }
        return s;
    }
};

/*
    string shiftingLetters(string s, vector<int>& shifts) {
        long shift = 0;
        for(int i=s.size()-1; i>=0; i--) {
            s[i] = ( (s[i]-'a') + (shift+shifts[i]) % 26) % 26 +'a';
            shift += shifts[i];
        }
        return s;
    }
*/
