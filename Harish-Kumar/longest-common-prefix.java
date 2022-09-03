/* 

https://leetcode.com/problems/longest-common-prefix/

*/

class Solution {
    public String longestCommonPrefix(String[] strs) {
        String output = strs[0];
        for (int i = 1; i < strs.length; i++) {
            output = compare(output, strs[i]);
        }
        return output;
    }

    public String compare(String output, String str) {
        int n = Math.min(output.length(), str.length());
        int i = 0;
        for (i = 0; i < n; i++) {
            if (output.charAt(i) != str.charAt(i)) {
                break;
            }
        }

        return str.substring(0, i);
    }
}