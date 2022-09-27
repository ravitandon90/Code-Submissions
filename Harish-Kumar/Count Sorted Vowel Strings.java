/* 

https://leetcode.com/problems/count-sorted-vowel-strings/
*/

class Solution {
    public int countVowelStrings(int n) {
        int a[] = { 1, 1, 1, 1, 1 };
        for (int i = 2; i <= n; i++) {
            a[0] = a[0] + a[1] + a[2] + a[3] + a[4];
            a[1] = a[1] + a[2] + a[3] + a[4];
            a[2] = a[2] + a[3] + a[4];
            a[3] = a[3] + a[4];
        }
        return a[0] + a[1] + a[2] + a[3] + a[4];
    }
}