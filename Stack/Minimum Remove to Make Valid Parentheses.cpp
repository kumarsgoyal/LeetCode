class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> stk;
        string str;
        int o = 0; // open paranthesis count
        int c = 0; // open paranthesis count
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {  
                o++;
                stk.push(s[i]);
            }   
            else if(s[i] == ')' && c < o) {  
                c++;
                stk.push(s[i]);
            }
            else if(s[i] != ')') {
                stk.push(s[i]);
            }
        }
        
        int diff = o - c;
        
        while(!stk.empty()) {
            if(stk.top() == '(' && diff) {
                diff--;
            }
            else {
                str.push_back(stk.top());
            }
            stk.pop();
        }
        
        int i = 0;  
        int j = str.length() - 1;  
        
        while(i < j) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
        
        return str;
    }
};
