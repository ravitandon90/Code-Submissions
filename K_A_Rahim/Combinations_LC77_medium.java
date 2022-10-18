class Solution {
    List<List<Integer>> results = new ArrayList<>();
    List<Integer> currentList = new ArrayList<>();
    public List<List<Integer>> combine(int n, int k) {
        generateCombinations(1,n,k);
        return results;  
    }
    private void generateCombinations(int startIndex,int n,int size)
    {
        if(currentList.size() == size)
        {
            results.add(new ArrayList<>(currentList));
            return;
        }
       for(int i=startIndex;i<=n;i++)
       {
           currentList.add(i);
           generateCombinations(i+1,n,size);  
           currentList.remove(currentList.size() - 1);
       }
    }
}