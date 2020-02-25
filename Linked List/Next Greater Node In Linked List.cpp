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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> temp;
        // convert linklist to array or vector
        while(head) {
            temp.push_back(head->val);
            head = head->next;
        }
        
        
        stack<int> stk;
        vector<int> res(temp.size(), 0);
        for(int i = 0; i < temp.size(); i++) {
            while(!stk.empty() && temp[stk.top()] < temp[i]) {
                res[stk.top()] = temp[i];
                stk.pop();
            }
            stk.push(i);
        }
        
        while(!stk.empty()) {
            stk.pop();
        }
        
        temp.clear();
        return res;
        
    }
};
