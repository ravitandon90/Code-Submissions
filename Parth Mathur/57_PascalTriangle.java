class Solution {
    public List<List<Integer>> generate(int numRows) {
        
        if(numRows == 0)
        {
            return new ArrayList<>();
        }
        
        List<List<Integer>> ans = new ArrayList();
        
        for(int i=1; i<=numRows; i++)
        {
            List<Integer> smallAns = new ArrayList();
            for(int j=0; j<i ; j++)
            {
                if(j==0 || j==i-1)
                {
                    smallAns.add(1);
                }
                else
                {
                    smallAns.add(ans.get(i-2).get(j) +  ans.get(i-2).get(j-1));
                }
                
            }
            ans.add(smallAns);
        }
        
        return ans;
        
    }
}
