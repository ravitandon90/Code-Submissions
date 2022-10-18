public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        int bit = 0;
       /* while(n != 0)
        {
            n = n & (n - 1);
            count++;
        }*/
        while(bit < 32)
        {
           if(((n >> bit) & 1 ) > 0)
               count++;
            bit++;
        }*/
        return count;
    }
}