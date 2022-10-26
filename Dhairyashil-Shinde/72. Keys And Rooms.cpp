class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            
            int roomIdx = q.front(); 
            q.pop();
            
            visited[roomIdx] = true;
            
            // push every room visitable from current room into queue
            for(auto adjRoom : rooms[roomIdx])
                if(!visited[adjRoom]) 
                    q.push(adjRoom);
        }
        
        // return false if any room has not yet been visited
        for(auto v : visited) 
            if(!v) 
                return false; 
        
        return true;
    }
};
