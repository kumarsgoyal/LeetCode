class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        
        int i = 0; // pushed index
        int j = 0; // poped index
        int flag = 1;
        while(i < pushed.size() || j < popped.size() && flag) {
            if(i < pushed.size()) {
                if(stk.empty() || stk.top() != popped[j]) {
                    stk.push(pushed[i]);
                    i++;
                }
                else {
                    stk.pop();
                    j++;
                }
            }
            else {
                if(stk.top() == popped[j]) {
                    stk.pop();
                    j++;
                }
                else {
                    flag = 0;
                }
            }
        }
        
        
        // or we can use stack is empty or not
        // if it empty then return true
        // else false;
        if(flag == 0) {
            return false;
        }
        
        return true;
    }
};
