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
    ListNode* swapPairs(ListNode* head) {
        if(head && head->next) {
            ListNode *newhead = head->next;
            
            head->next = swapPairs(newhead->next);
            newhead->next = head;
            return newhead;
        }
        else {
            return head;
        }
    }
};
