class Solution {
public:
    
    void reverse(string &s, int i, int j) {
        char temp;
        while(i < j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        
        temp = '\0';
    }
    
    string reverseParentheses(string s) {
        stack<int> stk;
        string str;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else if(s[i] == ')') {
                reverse(s, stk.top(), i);
                stk.pop();
            }
        }
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != '(' && s[i] != ')') {
                str.push_back(s[i]);
            }
        }
        
        return str;
    }
};
