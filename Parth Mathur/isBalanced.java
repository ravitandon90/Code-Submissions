
class Solution {
    public int height(TreeNode root)
    {
        if(root==null)
        {
            return 0;
        }
        
        int left = height(root.left);
        int right = height(root.right);
        
        int ans = Math.max(left,right)+1;
        return ans;
        
    }
    public boolean isBalanced(TreeNode root) {
        if(root == null)
            return true;
        
        boolean left = isBalanced(root.left);
        boolean right = isBalanced(root.right);
        
        boolean ans = Math.abs(height(root.left) - height(root.right)) <= 1;
         
        if(left && right && ans)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
}
