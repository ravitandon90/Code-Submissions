class Solution {
    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);
        return findWays(s.toCharArray(), dp, 0);
    }
    
    
    public int findWays(char[] arr, int[] dp, int idx){
        
        if(idx == arr.length) return 1;
        if(arr[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        int num = 0; int ans = 0;
        for(int k=idx; k<Math.min(idx+2, arr.length); ++k){
            num = num*10 + Character.getNumericValue(arr[k]);
            if(isValid(num))
                ans += findWays(arr, dp, k+1);
        }
        
        return dp[idx] = ans;
    }
    
    public boolean isValid(int num){
        return 0<num && num<27;
    }
}
