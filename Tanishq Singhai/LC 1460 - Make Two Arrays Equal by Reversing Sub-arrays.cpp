class Solution {
public:
    // Time complexity - O(n)
    // Space Complexity - O(n)
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size(), count=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[target[i]]++, m[arr[i]]--;
        }
        for(auto i:m)
        {
            if(i.second!=0)
                return false;
        }
        return true;
    }
};