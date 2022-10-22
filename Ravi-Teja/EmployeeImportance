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
    int importance(int id, pair<int, vector<int>> adj[]){
        int totalImportance=adj[id].first;
        for(int i=0;i<adj[id].second.size();i++){
            totalImportance+=importance(adj[id].second[i], adj);
        }
        return totalImportance;
    }
    int getImportance(vector<Employee*> employees, int id) {
        pair<int, vector<int>> adj[2002];
        for(int i=0;i<employees.size();i++){
            adj[employees[i]->id]={employees[i]->importance, employees[i]->subordinates};
        }
        return importance(id, adj);
    }
};
