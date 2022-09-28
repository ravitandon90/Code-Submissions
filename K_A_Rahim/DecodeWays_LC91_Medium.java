 int dp[];
    public int numDecodings(String s) { // 5.36
        dp = new int[s.length()+1];
        Arrays.fill(dp,-1);
       return numofPossibleDecodingsWays(0,s);
    }
    private int numofPossibleDecodingsWays(int index,String s)
    {
       
        if(index >= s.length())
        {
            dp[index] = 1;
            return 1;
        }
         if(dp[index] != -1)
            return dp[index];
        char element = s.charAt(index);
        int count = 0;
        if(element >= '1' && element <='9')
        {
              count += numofPossibleDecodingsWays(index+1,s);
        }
        if(index == s.length()-1)
            return dp[index] = count;
        String pairElement = s.substring(index,index+2);
        int number = Integer.parseInt(pairElement);
      if(number >= 10 && number <= 26)
      {
          count += numofPossibleDecodingsWays(index+2,s);
      }
        return dp[index] = count;
    }
 