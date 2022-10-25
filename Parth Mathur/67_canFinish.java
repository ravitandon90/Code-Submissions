class Solution {
    public boolean canFinish(int n, int[][] edges) 
    {
        List<List<Integer>> graph = create_graph(n , edges);   
        
        HashSet<Integer> visited = new HashSet<>();
        HashSet<Integer> recStack = new HashSet<>();
        List<Integer> traversal = new ArrayList<>();
        
        for(int currentVertex =0; currentVertex < n;currentVertex++)
        {
            if(visited.contains(currentVertex))
                continue;
            
            if(is_cyclic(graph , currentVertex, visited , recStack , traversal))
                return false;
        }
        return true;
    }
    
    private boolean is_cyclic(List<List<Integer>> graph , int currentVertex , HashSet<Integer> visited , HashSet<Integer> recStack , List<Integer> traversal)
    {
        visited.add(currentVertex);
        recStack.add(currentVertex);
        
        for(Integer neighbour: graph.get(currentVertex))
        {
            if(!visited.contains(neighbour))
            {
                if(is_cyclic(graph , neighbour , visited , recStack , traversal))
                    return true;
            }
                
            else if(recStack.contains(neighbour))
                return true;
        }
        
        traversal.add(currentVertex);
        recStack.remove(currentVertex);
        
        return false;
    }
    
    private List<List<Integer>> create_graph(int n , int[][] edges)
    {
        List<List<Integer>> graph = new ArrayList<>(n);
        
        for(int i=0; i<n;i++)
            graph.add(new ArrayList<>());
        
        for(int[] edge: edges)
        {
            int v = edge[0];
            int u = edge[1];
            
            graph.get(u).add(v);
        }
        return graph;
    }
}  
