class Solution {
    List<List<Integer>> sol=new ArrayList<>();
    public void helper(List<List<Integer>> sol,List<Integer> temp,int n,int k,int j){
        if(temp.size()==k){
            sol.add(new ArrayList<>(temp));
            return;
        }
        if(j>n)return;
        
        for(int i=j;i<=n;i++){
            temp.add(i);
            helper(sol,temp,n,k,i+1);
            temp.remove(temp.size()-1);
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        List<Integer> temp=new ArrayList();
        
        helper(sol,temp,n,k,1);
        return sol;
    }
}
