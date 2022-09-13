 class Solution {
    List<List<Integer>> results = new ArrayList<>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        generatePermutations(new ArrayList<Integer>(),nums, new int[nums.length]);
        return results;
       }


    private void generatePermutations(List<Integer> currList, int nums[],int[] visited)
    {
        if(currList.size() == nums.length)
        {
           results.add(new ArrayList<Integer>(currList));
            return;
        }
        for(int i=0;i<nums.length;i++)
        {
             if(i> 0 && nums[i] == nums[i-1] && visited[i-1] == 1)
                   continue;
            if(visited[i] != 1)
            {
              currList.add(nums[i]);
              visited[i] = 1;
              generatePermutations(currList,nums,visited);
              visited[i] = 0;
              currList.remove(currList.size() - 1);
            }
        }
        
    }
  }