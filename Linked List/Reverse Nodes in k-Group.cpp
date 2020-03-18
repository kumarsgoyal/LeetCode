/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    
    
    ListNode* getreverse(ListNode *head, int len, int k) {
        if((len < k) || (head == NULL)) {
            return head;
        }
        
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        int count = k;
        
        while(count--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
            
        
        head->next = getreverse(curr, len-k, k);
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        return getreverse(head,len, k);
    }
};
