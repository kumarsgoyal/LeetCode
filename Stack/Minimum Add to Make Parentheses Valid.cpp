class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> stk;
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(stk.empty() || s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(i);
            }
            else {
                if((s[stk.top()] == '{' && s[i] == '}') ||
                       (s[stk.top()] == '(' && s[i] == ')') ||
                       (s[stk.top()] == '[' && s[i] == ']')) {
                    stk.pop();
                }
                else {
                    stk.push(i);
                }
            }
        }
        
        while(!stk.empty()) {
            count++;
            stk.pop();
        }
        
        return count;
    }
};
