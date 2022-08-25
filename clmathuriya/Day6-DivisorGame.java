class Solution {
    //1025. Divisor Game https://leetcode.com/problems/divisor-game/
    // Alice will loose if n==1
    // for other values if n, it can be negation of (n-1) ie. alice will loose for odd numbers and win for even numbers.
    public boolean divisorGame(int n) {
        if(n%2==0){
            return true;
        }else{
            return false;
        } 
    }
    
}
