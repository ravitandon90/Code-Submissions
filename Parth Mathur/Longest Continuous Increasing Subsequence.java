class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int current_right = 0, best_right = 0;
        for(int i = 0; i < nums.length; i++) {
            if(i == 0 || nums[i - 1] >= nums[i]) {
                current_right = 1;
            } else {
                current_right++;
            }
            best_right = Math.max(best_right, current_right);
        }
        return best_right;
    }
}
