class Solution {
  private int invalidCount = 0;
  private Set<String> set = new HashSet<>();
  
  public List<String> removeInvalidParentheses(String s) {
    setInvalidCount(s);
    dfs(s, 0, 0, new StringBuilder(), 0);
    return new ArrayList<>(set);
  }
  
  private void dfs(String s, int idx, int open, StringBuilder sb, int removed){
    if(idx == s.length() && open == 0){
      set.add(sb.toString());
      return;
    }
      
    if(idx == s.length() || removed > invalidCount)
      return;
    
    if(s.charAt(idx) == '('){
      dfs(s, idx+1, open+1, sb.append(s.charAt(idx)), removed);
      sb.deleteCharAt(sb.length() -1);
      
      dfs(s, idx+1, open, sb, removed+1);
      
    } else if(s.charAt(idx) == ')'){
      if(open > 0){
        dfs(s, idx+1, open-1, sb.append(s.charAt(idx)), removed);
        sb.deleteCharAt(sb.length() -1);
      }
      
      dfs(s, idx+1, open, sb, removed + 1);
      
    } else {
      dfs(s, idx+1, open, sb.append(s.charAt(idx)), removed);
      sb.deleteCharAt(sb.length() -1);
    }
  }
  
  private void setInvalidCount(String s){
    int open = 0;
    int invalidClose = 0;
    
    for(char c: s.toCharArray()){
    
      if(c == '(')
        open++;
      else if(c == ')'){
        if(open > 0)
          open--;
        else
          invalidClose++;
      }
    }
    
    invalidCount = open + invalidClose;
  }
}
