class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        ans=new ArrayList<>();
        sets(nums,0,new ArrayList<Integer>());
        return ans;
    }
    List<List<Integer>> ans;
    void  sets(int[] nums,int idx,List<Integer> temp){
        if(idx==nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
        ans.add(new ArrayList<>(temp));
        for(int i=idx;i<nums.length;i++){
            temp.add(nums[i]);
            sets(nums,i+1,temp);
            temp.remove(temp.size()-1);
        }
    }
}
