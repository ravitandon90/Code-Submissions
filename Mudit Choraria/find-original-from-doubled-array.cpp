class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        queue<int> q;
        vector<int> ans;
        
        sort(changed.begin(), changed.end());
        
        for(auto num: changed) {
            if(!q.empty() && q.front() == num) {
                q.pop();
            } else {
                // in the queue, i am looking for the possible double which would match
                q.push(2 * num);
                ans.push_back(num);
            }
        }
        
        return q.empty() ? ans : vector<int>();
    }
};