/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) {
            return {};
        }
        
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> tmp;
            int n = size(q);
            
            while(n--) {
                Node* top = q.front();
                q.pop();
                
                tmp.push_back(top->val);
                
                for(auto i: top->children) {
                    q.push(i);
                }
            }
            
            ans.push_back(tmp);
        }
        
        return ans;
    }
};