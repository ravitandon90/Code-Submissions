class Solution {
    HashMap<String, Integer> hm= new HashMap<>();
    int total= 0;
    
    public int countSubstrings(String s, String t) {
        
        int start= 0;
        int n= s.length();
        
        //  Generating substrings using 2 pointers (start & i)
        while(start < n){
            
            for(int i= start; i<n; i++){
                countPairs( s.substring(start, i+1), t, 0, i+1-start );
            }
            
            start++;
        }
        
        return total;
    }
    
    public void countPairs(String sub, String t, int count, int subLength){
        if(subLength == 0){
            return;
        }
        
        if(hm.containsKey(sub)){
            total+=  hm.get(sub);
            return;
        }
        
        int startIndex= 0;
        int endIndex= subLength-1;
        int validStrings= 0;
        
        //  Generating substrings using 2 pointers (startIndex & i)
        while(endIndex < t.length()){

            String temp= t.substring(startIndex, endIndex+1);
            count= 0;

            for(int j= 0; j< subLength; j++){
                 
                if( temp.charAt(j) != sub.charAt(j) ){
                    count++;
                }
                
                if(count > 1){
                    break;
                }
            }
            
            if(count == 1){
                validStrings++;
                total++;
            }
            
            endIndex++;
            startIndex++;
        }
        
        hm.put(sub, validStrings);
    }
}
