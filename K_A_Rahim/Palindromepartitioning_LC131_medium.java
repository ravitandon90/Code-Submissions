class Solution { 
    List<List<String>> results = new ArrayList<>();
    public List<List<String>> partition(String s) {
        partitionTheString(new ArrayList<String>(),0,s); 
     return results;  
    }
    private void partitionTheString(ArrayList<String> currstring,int index,String s)
    {
       // basecase
      if(index == s.length())
      {
          results.add(new ArrayList<String>(currstring));
          return;
      }
      for(int i=index;i<s.length();i++)
      {
       String currStr = s.substring(index,i+1);
       if(isPalindrome(currStr))
       {
          currstring.add(currStr);
          partitionTheString(currstring,i+1,s);
          currstring.remove(currstring.size() - 1);
       }
      }
    } 
    
     private boolean isPalindrome(String givenStr)
    {
        if(givenStr.length() <= 1)
        return true;
        char firstChar = givenStr.charAt(0);
        char lastChar = givenStr.charAt(givenStr.length() - 1);
      if(lastChar != firstChar)
      return false;
      String subStr = givenStr.substring(1,givenStr.length() - 1);
      return isPalindrome(subStr);
    }
   
}