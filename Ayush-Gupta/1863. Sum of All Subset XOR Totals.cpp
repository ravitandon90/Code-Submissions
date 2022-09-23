class Solution {
public:
    int f(int ind, int xorValue, vector<int> &a) {
        if(ind == a.size()) return xorValue;
        int pick = f(ind+1, xorValue^a[ind], a);
        int notPick = f(ind+1, xorValue, a);
        return pick + notPick;
    }
    int subsetXORSum(vector<int>& a) {
        int ind = 0, xorValue = 0;
        return f(ind, xorValue, a);
    }
};