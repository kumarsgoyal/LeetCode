/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 */
class Solution {
public:
    TreeNode *curr;
    
    
    void constructTree(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        
        constructTree(root->left);
        
        root->left = NULL;
        curr->right = root;
        curr = root;
        constructTree(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        TreeNode *result = new TreeNode(0);
        curr = result;
        
        constructTree(root);
        
        return result->right;
    }
};
