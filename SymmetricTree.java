class SymmetricTree {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root.left, root.right);
    }
    
    private boolean isMirror(TreeNode left, TreeNode right) {
        if (left == null && right == null) {
            return true;
        }
        
        if (left != null && right != null && left.val == right.val) {
            return isMirror(left.left, right.right) && isMirror(left.right, right.left);
        }
        return false;
    }
}