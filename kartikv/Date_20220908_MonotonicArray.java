/**
 * /* Leetcode : https://leetcode.com/problems/monotonic-array/
 * <p>
 * An array is monotonic if it is either monotone increasing or monotone decreasing.
 * An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
 * Given an integer array nums, return true if the given array is monotonic, or false otherwise.
 */

public class Date_20220908_MonotonicArray {

    public static void main(String[] args) {
        int[] nums1 = {6,5,4,4};
        System.out.println(isMonotonic(nums1));
    }

    private static boolean  isMonotonic(int nums[]) {
        boolean incr = true;
        boolean decr = true;
        for (int i = 0, j= nums.length-1; i < nums.length-1; i++,j--){
                incr = incr && nums[i]<= nums[i+1];
                decr = decr && nums[j]<= nums[j-1];
        }
        return incr || decr;
    }


}