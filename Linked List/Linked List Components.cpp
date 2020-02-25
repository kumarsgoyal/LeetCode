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
    int numComponents(ListNode* head, vector<int>& G) {
        map<int, int> mp;
        int max = 0;
        int temp = 0;
        for(int i = 0; i < G.size(); i++) {
            mp.insert({G[i], 0});
        }
        
        
        while(head) {
            if(head->val == mp.find(head->val)->first && mp.find(head->val) != mp.end()) {
                temp++;
            }
            else {
                if(temp > 0) {
                    max++;
                }
                temp = 0;
            }
            
            // head is at last node
            if(head->next == NULL) {
                max += (mp.find(head->val) != mp.end() && mp.find(head->val)->first == head->val) ? 1 : 0; 
                
            }
            head = head->next;
        }
        
        mp.clear();
        return max;
    }
};
