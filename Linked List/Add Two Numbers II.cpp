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
    
    ListNode* reverse(ListNode *l1) {
        ListNode *prev = NULL;
        ListNode *next;
        
        while(l1) {
            next = l1->next;
            l1->next = prev;
            prev = l1;
            l1 = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *head = new ListNode(-1);
        ListNode* curr = head;
        int sum , carry = 0;
        while(l1 || l2) {
            sum =carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = (sum >= 10)? 1 : 0;  
            sum = sum % 10;  
            
            // Create a new node with sum as data  
            ListNode *temp = new ListNode(sum);
            curr->next = temp;
            curr = curr->next;
            
            if(l1) 
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        
        
        if (carry > 0)  
            curr->next = new ListNode(carry);  
        head = reverse(head->next);
        
        return head;
    }
};
