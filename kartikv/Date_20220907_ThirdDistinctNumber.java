/**
 * Given an integer array nums, return the third distinct maximum number in this array.
 * If the third maximum does not exist, return the maximum number.
 */

public class Date_20220907_ThirdDistinctNumber {

    public static void main(String[] args) {
        System.out.println(thirdDistinct(new int[] {1,2,2,5,3,5}));
    }


    private static int thirdDistinct(int[] nums){
        int firstNum = Integer.MIN_VALUE;
        int secondNum = Integer.MIN_VALUE;
        int thirdNum = Integer.MIN_VALUE;
        boolean minExists = false;

        for(int i=0;i< nums.length;i++){
            if(nums[i] == Integer.MIN_VALUE) {
                minExists = true;
            }

            if(nums[i]>firstNum){
                thirdNum = secondNum;
                secondNum = firstNum;
                firstNum = nums[i];
            }
            else if(nums[i]> secondNum && nums[i]< firstNum){
                thirdNum = secondNum;
                secondNum = nums[i];
            }
            else if(nums[i]> thirdNum && nums[i] < secondNum){
                thirdNum = nums[i];
            }
        }

        if(secondNum == Integer.MIN_VALUE || !minExists && thirdNum== Integer.MIN_VALUE){
            return firstNum;
        }
        return thirdNum;
    }
}
