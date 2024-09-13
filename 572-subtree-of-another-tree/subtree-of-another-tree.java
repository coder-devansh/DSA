/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isIdentical(TreeNode root,TreeNode subRoot)
    {
        if(root==null && subRoot==null)
        {
            return true;
        }
        else if(root==null || subRoot==null)
        {
            return false;
        }
        
        if(root.val!=subRoot.val)
        {
            return false;
        }
        
       
        
        return isIdentical(root.left,subRoot.left) && isIdentical(root.right,subRoot.right);
        
    }
    public boolean fun(TreeNode root,TreeNode subRoot)
    {
        if(root==null)
        {
            return false;
        }
        if(root.val==subRoot.val)
        {
            if(isIdentical(root,subRoot))
            {
                return true;
            }
        }
        return fun(root.left,subRoot) || fun(root.right,subRoot);
    }
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        return fun(root,subRoot);
        
    }
}