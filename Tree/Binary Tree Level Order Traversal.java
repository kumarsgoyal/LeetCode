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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        
        if(root == null)
            return res;
    
        q.add(root);
        while(q.isEmpty() == false) {
            Queue<TreeNode> t = new LinkedList<>();
            List<Integer> temp = new ArrayList<>();
            
            while(q.isEmpty() == false) {
                TreeNode front = q.poll();
                temp.add(front.val);
                if(front.left != null)
                    t.add(front.left);
                if(front.right != null)
                    t.add(front.right);
            }
        
            res.add(temp);
            q = t;
        }
    
        return res;
    }
}
