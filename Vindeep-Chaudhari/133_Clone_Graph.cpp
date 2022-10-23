/**
 * Problem Link - https://leetcode.com/problems/clone-graph/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* DFS(Node* curr, map <Node*, Node*>& mp ) {
        
        Node* clone = new Node(curr->val);
        mp[curr] = clone;
        for(auto neighbor: curr->neighbors) {
            if(mp.find(neighbor) != mp.end()) {
                clone->neighbors.push_back(mp[neighbor]);
            } else {
                clone->neighbors.push_back(DFS(neighbor, mp));
            }
        }
        
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        map <Node*, Node*> mp;
        
        if(node==NULL) {
            return NULL;
        } else if (node->neighbors.size() == 0) {
            Node* clone = new Node(node->val);
            return clone;
        } 
        
        return DFS(node, mp);
       
    }
};