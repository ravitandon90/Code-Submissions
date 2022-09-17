/* 

https://leetcode.com/problems/remove-invalid-parentheses/
*/

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        HashMap<String, Boolean> map = new HashMap<String, Boolean>();
        List<String> result = new ArrayList<>();
        int removals = find_removals(s);
        recurr(s, map, removals, result);
        return result;
    }

    public void recurr(String s, HashMap map, int removals, List<String> result) {
        if (map.get(s) == (Boolean) true) {
            return;
        }

        map.put(s, true);

        if (removals == 0) {
            int removals_needed = find_removals(s);
            if (removals_needed == 0)
                result.add(s);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            String left = s.substring(0, i);
            String right = s.substring(i + 1);
            recurr(left + right, map, removals - 1, result);
        }

        return;
    }

    public int find_removals(String s) {
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(')
                stk.push('(');
            else if (s.charAt(i) == ')') {
                if (!stk.empty() && stk.peek() == '(')
                    stk.pop();
                else
                    stk.push(')');
            }
        }
        return stk.size();
    }
}