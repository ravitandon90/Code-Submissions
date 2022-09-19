/* 
https://leetcode.com/problems/number-of-1-bits/
*/


public int hammingWeight(int n) {
    int ans =  0 ;
    int num = Math.abs(n);
    if( n < 0)
        num--;  // take 2's compliment if n is negative
   while(num >  0){
       if((num & 1) == 1){
           ans++;
       }
       num = num >>> 1;  // unsigned right shift
   }
    return n >= 0 ? ans :  32-ans;
}