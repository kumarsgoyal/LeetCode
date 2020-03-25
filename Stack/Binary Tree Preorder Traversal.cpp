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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *curr = root;
        vector<int> vec;
        while(curr != NULL || stk.empty() == false) {
            while(curr) {
                vec.push_back(curr->val);
                stk.push(curr);
                curr = curr->left;
            }
            
            curr = stk.top();
            stk.pop();
            
            curr = curr->right;
        }
        
        return vec;
    }
};
