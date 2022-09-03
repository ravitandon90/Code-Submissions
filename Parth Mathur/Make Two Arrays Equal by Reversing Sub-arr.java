Map<Integer, Integer> h = new HashMap<>();
for(int a : target)
h.put(a, h.getOrDefault(a,0)+1);
for(int a : arr)
h.put(a, h.getOrDefault(a,0)-1);
for(Map.Entry<Integer,Integer> e : h.entrySet())
{
if(e.getValue()!=0)
return false;
}
return true;
