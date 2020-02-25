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
    int Length(ListNode *head) {
        int count = 0;
        while(head) {
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode *func(ListNode *head, int len) {
        while(len--) {
            head = head->next;
        }
        return head;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = Length(headA);
        int len2 = Length(headB);
        
        
        // list having more length skip node nodes equal to difference in len
        if(len1 != len2) {
            (len1 > len2) ?(headA = func(headA, len1 - len2)) :
                (headB = func(headB, len2 - len1));
        }
        
        while(headA && headB) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};
