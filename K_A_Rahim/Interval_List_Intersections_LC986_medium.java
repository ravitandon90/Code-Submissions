class Solution { 
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
     int firstListPointer = 0;
     int secondListPointer = 0;
     ArrayList<ArrayList<Integer>> mergedIntersectionIntervals = new ArrayList<>();
     int startFirst = 0;
     int endFirst = 0;
     int startSecond = 0;
     int endSecond = 0;   
     while(firstListPointer < firstList.length && secondListPointer < secondList.length)
     {
         startFirst =  firstList[firstListPointer][0];
         endFirst =  firstList[firstListPointer][1];
         startSecond = secondList[secondListPointer][0];
         endSecond = secondList[secondListPointer][1];
         if (startFirst <= endSecond && endFirst >= startSecond)
         {
               ArrayList<Integer> pair= new ArrayList<>();
               pair.add(Math.max(startFirst,startSecond));
               pair.add(Math.min(endFirst,endSecond));
               mergedIntersectionIntervals.add(pair); 
         }
        if(endFirst <= endSecond)
        {
           firstListPointer++; 
        }
        else if(endFirst > endSecond)
        {
           secondListPointer++; 
        }
     }
       int[][] ans = new int[mergedIntersectionIntervals.size()][2];
     for(int i=0;i < mergedIntersectionIntervals.size();i++)
     {
       ans[i][0] = mergedIntersectionIntervals.get(i).get(0);  
       ans[i][1] = mergedIntersectionIntervals.get(i).get(1);
     }
    return ans;
    
    }
}