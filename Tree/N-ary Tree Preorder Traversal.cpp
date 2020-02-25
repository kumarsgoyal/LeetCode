/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node *> stk;
        if(!root) {
            return res;
        }
        
        stk.push(root);
        while(!stk.empty()) {
            Node* temp = stk.top();
            stk.pop();
            
            res.push_back(temp->val);
            for(int i = temp->children.size()-1; i >= 0; i--) {
                stk.push(temp->children[i]);
            }
        }
        
        return res;
    }
};
