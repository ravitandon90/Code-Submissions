class Solution {
public:
    int check(string s1,string s2){
        // cout<<s1<<" "<<s2<<endl;
        int k = 0;
        int i,n = s1.length();
        for(i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                k++;
            }
        }
        return k;
    }
    int countSubstrings(string s, string t) {
        unordered_map<string,int> m1,m2;
        int k = min(s.length(),t.length());
        string str = "";
        int i,j,n = s.length();
        for(i = 0; i < n; i++){
            str = "";
            for(j = i; j < n && (j-i)<k ; j++){
                str += s[j];
                m1[str]++;
            }
        }
        n = t.length();
        for(i = 0; i < n; i++){
            str = "";
            for(j = i; j < n && (j-i) < k; j++){
                str += t[j];
                m2[str]++;
            }
        }
        // for(auto &i: m1){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }for(auto &i: m2){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        int ans = 0;
        for(auto &i: m1){
            
            for(auto &j: m2){
                if(((i.first).length() == (j.first).length()) && (check(i.first,j.first)==1)){
                    ans += i.second * j.second;
                }
            }
        }
        return ans;
    }
};
