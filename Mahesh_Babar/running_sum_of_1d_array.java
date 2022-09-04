// https://leetcode.com/problems/running-sum-of-1d-array/

import java.util.Arrays;

public class running_sum_of_1d_array {
    public static void main(String[] args) {

        System.out.println(Arrays.toString(runningSum(new int[] { 1, 2, 3, 4, 5 })));
    }

    private static int[] runningSum(int[] nums) {
        int res[] = new int[nums.length];

        int runningSum = 0;
        for (int i = 0; i < nums.length; i++) {
            runningSum += nums[i];
            res[i] = runningSum;
        }
        return res;
    }
}
