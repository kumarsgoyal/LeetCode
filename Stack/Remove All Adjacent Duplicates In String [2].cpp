class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        stack<char> stk;
        for(int i = 0; i < S.length(); i++) {
            if(stk.empty() || stk.top() != S[i]) {
                stk.push(S[i]);
            }
            else if(stk.top() == S[i]) {
                stk.pop();
            }
        }
        
        // reverse stack
        stack<char> rev;
        while(!stk.empty()) {
            rev.push(stk.top());
            stk.pop();
        }
        
        // copy stack to result 
        while(!rev.empty()) {
            res.push_back(rev.top());
            rev.pop();
        }
        return res;
    }
};
