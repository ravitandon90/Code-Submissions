class Solution
{
public List<String> removeInvalidParentheses(String s) {
    int rmL = 0, rmR = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.charAt(i) == '(') {
            rmL++;
        } else if (s.charAt(i) == ')') {
            if (rmL != 0) {
                rmL--;
            } else {
                rmR++;
            }
        }
    }
    Set<String> res = new HashSet<>();
    removeParenthesis(s, 0, res, new StringBuilder(), rmL, rmR, 0);
    return new ArrayList<String>(res);
}

public void removeParenthesis(String s, int i, Set<String> res, StringBuilder sb, int leftP, int rightP, int open) {
    if (leftP < 0 || rightP < 0 || open < 0) {
        return;
    }
    if (i == s.length()) {
        if (leftP == 0 && rightP == 0 && open == 0) {
            res.add(sb.toString());
        }        
        return;
    }

    char c = s.charAt(i); 
    int len = sb.length();

    if (c == '(') {
        removeParenthesis(s, i + 1, res, sb, leftP - 1, rightP, open);		    
    	removeParenthesis(s, i + 1, res, sb.append(c), leftP, rightP, open + 1);     

    } else if (c == ')') {
        removeParenthesis(s, i + 1, res, sb, leftP, rightP - 1, open);	           
    	removeParenthesis(s, i + 1, res, sb.append(c), leftP, rightP, open - 1);  	 

    } else {
        removeParenthesis(s, i + 1, res, sb.append(c), leftP, rightP, open);	
    }

    sb.setLength(len);        
}
}