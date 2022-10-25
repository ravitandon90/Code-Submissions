    int findCenter(vector<vector<int>>& edges) {
        // if first node of edge-0 occurs in edge-1 as well, it's the center one
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        // otherwise, the second node of edge-0 will be center node for sure
       return edges[0][1];
    }
