/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    bool isExist(TreeNode *root, ListNode *head) {
        if(head == NULL) {
            return true;
        }
        if(root == NULL) {
            return false;
        }
        
        if(head->val != root->val) {
            return false;
        }
        
        return isExist(root->left, head->next) || isExist(root->right, head->next);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) {
            return false;
        }
        
        if(root->val == head->val) {
            bool flag = isExist(root, head);
            if(flag == true) {
                return true;
            }
        }
        
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
