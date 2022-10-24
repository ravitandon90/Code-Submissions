/**
 * Problem Link - https://leetcode.com/problems/employee-importance/
 */

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
    void dfs(unordered_map<int,Employee*>& emp, unordered_map<int,bool>& visited, Employee* employee, int& importance) {
        
        visited[employee->id] = true;
        importance += employee->importance;
        
        for(int i = 0; i < employee->subordinates.size(); i++) {
            if(!visited[employee->subordinates[i]]) {
                dfs(emp, visited, emp[employee->subordinates[i]], importance);
            }
        }
        
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,bool> visited;
        unordered_map<int,Employee*> emp;
        
        for(int i = 0; i < employees.size(); i++) {
            emp[employees[i]->id] = employees[i];
        }
        
        
        int importance = 0;
        for(int i = 0; i < employees.size(); i++) {
            if(employees[i]->id == id) {
                dfs(emp, visited, employees[i], importance);
            }
        }
        
        return importance;
    }
};