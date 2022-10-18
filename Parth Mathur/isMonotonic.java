import java.util.*;
public class Main {
    public static void main(String[] args) {
        // Insert Your Code Here. Here are the steps to get started: 
        // Step-I: Define the input format using the examples from the problem description. 
        // Step-II: Parse input from standard in. 
        // Step-III: Write your algorithm to generate the required output. 
        // Note: In case of any issues use #feedback channel on Discord. 
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int nums[] = new int[n];
        for(int i=0; i<n; i++)
        {
            nums[i] = sc.nextInt();
        }
        System.out.println(isMonotonic(nums));
    }
     public static boolean isMonotonic(int[] nums) {
        if(nums[0]>nums[nums.length-1]){
            for(int i=1;i<nums.length;i++){
                if(nums[i]>nums[i-1]){
                    return false;
                }
            }
        }else{
            for(int i=1;i<nums.length;i++){
                if(nums[i]<nums[i-1]){
                    return false;
                }
            }
        }
        return true;
    }
}
