class Solution {
    public int minReorder(int n, int[][] connections) {
        
        List<List<Pair<Integer, Boolean>>> graph = new ArrayList<>();
        for(int i = 0; i< n; i++) graph.add(new ArrayList<>());
        for(int[] c: connections){
            graph.get(c[0]).add(new Pair(c[1], true));
            graph.get(c[1]).add(new Pair(c[0], false));
        }
        return dfs(0, -1, graph);
    }
    private int dfs(int node, int prev, List<List<Pair<Integer, Boolean>>> graph){
        int totalChanges = 0;
        for(Pair p: graph.get(node)) { 
            if((int)p.getKey() == prev) continue;
            if((boolean)p.getValue()) totalChanges++;
            totalChanges += dfs((int)p.getKey(), node, graph);
        }
        return totalChanges;
    }
}
