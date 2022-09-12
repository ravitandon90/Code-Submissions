class Solution {
public int thirdMax(int[] nums) {
Arrays.sort(nums);
int max1=-2147483648;
int max2=-2147483648;
int max3=-2147483648;
for(int i=0;i<nums.length;i++)
{
if(max1<nums[i])
{
max3=max2;
max2=max1;
max1=nums[i];
}
}
if(nums.length>=3 && max3==(-2147483648)&&(nums[0]|nums[1])>0)
{
max3=max1;
}
else if(nums.length==1)
{
max3=nums[0];
}
else if(nums.length==2)
{
max3=max1;
}
else if((max2|max3)==-2147483648)
max3=max1;
return max3;
}}
