class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pQueue(stones.begin(), stones.end());
        // In priority_queue, By Default 'Max' element will come on top
        
        while(pQueue.size()>1) {

            int y = pQueue.top(); // heaviest one (Before poping this ele. out)
            pQueue.pop();
            
            int x = pQueue.top(); 
            pQueue.pop();
            
            if(x!=y) pQueue.push(y-x); // Given Condition
        }

        return pQueue.empty() ? 0 : pQueue.top();
    }
};
