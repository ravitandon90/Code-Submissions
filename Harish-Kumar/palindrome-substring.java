/* 
https://leetcode.com/problems/palindrome-partitioning/
*/

class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> palindrome = new ArrayList<>();
        recurr(0, s.length(), s, res, palindrome);
        return res;
    }

    public void recurr(int ind, int n, String s, List<List<String>> res, List<String> palindrome) {
        if (ind == n) {
            res.add(new ArrayList<>(palindrome));
            return;
        }
        for (int i = ind; i < n; i++) {
            if (isPalindrome(s, ind, i)) {
                palindrome.add(s.substring(ind, i + 1));
                recurr(i + 1, n, s, res, palindrome);
                palindrome.remove(palindrome.size() - 1);
            }
        }

    }

    boolean isPalindrome(String s, int start, int end) {
        while (start <= end) {
            if (s.charAt(start++) != s.charAt(end--))
                return false;
        }
        return true;
    }
}