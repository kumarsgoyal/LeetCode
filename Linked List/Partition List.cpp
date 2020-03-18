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
    ListNode* partition(ListNode* head, int x) {
        ListNode *before = new ListNode(0);
        ListNode *after = new ListNode(0);
        ListNode *bef = before;
        ListNode *aft = after;
        
        while(head) {
            if(head->val < x) {
                bef->next = head;
                bef = bef->next;
            }   
            else {
                aft->next = head;
                aft = aft->next;
            }
            
            head = head->next;
        }
        
        bef->next = after->next;
        aft->next = NULL;
        
        return before->next;
    }
};
