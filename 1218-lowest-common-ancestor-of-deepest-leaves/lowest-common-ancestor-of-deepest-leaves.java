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
    class Pair {
        int depth;
        TreeNode node;
        Pair(int _depth,TreeNode _node) {
            this.depth=_depth;
            this.node=_node;
        }
    }
    Pair LCA(TreeNode root){
        if(root==null) {
            return new Pair(0,null);
        }

        Pair leftAns=LCA(root.left);
        Pair rightAns=LCA(root.right);

        if(leftAns.depth==rightAns.depth) return new Pair(leftAns.depth+1,root);
        else if(leftAns.depth > rightAns.depth) return new Pair(leftAns.depth+1,leftAns.node);
        else return new Pair(rightAns.depth+1,rightAns.node);
    }
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return LCA(root).node;
    }
}