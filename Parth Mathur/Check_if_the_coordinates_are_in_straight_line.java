class Solution {
    public boolean checkStraightLine(int[][] coordinates) 
    {
    int y = (coordinates[1][1] - coordinates[0][1]);
    int x = (coordinates[1][0] - coordinates[0][0]);
    
    for(int i  = 2 ; i< coordinates.length ;i++){
        
        int x2 = coordinates[i][0] - coordinates[i-1][0];
        int y2 = coordinates[i][1] - coordinates[i-1][1];
        
        if(x2*y!=y2*x){
            return false;
        }
                
    }   
    return true;
}
}
