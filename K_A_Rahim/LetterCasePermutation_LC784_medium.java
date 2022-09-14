import java.util.List;
import java.util.ArrayList;
public class Main {
    static List<String> results = new ArrayList<String>();
    public static void main(String[] args) {
        // Insert Your Code Here. Here are the steps to get started: 
        // Step-I: Define the input format using the examples from the problem description. 
        // Step-II: Parse input from standard in. 
        // Step-III: Write your algorithm to generate the required output. 
        // Note: In case of any issues use #feedback channel on Discord.
         generateStrings(0,new StringBuilder(),"a1b2");
         System.out.println(results); 
    }
    private static void generateStrings(int index,StringBuilder currString,String s)
    {
      if(index == s.length())
      {
          results.add(currString.toString()); 
          return;
      }
        char currChar = s.charAt(index);
      if(currChar >= '0' && currChar <= '9')
      {
          currString.append(currChar);
          generateStrings(index+1,currString,s);
          currString.deleteCharAt(currString.length() - 1);
      }
        else
        {
            char afterChangingCase = ' ';
          if(currChar >= 'a' && currChar <= 'z')
           afterChangingCase = (char)('A' + (currChar - 'a')); 
            else
            afterChangingCase = (char)('a' + (currChar - 'A'));
           currString.append(currChar);
          generateStrings(index+1,currString,s);
          currString.deleteCharAt(currString.length() - 1); 
              currString.append(afterChangingCase);
          generateStrings(index+1,currString,s);
          currString.deleteCharAt(currString.length() - 1); 
         
        }
    }
}