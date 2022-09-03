
/* 
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<Character>();
        int count = 0;
        int start = 0, end = 0;
        int n = s.length();
        while (start < n && end < n) {

            if (!set.contains(s.charAt(end))) {
                set.add(s.charAt(end));
                end++;
            } else {
                set.remove(s.charAt(start));
                start++;
            }
            count = Math.max(set.size(), count);
        }

        return count;
    }
}