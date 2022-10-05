class Solution {
    public boolean isSubsequence(String s, String t) { //8.22
        if(s.length() > t.length())
            return false;
       int sPointer = 0;
        int tPointer = 0;
        while(sPointer < s.length() && tPointer < t.length())
        {
            if(s.charAt(sPointer) != t.charAt(tPointer))
            {
                tPointer++;
            } 
            else
            {
              sPointer++;
                tPointer++;  
            }
        }
        if(tPointer == t.length() && sPointer != s.length())
            return false;
        else
            return true;
    }
}