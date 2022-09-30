class Solution {
    // 1) - could not get "DROP" part: how many at most drop(break + non break)
    // needed is being asked for
    // 2) - 2 cases: if drop breaks I have to go down else go up
    // 3) - recursive relation: IF I know answer of till nth floor, then
    //          2 cases : case1) EGG DROPPED gets broken find(n-1,noOfegg-1) i.e go down and egg reduced
     //                   case2) NOT BROKEN              find(totalFloor - n,noOfegg) i.e go up and treat Current Floor as Floor 0, i.e treat remaining floor built on this "ground floor"
     /// - BEST OF THE WORST concept
     // Starting from bottom floor is always best strategy, Otherwise we will end up  with all eggs being broken
     
     public int eggDrop(int eggs,int floors)
     {
            // If there are no eggs, then there can't be any tries
    if (eggs <= 0)
      return 0;
    
    // If there are no floors, then no trials needed. OR if there is 
    // one floor, one trial needed.
    if (floors == 1 || floors == 0)
      return floors;

    // We need k trials for one egg and k floors 
    if (eggs == 1)
      return floors;

    int min = Integer.MAX_VALUE;
    int  res;
    for (int x = 1; x <= floors; x++) {
      res = Math.max(eggDrop(eggs - 1, x - 1), eggDrop(eggs, floors - x));
    if (res < min)
        min = res;
    }

    return min + 1;
     }


     public int twoEggDrop(int n) {
  
        int eggs = 2;
        //return eggDrop(eggs,n); // recursion 
        return drop(n, eggs, new int[n + 1][eggs + 1]);
    }

    int drop(int floors, int eggs, int[][] dp) {
        if (eggs == 1 || floors <= 1)
            return floors;
        if (dp[floors][eggs] > 0)
            return dp[floors][eggs];
        int min = Integer.MAX_VALUE;
        for (int f = 1; f <= floors; f++)
            min = Math.min(min, 1 + Math.max(drop(f - 1, eggs - 1, dp), drop(floors - f, eggs, dp)));
        dp[floors][eggs] = min;
        return min;
    }
}