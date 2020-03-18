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
    
    void split(ListNode *head, ListNode **first, ListNode **second) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        *first = head;
        *second = slow->next;
        slow->next = NULL;
    }
    
    ListNode* merge(ListNode *a, ListNode *b) {
        if(a == NULL) {
            return b;
        }
        
        if(b == NULL) {
            return a;
        }
        
        ListNode *result = NULL;
        
        if(a->val <= b->val) {
            result = a;
            result->next = merge(a->next, b);
        }
        else {
            result = b;
            result->next = merge(a, b->next);
        }
        
        return result;
    }
    
    void mergeSort(ListNode **head_ref) {
        ListNode *head = *head_ref;
        ListNode *a = NULL;
        ListNode *b = NULL;
        
        if(head == NULL || head->next == NULL) {
            return;
        }
        
        split(head, &a, &b);
        
        mergeSort(&a);
        mergeSort(&b);
        
        *head_ref = merge(a, b);
    }
    
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);
        return head;
    }
};
