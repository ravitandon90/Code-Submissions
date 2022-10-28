/**
 * Problem Link - https://leetcode.com/problems/find-the-town-judge/
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty() && n==1)
            return 1;
		
		vector<int> outDegrees (n+1);
	    vector<int> inDegrees (n+1);
		
		for(int i = 0; i < trust.size(); i++){
            outDegrees[trust[i][0]]++;
            inDegrees[trust[i][1]]++;
        }
		
		for(int i = 0; i <= n; i++){
            if(outDegrees[i]==0 && inDegrees[i]==n-1)
                return i;
        }

        return -1;
    }
};
