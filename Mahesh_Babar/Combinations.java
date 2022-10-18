// https://leetcode.com/problems/combinations/

class Combinations {
    List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        ArrayList<Integer> al = new ArrayList<Integer>();
        permute(nums, 0, k, al);
        return ans;
    }

    public void permute(int[] nums, int index, int k, ArrayList<Integer> curr) {
        if (curr.size() == k) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        for (int i = index; i < nums.length; i++) {
            curr.add(nums[i]);
            permute(nums, i + 1, k, curr);
            curr.remove(curr.size() - 1);
        }
    }
}
