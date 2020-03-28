/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        pushToLeft(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *temp = stk.top();
        stk.pop();
        pushToLeft(temp->right);
        
        return temp->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(stk.empty()) {
            return false;
        }
        return true;
    }
    
    void pushToLeft(TreeNode *root) {
        while(root) {
            stk.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
