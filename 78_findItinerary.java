class Solution {
    public List<String> findItinerary(List<List<String>> t) {
        Stack<String> kk=new Stack<>();
        Map<String,PriorityQueue<String>> nm=new HashMap<>();
        for(int i=0;i<t.size();i++)
        {
            String k=t.get(i).get(0);
            if(!nm.containsKey(k))
                nm.put(k, new PriorityQueue<String>());
            nm.get(k).offer(t.get(i).get(1));
        }
        List<String> p=new ArrayList<>();
        kk.push("JFK");
        while(!kk.isEmpty())
        {
            String f=kk.peek();
            if(nm.containsKey(f) && nm.get(f).size()>0)
                kk.push(nm.get(f).poll());
            else
                p.add(0,kk.pop());
        }
        return p;
    }
}
