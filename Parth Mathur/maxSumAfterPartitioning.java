class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int N = arr.length;
        int []dp =new int[N+1];
        for(int i=0;i<N+1;i++){
            dp[i] = 0;
        }
        for(int ind = N-1;ind>=0;ind--){
            int maxi = -(int)1e7;
            int len=0;
            int maxSum = -(int)1e7;
            for(int j=ind;j<Math.min(N, ind+k);j++){
                len++;
                maxi = Math.max(arr[j],maxi);
                int sum = (len*maxi) + dp[j+1];
                maxSum = Math.max(sum,maxSum);
            }
            dp[ind] = maxSum;
        }
        return dp[0];
    }
}
java
partition dp
Comments: 0
BestMost VotesNewest to OldestOldest to Newest
Type comment here... (Markdown is supported)

Preview

Post
