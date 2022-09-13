/* 

https://leetcode.com/problems/subsets/

*/

class Solution {
    public static List<List<Integer>> result;

    public List<List<Integer>> subsets(int[] nums) {
        result = new ArrayList();
        ArrayList<Integer> list = new ArrayList<>();
        generateSubsets(0, list, nums.length, nums);
        return result;
    }

    public static void generateSubsets(int i, ArrayList<Integer> list, int n, int[] nums) {
        if (i == n) {
            result.add(new ArrayList(list));
            return;
        }
        list.add(nums[i]);
        generateSubsets(i + 1, list, n, nums);
        list.remove(list.size() - 1);
        generateSubsets(i + 1, list, n, nums);
    }
}