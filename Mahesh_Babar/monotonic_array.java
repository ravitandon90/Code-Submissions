// https://leetcode.com/problems/monotonic-array/

class monotonic_array {
    public boolean isMonotonic(int[] nums) {
        int[] arr = nums.clone();
        Arrays.sort(arr);
        if (arr[0] == nums[0]) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != arr[i])
                    return false;
            }
        } else {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != arr[nums.length - i - 1])
                    return false;
            }
        }
        return true;
    }
}
