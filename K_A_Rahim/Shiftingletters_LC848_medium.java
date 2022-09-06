class Solution { 
    public String shiftingLetters(String s, int[] shifts) {
        
        char[] stringArray = s.toCharArray();
        shifts[shifts.length - 1] = shifts[shifts.length - 1] % 26;
        for(int i=shifts.length-2;i>=0;i--)
        {
          int number = shifts[i] + shifts[i+1];
          number %= 26;
          shifts[i] = number;  
        }
        for(int i=0;i<stringArray.length;i++)
        {
        
           stringArray[i] = (char)((((int)stringArray[i] + shifts[i]) - (int)'a') % 26 + (int)'a');
        }
        return String.valueOf(stringArray);
    }
}