/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        traversal(root, L, R);
        return sum;
    }
    
    void traversal(TreeNode *root, int L, int R) {
            if(L <= root->val && root->val <=R) {
                sum += root->val;
            }
            
            // when we are required to move to left child of tree
            // if root->val > L 
            if(root->val > L && root->left) {
                traversal(root->left, L, R);
            }
            
            // when we are required to move to right child of tree
            // if root->val < R 
            if(root->val < R && root->right) {
                traversal(root->right, L, R);
            }
    }
};
