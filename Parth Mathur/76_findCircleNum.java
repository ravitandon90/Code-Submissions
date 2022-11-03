class Solution {
    public int findCircleNum(int[][] M) {
        int N = M.length;
        boolean[]visited = new boolean[N];
        int count = 0;
        
        for(int i = 0; i < N ;i++){
            if(!visited[i]){
                count++;
                dfs(M,i,visited);
            }
        }
      return count;  
    }
    
    
    private void dfs(int[][]M,int i,boolean[]visited){
        for(int j = 0 ; j < M[i].length ; j++){
            if(!visited[j] && M[i][j] != 0){
                visited[j] = true;
                dfs(M,j,visited);
            }
        }
    }
    
}
