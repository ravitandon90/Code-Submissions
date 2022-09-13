/**
 * Problem Link - https://leetcode.com/problems/combinations/
 */

class Solution {
public:
    vector<vector<int>> ans;
    void combinations(int n , int k, int num, vector<int>& combination, int sizeCombination) {
        if(sizeCombination == k) {
            ans.push_back(combination);
            return;
        }
        
        if(num > n) {
            return;
        }
        
        for(int i = num; i <= n; i++) {
            combination.push_back(i);
            combinations(n, k, i+1, combination, sizeCombination+1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        combinations(n, k, 1, combination, 0);
        
        return ans;
    }
};