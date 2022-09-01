import java.util.Arrays;

/**
 * https://leetcode.com/problems/move-zeroes/
 * <p>
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * <p>
 * Note that you must do this in-place without making a copy of the array.
 * <p>
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * <p>
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 *
 * Time Complexity: o(n)
 * Space Complexity: o(1)
 */

public class Date_20220830_MoveZeros {

    public static void main(String[] args) {

        int nums[] = {0,0,0,1, 5,0,3,12};
        moveZeroes(nums);
    }


    public static void moveZeroes(int[] nums) {

        int i = 0;
        int j = 0;
        while (j < nums.length) {
            if (nums[j] == 0) {
                j++;
            } else {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j++;
            }
        }
        System.out.println(Arrays.toString(nums));
    }
}
