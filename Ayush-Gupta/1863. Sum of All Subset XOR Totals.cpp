class Solution {
public:
    vector<vector<int>> subsets(vector< int>& s) 
    {   
        int i,j,n=s.size(),N=(1<<n)-1;
        vector<vector<int>> vv;
        for(i=0;i<=N;++i)
        {
            vector< int> v;
            for(j=0;j<n;++j)
            {
                if(i&(1<<(n-1-j)))
                {
                    v.push_back(s[j]);
                }
            }
            vv.push_back(v);
        }
        return vv;
    }
    int subsetXORSum(vector<int>& a) {
        int i,j,Xor,sum=0;
        vector<vector<int>> v=subsets(a);
        for(i=0;i<v.size();i++){
            Xor=0;
            for(j=0;j<v[i].size();j++){
                Xor=Xor^v[i][j];
            }
            sum+=Xor;
        }
        return sum;
    }
};