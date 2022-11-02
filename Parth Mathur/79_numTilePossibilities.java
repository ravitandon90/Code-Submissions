class Solution {
    public int numTilePossibilities(String tiles) {
        Set<String> set = new HashSet<>();
        boolean[] visited = new boolean[tiles.length()];
        backtrack(tiles, "", set, visited);
        return set.size();
    }
    
    private void backtrack(String tiles, String fixedChar, Set<String> set, boolean[] visited){
        if(fixedChar.length() > 0){
            if(set.contains(fixedChar)){
                return;
            }
            set.add(fixedChar);
        }
        
        for(int i = 0; i < tiles.length(); i++){
            if(visited[i]) continue;
            visited[i] = true;
            backtrack(tiles, fixedChar + tiles.charAt(i), set, visited);
            visited[i] = false;
        }
    }
}
