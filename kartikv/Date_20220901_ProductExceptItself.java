import java.util.Arrays;

/**
 * https://leetcode.com/problems/plus-one/
 * <p>
 * You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
 * The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 * <p>
 * Increment the large integer by one and return the resulting array of digits.
 */

public class Date_20220831_PlusOne {

    public static void main(String[] args) {

        int nums[] = {1, 2, 3};
        System.out.println(Arrays.toString(nums)  + "|" + Arrays.toString(plusOne(nums)));
        int nums1[] = {1, 2, 9};
        System.out.println(Arrays.toString(nums1)  + "|" + Arrays.toString(plusOne(nums1)));
        int nums2[] = {1, 9, 0};
        System.out.println(Arrays.toString(nums2)  + "|" + Arrays.toString(plusOne(nums2)));
        int nums3[] = {8, 9, 9};
        System.out.println(Arrays.toString(nums3) + "|" + Arrays.toString(plusOne(nums3)));
    }


    public static int[] plusOne(int[] nums) {
        int i = nums.length - 1;
        while (i >= 0 && nums[i] == 9) {
            i--;
        }

        //all digits are 9
        if (i == -1) {
            int digits[] = new int[nums.length + 1];
            digits[0] = 1;
            return digits;
        }

        int result[] = new int[nums.length];
        result[i] = nums[i] + 1;
        for (int k = 0; k < i; k++) {
            result[k] = nums[k];
        }
        return result;
    }
}
