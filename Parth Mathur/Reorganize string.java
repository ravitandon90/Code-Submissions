class Solution {
    // help class to add into priority queue
    // [character,count] array could also be used
    class help{
        char c;
        int n;
        help(char c,int n){
            this.c=c;
            this.n=n;
        }
    }
    public String reorganizeString(String s) {
        
        // hashmap to count character
        HashMap<Character,Integer> hp = new HashMap<>();
        // using max heap to get max count character always
        PriorityQueue<help> pq = new PriorityQueue<help>((a,b)->b.n-a.n);
        
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            hp.put(c,hp.getOrDefault(c,0)+1);
        }
        for(char c: hp.keySet()){
            int num = hp.get(c);
            pq.add(new help(c,num));
        }
        help block = pq.remove();
        block.n=block.n-1;
        
        String ans = "";
        
        ans+=block.c;
        while(pq.size()!=0){
            help temp = pq.remove();
            ans+=temp.c;
            temp.n=temp.n-1;
            if(block.n!=0) pq.add(block);
            block=temp;
        }
        
        if(block.n>0) return "";
        return ans;
    }
}
