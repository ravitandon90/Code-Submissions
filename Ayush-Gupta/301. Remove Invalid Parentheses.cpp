class Solution {
public:
    vector<string> ans;
    unordered_map<string, int> mp;
    int getMinInv(string s){
        stack<char> st;
        for(auto x: s){
            if(x=='(') st.push(x);
            else if(x==')'){
                if(st.size() && st.top()=='(') st.pop();
                else st.push(x);
            }
        }
        return st.size();
    }
    void solve(string s, int minInv){
        if(mp[s]!=0) return;
        mp[s]++;
        if(minInv<0) return;
        if(minInv==0){
            if(getMinInv(s)==0) ans.push_back(s);
            return;
        }
        for(int i=0;i<s.size();i++){
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(left+right, minInv-1);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        solve(s, getMinInv(s));
        return ans;
    }
};