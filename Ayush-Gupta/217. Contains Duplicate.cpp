class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto x: nums) {
            if(st.find(x) != st.end()) return 1;
            st.insert(x);
        }
        return 0;
    }
};