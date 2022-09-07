class Pair implements Comparable<Pair>
{
    int frequency;
    int value;
    public Pair(int frequency,int value)
    {
       this.frequency = frequency;
       this.value = value;
    }
    public int compareTo(Pair p)
    {
     if(p.frequency == this.frequency)
      return (p.value - this.value);
      else
      return (this.frequency - p.frequency);
    }
}
class Solution { 
    public int[] frequencySort(int[] nums) {
      int[] freqArr = new int[201];
      for(int i=0;i<nums.length;i++)
      {
        freqArr[nums[i]+100]++;
      }
      ArrayList<Pair> pairList = new ArrayList<>();
      for(int i=0;i<201;i++)
      {
       pairList.add(new Pair(freqArr[i],i-100));
      }
      Collections.sort(pairList);
      int destination = 0;
      int ans[] = new int[nums.length];
      for(int i=0;i<201;i++)
      {
       int freq = pairList.get(i).frequency;
       while(freq != 0)
       {
       ans[destination++] = pairList.get(i).value;
       freq--;
       }
      }
      return ans;
    }
}