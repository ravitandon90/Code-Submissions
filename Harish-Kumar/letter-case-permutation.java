/* 

https://leetcode.com/problems/letter-case-permutation/

*/

class Solution {

    public List<String> letterCasePermutation(String s) {
        List<String> result = new ArrayList<>();

        StringBuilder sb = new StringBuilder();
        generatePermutation(0, s.length(), s, sb, result);

        return result;
        // 1) create an global variable
        // 2) Declare a fucntion with ArrayList<String>
        // 3) check if i == n else continue with the task

    }

    public void generatePermutation(int i, int n, String s, StringBuilder sb, List<String> result) {
        if (i == n) {
            StringBuilder copy = new StringBuilder(sb);
            result.add(copy.toString());
            return;
        }
        char ch = s.charAt(i);

        if (Character.isDigit(ch)) {
            sb.append(ch);
            generatePermutation(i + 1, n, s, sb, result);
            sb.deleteCharAt(sb.length() - 1);
        } else {
            sb.append(Character.toLowerCase(ch));
            generatePermutation(i + 1, n, s, sb, result);
            sb.deleteCharAt(sb.length() - 1);
            sb.append(Character.toUpperCase(ch));
            generatePermutation(i + 1, n, s, sb, result);
            sb.deleteCharAt(sb.length() - 1);

        }

    }
}