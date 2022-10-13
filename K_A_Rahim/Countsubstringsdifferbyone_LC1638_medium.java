   class Solution {
   public int countSubstrings(String s, String t) {
    int res = 0;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < t.length(); ++j) {
            int miss = 0;
            for (int pos = 0; i + pos < s.length() && j + pos < t.length(); ++pos) {
                if (s.charAt(i + pos) != t.charAt(j + pos))
                    {
                        miss++;
                        if(miss > 1)
                    break;
                    }
                res += miss;
            }
        }
    }
    return res;        
}
}