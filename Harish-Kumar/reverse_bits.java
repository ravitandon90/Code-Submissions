/* 
https://leetcode.com/problems/reverse-bits/submissions/
*/

public int reverseBits(int n) {
    int res = 0;
    for(int count = 31 ; count>=0 ; count--){
        int i = n & 1;
        res = res * 2 + i;
        n = n >> 1;
    }
    return res;
}