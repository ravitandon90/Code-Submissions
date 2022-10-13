class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1){
            return {{1}};
        }
        vector<vector<int>> ans;
        ans.push_back({1});
        vector<int> temp;
        for(int i=2;i<=numRows;i++){
            temp.clear();
            temp.push_back(1);
            for(int j=0;j<i-2;j++){
                temp.push_back(ans[i-2][j]+ans[i-2][j+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};
