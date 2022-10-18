class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> result=new ArrayList<>();
        backtrack(result, s, new StringBuilder(), 0);
        return result;
    }
    public void backtrack(List<String> result, String s, StringBuilder sb, int ind){
        if(ind==s.length()){
            StringBuilder copy=new StringBuilder(sb);
            result.add(copy.toString());
            return;
        }
        char curr=s.charAt(ind);
        if(Character.isDigit(curr)){
            sb.append(curr);
            backtrack(result, s, sb, ind+1);
            sb.deleteCharAt(sb.length()-1);
        }else{
            sb.append(Character.toLowerCase(curr));
            backtrack(result, s, sb, ind+1);
            sb.deleteCharAt(sb.length()-1);
            sb.append(Character.toUpperCase(curr));
            backtrack(result, s, sb, ind+1);
            sb.deleteCharAt(sb.length()-1);
        }
    }
}
