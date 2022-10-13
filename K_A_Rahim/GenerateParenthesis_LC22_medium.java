class Solution { 
    List<String> result = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
       genNestedParenthesis(n,0,0,new StringBuilder());
       return  result; 
    }
    private void genNestedParenthesis(int numOfPairOfBracket, int indexOpen, int indexClose, StringBuilder currentString)
    {
        if(currentString.length() == numOfPairOfBracket * 2)
        {
            result.add(currentString.toString());
            return;
        }
            if(indexOpen < numOfPairOfBracket)
            {
            currentString.append('('); 
            genNestedParenthesis(numOfPairOfBracket,indexOpen+1,indexClose,currentString);
            currentString.deleteCharAt(currentString.length() - 1);
            }
             if(indexClose < indexOpen)
            {
            currentString.append(')');
            genNestedParenthesis(numOfPairOfBracket,indexOpen,indexClose+1,currentString);
            currentString.deleteCharAt(currentString.length() - 1);
            }
        
    }
}