// https://leetcode.com/problems/third-maximum-number/

class third_maximum_number {
    public int thirdMax(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        int[] ans = new int[set.size()];
        int c = 0;
        for (int s : set) {
            ans[c] = s;
            c++;
        }
        Arrays.sort(ans);
        if (ans.length >= 3) {
            return ans[ans.length - 3];
        } else {
            return ans[ans.length - 1];
        }
    }
}
