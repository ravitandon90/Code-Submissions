/* 
https://leetcode.com/problems/divisor-game/
*/

class Solution {
    public boolean divisorGame(int n) {
        // the one who has the even one always wins
        return (n % 2 == 0);
    }
}