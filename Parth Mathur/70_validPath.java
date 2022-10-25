class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) 
    {
        List<Integer>[] graph = new ArrayList[n];
        
        for(int i=0; i<n;i++)
            graph[i] = new ArrayList<>();
        
        for(int i=0; i<edges.length;i++)
        {
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            graph[v1].add(v2);
            graph[v2].add(v1);                
        }
        
        Queue<Integer> queue = new LinkedList<>();
        queue.add(source);
        
        boolean[] visited = new boolean[n];
        
        while(queue.size() > 0)
        {
            int current_node = queue.remove();
            
            if(visited[current_node] == true)
                continue;
            
            if(current_node == destination)
                return true;
            
            visited[current_node] = true;
            
            for(Integer neighbour: graph[current_node])
                queue.add(neighbour);
        }
        return false;
    }
}
