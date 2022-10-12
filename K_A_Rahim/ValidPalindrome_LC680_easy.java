public class Main {
    public static void main(String[] args) {
        System.out.println(validPalindrome("tcaac"));
    }
    private static boolean validPalindrome(String s) {
    int length = s.length();
     for(int i=0;i<length/2;i++)
     {
        if(s.charAt(i) != s.charAt(length - 1 - i))
         return isPalindrome(i,length - 2 - i,s) || isPalindrome(i+1,length - 1 - i,s);
     }
      return true; // returns true if single element or full palindrome
    }
    private static boolean isPalindrome(int start, int end, String s)
    {
      while(start < end)
      {
          if(s.charAt(start) != s.charAt(end))
          return false;
          start++;
          end--;
      }
      return true; // returns true if start = end
    }
}