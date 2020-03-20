class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        
        for(int i = 0; i < s.length(); i++) {
            if(stk.empty() || s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(i);
            }
            else {
                if(stk.empty()) {
                    return false;
                }
                else if((s[stk.top()] == '{' && s[i] == '}') ||
                       (s[stk.top()] == '(' && s[i] == ')') ||
                       (s[stk.top()] == '[' && s[i] == ']')) {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        if(stk.empty()) {
            return true;
        }
        
        else {
            return false;
        }
    }
};
