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
    int size = 0;
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *next = NULL;
        
        while(head) {
            size++;
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> temp;
        // convert linklist to array or vector
        
        head = reverse(head);
        stack<int> stk;
        vector<int> res(size, 0);
        
        size = size-1; // 0 based index
        
        while(head) {
            
            while(!stk.empty() && (stk.top() <= head->val)) {
                stk.pop();
            }
            
            if(!stk.empty()) {
                res.at(size) = stk.top();
            }
            
            stk.push(head->val);
            size--;
            head = head->next;
        }
        
        return res;
        
    }
};
