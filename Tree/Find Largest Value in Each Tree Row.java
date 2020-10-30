class Solution {
    public List<Integer> largestValues(TreeNode root) {
        // return list
        List<Integer> res = new LinkedList<>();
        if(root == null) 
            return res;
        
        // queue for level order traversal
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);
        
        while(que.isEmpty() == false) {
            int size = que.size();
            int max = Integer.MIN_VALUE;
            
            // to maintain level
            while(size > 0) {
                size--;
                root = que.remove();
                if(root.val > max) 
                    max = root.val;
                
                if(root.left != null) 
                    que.add(root.left);
                if(root.right != null) 
                    que.add(root.right);
            }
            
            // add max value of current level in res
            res.add(max);
        }
        
        return res;
    }
}
