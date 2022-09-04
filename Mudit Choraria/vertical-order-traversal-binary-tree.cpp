/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<int, TreeNode*>> q;
        map<int, vector<int>> mp;
        
        q.push({0, root});
        while(!q.empty()) {
            int n = size(q);
            vector<pair<int,int>> similarNodes;
            while(n--) {
                pair<int, TreeNode*> curr = q.front();
                q.pop();
                pq.push({curr.second->val, curr.first});
                if(curr.second->left) {
                    q.push({curr.first - 1, curr.second->left});
                }
                if(curr.second->right) {
                    q.push({curr.first + 1, curr.second->right});
                }
            }
            while(!pq.empty()) {
                mp[pq.top().second].push_back(pq.top().first);
                pq.pop();
            }
        }
        for(auto i: mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};