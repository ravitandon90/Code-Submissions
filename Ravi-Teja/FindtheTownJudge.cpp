class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return trust.size()==0 ? 1 : -1;
        }
        vector<int> count(n+1, 0);
        for(auto edge: trust){
            count[edge[1]]++;
            count[edge[0]]--;
        }
        for(int i=0;i<=n;i++){
            if(count[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};
