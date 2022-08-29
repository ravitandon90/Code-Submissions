public class MaxConsecutiveOnes {
    public static int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int cnt = 0;

        for(int n: nums){
            cnt = (1+cnt)*n;
            max = Math.max(max,cnt);
        }
        return max;
    }
}
