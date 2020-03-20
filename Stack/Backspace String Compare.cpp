class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1;
        stack<char> s2;
        
        int i = 0;
        int j = 0;
        while(i < S.length() || j < T.length()) {
            // # pop only when is stack is not empty
            if(i < S.length()) {
                if(S[i] == '#' && !s1.empty()) {
                    s1.pop();
                }
                // not #
                else if(S[i] != '#'){
                    s1.push(S[i]);
                }
                i++;
            }
            
            if(j < T.length()) {
                // # pop only when stack is not empty
                if(T[j] == '#' && !s2.empty()) {
                    s2.pop();
                }
                // not #
                else if(T[j] != '#'){
                    s2.push(T[j]);
                }
                j++;
            }
        }
        
        string str1;
        string str2;
        
        while(!s1.empty()) {
            str1.push_back(s1.top());
            s1.pop();
        }
        
        while(!s2.empty()) {
            str2.push_back(s2.top());
            s2.pop();
        }
        
        cout<<str1<<" "<<str2;
        return str1.compare(str2) == 0 ? true : false;
        
    }
};
