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
    
    int length(ListNode *head) {
        int count = 0;
        while(head) {
            count++;
            head = head->next;
        }
        return count;
    }
    
    TreeNode* sortedListToBSTReccur(ListNode **head, int n) {
        if(n <= 0) {
            return NULL;
        }
        
        TreeNode *left = sortedListToBSTReccur(head, n/2);
        
        TreeNode *root = new TreeNode((*head)->val);
        root->left = left;
        
        *head = (*head)->next;
        
        root->right = sortedListToBSTReccur(head, n - n/2 -1);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int n = length(head);
        return sortedListToBSTReccur(&head, n);
    }
};
