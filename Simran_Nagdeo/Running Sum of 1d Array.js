var runningSum = function(nums) {
   
    let arr1=[];
   for(let i=0;i<nums.length;i++){
       let sum=0;
       for(let j=0;j<=i;j++){
           sum=sum+nums[j];
       }
       arr1.push(sum);
   }
   return arr1;

};
