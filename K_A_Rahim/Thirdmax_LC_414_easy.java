class Solution {
    public int thirdMax(int[] nums) { 
        if(nums.length == 0)
            return 0;
        long max = (long)Integer.MIN_VALUE-1;
        long secondMax = (long)Integer.MIN_VALUE-1;
        long thirdMax = (long)Integer.MIN_VALUE-1;
        for(int i=0;i<nums.length;i++)
        {
           long currentElement = (long)nums[i];
            if(currentElement > max)
            {
                thirdMax = secondMax;
                secondMax = max;
                max = currentElement;
            }
            else if(currentElement > secondMax && currentElement != max)
            {
               thirdMax = secondMax;
                secondMax = currentElement; 
            }
            else if(currentElement > thirdMax && currentElement != secondMax && currentElement != max)
            {
                thirdMax = currentElement;
            }
        }
        if(thirdMax == (long)Integer.MIN_VALUE - 1)
        {
          return (int) max;
        }
        return (int)thirdMax;
    }
}