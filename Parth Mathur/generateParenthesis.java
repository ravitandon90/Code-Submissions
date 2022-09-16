class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result=new ArrayList();
        int leftCount=n;
        int rightCount=0;
        String emptyString="";
        helper(leftCount, rightCount, emptyString, result);
        return result;
    }
    private void helper(int leftCount, int rightCount, String str, List<String> result){
        if(leftCount==0 && rightCount==0){
            result.add(str);
            return;
        }
        if(leftCount>0){
            helper(leftCount-1,rightCount+1,str+"(",result);
        }
        if(rightCount>0){
            helper(leftCount,rightCount-1,str+")",result);
        }
    }
}
