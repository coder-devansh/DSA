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
class BSTIterator {
    private Stack<TreeNode>stack=new Stack<TreeNode>();

    public BSTIterator(TreeNode root) {
        pushAll(root);
        
    }
    
    public int next() {
        TreeNode tmp=stack.pop();
        pushAll(tmp.right);
        return tmp.val;
        
    }
    
    public boolean hasNext() {
        return !stack.isEmpty();
        
    }
    void pushAll(TreeNode root){
        for(;root!=null;stack.push(root),root=root.left);
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */