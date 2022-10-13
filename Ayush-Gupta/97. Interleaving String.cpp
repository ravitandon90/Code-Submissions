class Solution {
public:
    unordered_map<string,bool> dp;
    bool fun(string s1, string s2, string s3, int l1, int l2, int l3, int p1, int p2, int p3){
        if(p3==l3) return (p1==l1 && p2==l2)?1:0;
        string key=to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
        if(dp.find(key)!=dp.end()) return dp[key];
        if(p1==l1) return dp[key] = (s2[p2]==s3[p3])?fun(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1):0;
        if(p2==l2) return dp[key] = (s1[p1]==s3[p3])?fun(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1):0;
        bool one=0, two=0;
        if(s1[p1]==s3[p3]) one=fun(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
        if(s2[p2]==s3[p3]) two=fun(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
        return dp[key] = one||two;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.size(), l2=s2.size(), l3=s3.size();
        if(l1+l2!=l3) return 0;
        return fun(s1,s2,s3,l1,l2,l3,0,0,0);
    }
};