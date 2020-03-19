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
    
    int maxDepth(Node* root) {
        if(root == NULL) {
            return 0;
        }
        
        queue<Node*> q;
        int level = 0;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            Node *temp = NULL;
            while(size--) {
                temp = q.front();
                q.pop();
                for(int i = 0; i < temp->children.size(); i++) {
                    q.push(temp->children.at(i));
                }
            }
            level++;
        }
        
        return level;
        
    }
};
