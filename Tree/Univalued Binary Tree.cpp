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
    
    bool isUnivalued(TreeNode *root, int val) {
        if(root == NULL) {
            return true;
        }
        
        return (root->val == val) && isUnivalued(root->left, val) && isUnivalued(root->right, val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        int val = root->val;
        return isUnivalued(root, val);
    }
};
