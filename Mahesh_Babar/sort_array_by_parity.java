// https://leetcode.com/problems/sort-array-by-parity/

class sort_array_by_parity {
    public int[] sortArrayByParity(int[] nums) {
        int i = 0;
        int j = nums.length - 1;

        while (i < j) {
            if (nums[i] % 2 > nums[j] % 2) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            if (nums[i] % 2 == 0)
                i++;
            if (nums[j] % 2 != 0)
                j--;
        }
        return nums;
    }
}
