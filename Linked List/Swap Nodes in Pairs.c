/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *temp = NULL;
    struct ListNode *newhead = NULL;
    if(head && head->next) {
        temp = head->next->next;
        newhead = head->next;
        
        head->next->next = head;
        
        
        head->next = swapPairs(temp);
        return newhead;
    }
    else {
        return head;
    }
}

