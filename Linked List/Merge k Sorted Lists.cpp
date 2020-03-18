/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class myCompare {
    public:
    int operator() (ListNode *a, ListNode *b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode *, vector<ListNode*>, myCompare> minHeap;
        
        
        for(int i = 0; i < lists.size(); i++) {
            if(lists.at(i) != NULL)
                minHeap.push(lists.at(i));
        }
        
        ListNode *dummy = new ListNode(0);
        ListNode *res = dummy;
        
        while(minHeap.empty() == false) {
            ListNode *temp = minHeap.top();
            minHeap.pop();
            
            if(temp->next) {
                minHeap.push(temp->next);
            }
            
            res->next = temp;
            res = res->next;
        }
        
        return dummy->next;
    }
};
