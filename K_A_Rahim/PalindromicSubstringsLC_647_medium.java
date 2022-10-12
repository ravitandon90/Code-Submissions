class Solution {
   int count=0;
	//int result=0;

	int countSubstrings(String s) {

				if (s == null || s.length() == 0) 
					return 0;
    
		for (int i = 0; i < s.length(); i++) { 
			extendPalindrome(s, i, i); 
			extendPalindrome(s, i, i + 1); 
		}
    
		return count;
	}

	public void extendPalindrome(String s, int leftside, int rightside) {
		while (leftside >=0 && rightside < s.length() && s.charAt(leftside) == s.charAt(rightside)) {
			count++; 
			leftside--; 
			rightside++;
		}
	}
}