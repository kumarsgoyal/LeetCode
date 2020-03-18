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
    
    int length(ListNode *root) {
        int count = 0;
        while(root) {
            count++;
            root = root->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = length(root);
        int main = len/k, extra = len%k;
        vector<ListNode*> res;
        
        if(main) {
            while(root) {
                int currlen = main;
                res.push_back(root);
                ListNode* temp = root;
                while(temp && currlen > 1){
                    temp = temp->next;
                    currlen--;
                }

                // [0,1,2,3,4]
                // k = 3
                // OUTPUT: [[0,1],[2,3],[4]]
                if(extra){
                    temp = temp->next;
                    extra--;
                }

                root = temp->next;
                temp->next = NULL;
            }
        }
        else {
            // root = [1, 2, 3], k = 5
            // Output: [[1],[2],[3],[],[]]
            while(root && k) {
                ListNode *temp = root->next;
                root->next = NULL;
                res.push_back(root);
                root = temp;
                k--;
            }
            while(k) {
              res.push_back(NULL);
                k--;
            }
            
        }
        
        return res;
    }
};
