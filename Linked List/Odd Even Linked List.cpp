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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode *odd = new ListNode(0);
        ListNode *even = new ListNode(0);
        ListNode *currOdd = odd;
        ListNode *currEven = even;
        int i = 1;
        
        while(head) {
            if(i%2) {
                currOdd->next = head;
                currOdd = currOdd->next;
            }
            else {
                currEven->next = head;
                currEven = currEven->next;
            }
            head = head->next;
            i++;
        }
        
        currOdd->next = even->next;
        currEven->next = NULL;
        
        return odd->next;
        
    }
};
