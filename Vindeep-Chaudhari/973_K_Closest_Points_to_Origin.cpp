/**
 * Problem Link - https://leetcode.com/problems/k-closest-points-to-origin/
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue <pair<float,int>> pq;
        for(int i = 0; i < points.size(); i++) {
            auto point = points[i];

            auto x = point[0] * point[0];
            auto y = point[1] * point[1];

            auto dist = sqrt(x + y);
            pq.push({dist, i});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(pq.empty() == false) {
            auto popped = pq.top();
            pq.pop();
            ans.push_back(points[popped.second]); 
        }

        return ans;
    }
};


