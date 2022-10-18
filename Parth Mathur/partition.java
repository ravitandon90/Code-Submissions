class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<List<String>>();
        palpar(0,s,new ArrayList<>(),ans);
        return ans;
    }
    
    
    void palpar(int index , String s , List<String> temp , List<List<String>> ans){
        if(index == s.length()){
            ans.add(new ArrayList<>(temp));
            return;
        }
        
        for(int i=index ; i<s.length() ; i++){
            if(isPalindrome(s,index,i)){
                temp.add(s.substring(index,i+1));
                palpar(i + 1,s,temp,ans);
                temp.remove(temp.size()-1);
            }
        }
    }
    boolean isPalindrome(String s , int start , int end){
        while(start < end){
            if(s.charAt(start++) != s.charAt(end--)){
                return false;
            }
        }
        return true;
    }
}
