class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //to store the neighbors and weights corresponding to each vertices
        vector <vector<pair<int, int>>> neighs(n+1);       
  
        //pushing vertex, neighbor, weight in the proper format
        for(auto t: times) 
            neighs[t[0]].push_back({t[1], t[2]});
            
        //to store the time taken by signal to reach each vertices
        vector <int> res(n+1, INT_MAX);
        
        //min heap
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    
        //starting with the starting vertex
        pq.push({0, k}); 
        
        //since no time is required for starting vertex to reach itself
        res[k]=0;                                          
        
        while(!pq.empty()) {
            int vertex = pq.top().second;     
            pq.pop();
            
            //considering each neighbors
            for(auto neigh:neighs[vertex]){                
                //if time taken to reach end point(neigh.first) 
                // is more than time taken to reach 
                //starting point(i.e vertex) initially + time taken(i.e neigh.second)
                // to reach from
                
                //starting to end with another path
                if(res[vertex]+neigh.second<res[neigh.first]) { 
                
                    //updating time for shorter path
                    res[neigh.first]=res[vertex]+neigh.second;
                    
                    //pushing for the further journey from end point(i.e neigh.first)
                    pq.push({res[neigh.first], neigh.first});
                }
            }
        }
        
        //to get max time taken
        int ans=*max_element(res.begin()+1, res.end());     
        //if it is impossible for all nodes to receive signal, 
        // i.e we still have INT_MAX in res 
        
        //array, so return -1. Else return ans
        return ans==INT_MAX?-1:ans;                         
    }
};
