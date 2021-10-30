class Solution {
    private int answer;
    public int maxDepth(TreeNode root) {
        answer = 0;
        return depthPostOrder(root, 0);
    }
    
    private int max (int a, int b) {
        return a>b ? a: b;
    }
    
    private void depthPreOrder(TreeNode node, int depth) {
        if (node == null) {
            return;
        }
        
        if (node.left == null && node.right == null) {
            answer = max(answer, depth + 1);
        }
        depthPreOrder(node.left, depth+1);
        depthPreOrder(node.right, depth+1);
        
    }
    
    private int depthPostOrder(TreeNode node, int depth) {
        if (node == null) {
            return 0;
        }
        int leftDepth = depthPostOrder(node.left, depth+1);
        int rightDepth = depthPostOrder(node.right, depth+1);
        
        return max(leftDepth, rightDepth) + 1;
    }
}