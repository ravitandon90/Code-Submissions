public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int position = 0;
        int revNumMinusOne = 0;
        boolean isPositive = true;
        if(n % 2 != 0)
            isPositive = false;
      for(int i=31;i>=0;i--)
      {
           position = 31 - i;
        if(!isPositive && ((n >> i) & 1) == 0)
        {
           revNumMinusOne = revNumMinusOne | (1 << position); 
        }
          else if(isPositive && ((n >> i) & 1) == 1)
          {
              revNumMinusOne = revNumMinusOne | (1 << position); 
          }
      }
        if(isPositive)
            return revNumMinusOne;
        else
            return (0 - (revNumMinusOne+1));
        
    }
}