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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) {
            return head;
        }
        
        ListNode* temp;
        // if val is in starting skip starting nodes
        while(1) {
            // whole linklist having value equal to given val
            if(head == NULL) {
                return head;
            }
            if(head->val == val) {
                temp = head;
                head = head->next;
                delete temp;
            }
            else {
                break;
            }
        }
        
        ListNode *curr = head;
        while(curr && curr->next) {
            if(curr->next->val == val) {
                temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else {
                curr = curr->next;    
            }
            
        }
        
        return head;
    }
};
