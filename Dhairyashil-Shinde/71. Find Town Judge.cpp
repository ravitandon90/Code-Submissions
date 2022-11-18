class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        unordered_map<int, int> a;
        unordered_map<int, int> b;
        
        for(auto i : trust) a[i[0]]++;
        for(auto i : trust) b[i[1]]++;
        
        for(int i=1; i<=n; i++) 
            if(a[i]==0 && b[i]==n-1) 
                return i;
        
        return -1;
    }
};
