class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] dict = new int[128];
        for (int i = 0; i < order.length(); i++) {
            dict[order.charAt(i)] = i;
        }
        for(int i = 1; i < words.length; i++) {
            String cur = words[i];
            String pre = words[i - 1];
            int length = Math.min(cur.length(), pre.length());
            boolean equal = true;
            for (int j = 0; j < length; j++) {
                int curOrder = dict[cur.charAt(j)];
                int preOrder = dict[pre.charAt(j)];
                if(curOrder < preOrder) {
                    return false;
                } else if (curOrder > preOrder){
                    equal = false;
                    break;
                } else {
                    continue;
                }
            }           
            if(equal && cur.length() < pre.length()) return false;
        }
        return true;
    }
}
