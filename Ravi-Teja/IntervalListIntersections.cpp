class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0, j=0, m=firstList.size(), n=secondList.size();
        while(i<m && j<n){
            if(firstList[i][1]>=secondList[j][0] && firstList[i][1]<=secondList[j][1]){
                ans.push_back({max(firstList[i][0],secondList[j][0]), min(firstList[i][1], secondList[j][1])});
                i++;
            }
            else if(secondList[j][0]<=firstList[i][1] && secondList[j][1]>=firstList[i][0]){
                ans.push_back({max(firstList[i][0],secondList[j][0]), min(firstList[i][1], secondList[j][1])});
                j++;
            }
            else if(firstList[i][1]<secondList[j][0]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};