class Solution {
public:
    int thirdMax(vector<int>& a) {
        set<int> st;
        for(auto x: a) {
            st.insert(x);
            if(st.size() > 3) st.erase(st.begin());
        }
        return st.size() == 3 ? *st.begin() : *st.rbegin();
    }
};