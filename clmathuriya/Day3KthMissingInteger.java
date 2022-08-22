//1539. Kth Missing Positive Number https://leetcode.com/problems/kth-missing-positive-number/
class Solution {
    public int findKthPositive(int[] arr, int k) {
        //1. store array elements in a hashset to quickly check if a given integer is present in the array or not.
        //2. iterate throw all the positive integers till the missing intger count is less than or equal to k
        //3. print the kth missing positive integer 
        Set<Integer> set = new HashSet<>();
        for(int i:arr){
            set.add(i);
        }
        int missingIntegerCount=0;
        int i=1;
        while(missingIntegerCount<k){
            if(set.add(i++)){
                missingIntegerCount++;
            }
        }
        return i-1;
        
    }
}
