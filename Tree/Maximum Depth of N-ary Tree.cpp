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
    
    int maxi = 0;
    
    void findDepth(Node *root, int level) {
        if(root == NULL) {
            return;
        }
        
        if(level > maxi) {
            maxi++;
        }

        for(int i = 0; i < root->children.size(); i++) {
            findDepth(root->children.at(i), level+1);
        }
        
        return;
    }
    
    int maxDepth(Node* root) {
        if(root == NULL) {
            return 0;
        }
        findDepth(root, 1);
        return maxi;
        
    }
};
