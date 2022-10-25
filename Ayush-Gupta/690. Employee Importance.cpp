/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(unordered_map<int, Employee*> &mp, int id, int &ans) {
        ans+=(mp[id]->importance);
        for(auto x: mp[id]->subordinates) dfs(mp, x, ans);
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for(auto x: employees) mp[x->id]=x;
        int ans=0;
        dfs(mp, id, ans);
        return ans;
    }
};