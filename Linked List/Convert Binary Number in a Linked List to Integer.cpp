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
    int getDecimalValue(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        int flag = 0;
        double sum = 0;
        while(prev) {
            sum += (prev->val * pow(2, flag));
            ++flag;
            prev = prev->next;
        }
        return (int)sum;
        
    }
};
