
/* 

leetcode - https://leetcode.com/problems/generate-parentheses/

*/

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        recurr(0, 0, n, result, sb);
        return result;
    }

    public void recurr(int open, int close, int n, List<String> result, StringBuilder sb) {
        if (sb.length() == n * 2) {
            result.add(sb.toString());
            return;
        }
        if (open < n) {
            sb.append("(");
            recurr(open + 1, close, n, result, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
        if (close < open) {
            sb.append(")");
            recurr(open, close + 1, n, result, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}