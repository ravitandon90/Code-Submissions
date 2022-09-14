import java.util.List;
import java.util.ArrayList;
public class Main {
    static List<List<Integer>> results = new ArrayList<>();
    public static void main(String[] args) {
        // Insert Your Code Here. Here are the steps to get started: 
        // Step-I: Define the input format using the examples from the problem description. 
        // Step-II: Parse input from standard in. 
        // Step-III: Write your algorithm to generate the required output. 
        // Note: In case of any issues use #feedback channel on Discord. 
        System.out.println(getPowerSet(new int[]{1,2,3}));
    }
    private static List<List<Integer>> getPowerSet(int[] numbers)
    {
      generateSubsets(0,numbers,new ArrayList<>());
      return results;
    }
    private static void generateSubsets(int index,int[] numbers,ArrayList<Integer> currList)
    {
      if(index == numbers.length)
      {
          results.add(new ArrayList<Integer>(currList));
          return;
      }
       //generateSubsets(index+1,numbers,currList);
      currList.add(numbers[index]);
      generateSubsets(index+1,numbers,currList);
      currList.remove(currList.size() - 1);
      generateSubsets(index+1,numbers,currList);
      
    }
}