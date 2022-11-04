class Solution {
    public int maximumScore(int a, int b, int c) {
     int[] nums=new int[]{a,b,c};
     Arrays.sort(nums);
     if(nums[2]>nums[1]+nums[0]){
         int sum=nums[0]+nums[1];
         return sum;
     }
        else   {
               int sum=a+b+c;
              return sum/2;
        }
    }
}
