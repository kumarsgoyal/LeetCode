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
            res.push_back(stk.top());
            stk.pop();
        }
        
        int  i = 0;
        int j = res.length() - 1;
        char ch;
        // reverse string
        while(i < j) {
            ch = res[i];
            res[i] = res[j];
            res[j] = ch;
            i++;
            j--;
        }
        return res;
    }
};
