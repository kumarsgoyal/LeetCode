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
    int mini;
    int flag = 0;
    int ans = INT_MAX;
    void findSecondMin(TreeNode *root) {
        if(root == NULL) {
            return;
        }
       
        if((root->val < ans) && (root->val != mini)) {
            ans = root->val;
        }
        else if((root->val <= ans) && (root->val != mini) && (root->val == INT_MAX)) {
            ans = root->val;
            flag = 1;
        }
        findSecondMin(root->left);
        findSecondMin(root->right);
       
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        
        mini = root->val;
        findSecondMin(root);
        if(flag == 1) {
            return ans; //[2,2,2147483647]
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};
