class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> res;
        int i=0,j=0,m=f.size(),n=s.size();
        if(m==0 || n==0)
            return {};
        while(i<m && j<n)
        {
            int k1=max(f[i][0],s[j][0]);
            int l1=min(f[i][1],s[j][1]);
            if(k1<=l1)
                res.push_back({k1,l1});
            if(f[i][1]<s[j][1])
                i++;
            else 
                j++;
        }
        return res;
    }
};
