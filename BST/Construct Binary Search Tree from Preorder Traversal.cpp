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
    TreeNode* ConstructBst(vector<int> pre, int size, int *index, int key, int min, int max) {
        if(*index >= size) {
            return NULL;
        }
            
        TreeNode *root = NULL;
        if(key > min && key < max) {
            root = new TreeNode(key);
            *index = *index + 1;
            
            if(*index < size) {
                root->left = ConstructBst(pre, size,index, pre.at(*index), min, key);   
            }
            if(*index < size) {
                root->right = ConstructBst(pre, size,index, pre.at(*index), key, max);
            }
        }
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return ConstructBst(preorder, preorder.size(), &index, preorder.at(0), INT_MIN, INT_MAX);
    }
};
