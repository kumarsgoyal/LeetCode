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
    
    void findBST(TreeNode *root, vector<TreeNode *> &vec) {
        if(root == NULL) {
            return;
        }
        findBST(root->left, vec);
        vec.push_back(root);
        findBST(root->right, vec);
    }
    
    TreeNode* constructTree(vector<TreeNode*> vec) {
        TreeNode *res;
        res = vec.at(0);
        TreeNode *temp = res;
        for(int i = 1; i < vec.size(); i++) {
            temp->left = NULL;
            temp->right = vec.at(i);
            temp = vec.at(i);
        }
        temp->left = NULL;
        temp->right = NULL;
        return res;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        
        vector<TreeNode *> vec;
        findBST(root, vec); // inorder of tree
        return constructTree(vec);
    }
};
