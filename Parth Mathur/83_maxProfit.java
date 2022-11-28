class Solution {
    public int maxProfit(int[] prices) {
        int pro = 0;
        int min = Integer.MAX_VALUE;
        
        for(int i=0; i<prices.length;i++)
        {
            min = Math.min(min,prices[i]);
            pro = Math.max(pro,prices[i]-min);
        }
        return pro;
    }
}
