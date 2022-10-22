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
    
    int getImportance(vector<Employee*> employees, int id) {
        
        int result = 0;
        unordered_map<int, Employee*> m;
        
        for(auto& employee : employees) 
            m[employee->id] = employee;
        
        queue<Employee*> q;
        q.push(m[id]);
        
        while (!q.empty()) {
        
            Employee* temp = q.front();  
            q.pop();
            
            result += temp->importance;
            for (int s : temp->subordinates) {
                q.push(m[s]);
            }
        }
        return result;
    }
    
};
