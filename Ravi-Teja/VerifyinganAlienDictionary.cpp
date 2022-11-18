class Solution {
public:
    int ind[26];
    bool check(string &a, string &b){
        int n1=a.length();
        int n2=b.length();
        for(int i=0;i<min(n1, n2);i++){
            if(ind[a[i]-'a'] > ind[b[i]-'a']){
                return false;
            }
            else if(ind[a[i]-'a'] < ind[b[i]-'a']){
                return true;
            }
        }
        if(n1 > n2){
            return false;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> sortwords=words;
        int n= words.size();
        for(int i=0;i<26;i++){
            ind[order[i]-'a']=i;
        }
        string temp;
        for(int i=0;i<n-1;i++){
            if(!check(sortwords[i], sortwords[i+1])){
                return false;
            }
        }
        return true;
    }
};
