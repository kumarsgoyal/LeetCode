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
    bool isPalindrome(ListNode* head) {
        if(!head || (head && !head->next)) {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *terminate = NULL;
        int res = 1;
        
        while(fast != NULL && fast->next != NULL) {
            terminate = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != NULL) {
            slow = slow->next;
        }
        
        terminate->next = NULL;
        
        // head of first and second
        ListNode *head1 = head;
        ListNode *head2 = slow;
        
        // reverse LinkList
        ListNode *next = NULL;
        ListNode *prev = NULL;
        
        while(head2) {
            next = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = next;
        }
        
        // head to last of second linkedlist
        head2 = prev;
        
        ListNode *curr1 = head1;
        ListNode *curr2 = head2;
        while(curr1 && curr2) {
            if(curr1->val != curr2->val) {
                res = 0;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        prev = NULL;
        while(head2) {
            next = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = next;
        }
        head2 = prev;
        
        
        while(head1->next) {
            head1 = head1->next;
        } 
        head1->next = head2;
        
        return (res == 1)?true: false;
        
    }
};
