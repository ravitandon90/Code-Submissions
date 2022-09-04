import java.util.Arrays;

/**
 * 1480. Running Sum of 1d Array
 * https://leetcode.com/problems/running-sum-of-1d-array/
 * <p>
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i])
 * Return the running sum of nums.
 */
public class Date_20220903_RunningSumArray {

    public static void main(String[] args) {

        System.out.println(Arrays.toString(runningSum(new int[]{1, 2, 3, 4, 5})));
    }

    private static int[] runningSum(int[] nums) {
        int rs[] = new int[nums.length];

        int runningSum = 0;
        for (int i = 0; i < nums.length; i++) {
            runningSum += nums[i];
            rs[i] = runningSum;
        }
        return rs;
    }
}
