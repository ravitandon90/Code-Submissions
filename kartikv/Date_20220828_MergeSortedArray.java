 import java.util.Arrays;

/**
 * Problem: https://leetcode.com/problems/merge-sorted-array/
 * Assignment Date: 2022-08-28
 * Type: Array
 * Difficulty: Easy
 */

  public class Date_20220828_MergeSortedArray {

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int m = 3;
        int nums2[] = {2, 5, 6};
        int n = 3;
        merge(nums1, m, nums2, n);
    }
 
 public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int m = 3;
        int nums2[] = {2, 5, 6};
        int n = 3;
        merge(nums1, m, nums2, n);
    }


    //Trick is to move backwards from larger to smaller numbers
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int counter = m + n - 1;
        int r1 = m-1;
        int r2 = n-1;
        while (r1 >= 0 && r2 >= 0) {
            nums1[counter--] = nums1[r1] > nums2[r2] ? nums1[r1--] : nums2[r2--];
        }

        while(r2>=0){
            nums1[counter--] = nums2[r2--];
        }
        System.out.println(Arrays.toString(nums1));
    }
}