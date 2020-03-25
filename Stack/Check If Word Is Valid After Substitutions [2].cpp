class Solution {
public:
    bool isValid(string S) {
        stack<char> stk;
        
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == 'c') {
                if(!stk.empty() && stk.top() == 'b') {
                    stk.pop();
                    if(!stk.empty() && stk.top() == 'a') {
                        stk.pop();
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            else {
                stk.push(S[i]);
            }
        }
        
        return stk.empty();
    }
};
