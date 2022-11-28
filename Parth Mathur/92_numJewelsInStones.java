class Solution {
    public int numJewelsInStones(String jewels, String stones)
    {
        HashMap<Character,Integer> hm = new HashMap<>();

        for(int i=0; i<stones.length(); i++)
        {
            int c = hm.containsKey(stones.charAt(i)) ? hm.get(stones.charAt(i)) : 0;
            hm.put(stones.charAt(i),c+1);
        }

        int count = 0;
        for(int i=0; i<jewels.length(); i++)
        {
            if(hm.containsKey(jewels.charAt(i)))
            {
                count += hm.get(jewels.charAt(i));
            }
        }
        
        return count;
    }
}
