/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* temp = NULL;
    struct ListNode* curr = res;
    if(l1 == NULL && l2 == NULL) {
        return NULL;
    }
    
    while(l1 && l2) {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        if(l1->val <= l2->val) {
            temp->val = l1->val;
            l1 = l1->next;
        }
        else {
            temp->val = l2->val;
            l2 = l2->next;
        }
        curr->next = temp;
        curr = curr->next;
    }
    while(l1) {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = l1->val;
        curr->next = temp;
        curr = curr->next;
        l1 = l1->next;
    }
    while(l2) {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = l2->val;
        curr->next = temp;
        curr = curr->next;
        l2 = l2->next;
    }
    return res->next;
    
}

