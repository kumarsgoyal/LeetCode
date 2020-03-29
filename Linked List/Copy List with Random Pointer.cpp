/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr = head;
        
        while(curr) {
            Node *temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            
            curr = curr->next->next;
        }
        
        curr = head;
        while(curr) {
            curr->next->random = (curr->random) ? curr->random->next : curr->random;
            curr = curr->next->next;
        }
        
        curr = head;
        
        Node *dummyorginal = new Node(-1);
        Node *dummycopy = new Node(-1);
        
        Node *orginal = dummyorginal;
        Node *copy = dummycopy;
        int c = 1;
        while(curr) {
            if(c%2) {
                orginal->next = curr;
                orginal = orginal->next;
            }
            else {
                copy->next = curr;
                copy = copy->next;
            }
            curr = curr->next;
            c++;
        }
        
        orginal->next = NULL;
        
        return dummycopy->next;
    }
};
