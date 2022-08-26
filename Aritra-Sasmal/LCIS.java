public class LCIS {
    public static int findLengthOfLCIS(int[] nums) {
        int maxLength = 0;
        int tmp = nums[0];
        int cnt = 0;
        for(int n:nums){
            cnt = (n > tmp)? cnt + 1:1;
            maxLength = Math.max(maxLength, cnt);
            tmp = n;
        }
        return maxLength;
    }
}
