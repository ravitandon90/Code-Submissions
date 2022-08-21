class Solution {
    //1. sort array by the number of elements in each box 
    //2. keep adding boxes till the capacity is available
    //Compelxity : O(nlogn) 
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b){
                return b[1]-a[1];
            }
        });
        int remainingCapacity = truckSize;
        int answer = 0;
        
        for(int[] a:boxTypes){
            
            if(remainingCapacity>=a[0]){
                answer+=a[1]*a[0];
                remainingCapacity-=a[0];
            }else{
                answer+=a[1]*remainingCapacity;
                return answer;
                
            }
            
        }
        return answer;
        
        
    }
}
