class Solution {
    //66. Plus One : https://leetcode.com/problems/plus-one/
    
    public int[] plusOne(int[] digits) {
        int remainder=0;
        for(int i=digits.length-1; i>=0; i--){
            
            if(i==digits.length-1 ){
                if(digits[i]==9){
                    
                
                digits[i]=0;
                remainder=1;
                } else {
                digits[i] = digits[i]+1;
                remainder=0;
            }
            
        } else {
                if(digits[i]==9 && remainder ==1){
                    
                
                digits[i] = 0;
                remainder=1;
                } else {
                    digits[i]=digits[i]+remainder;
                    remainder=0;
                }
            }
        
    }
    if(remainder==1){
        int[] temp = new int[digits.length+1];
        temp[0]=remainder;
        System.arraycopy(temp,1,digits,0,digits.length);
        return temp;
    }
    return digits;
    }
}
