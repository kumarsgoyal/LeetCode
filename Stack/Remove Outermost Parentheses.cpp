class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        stack<int> stk;
        vector<int> vec;
        for(int i = 0; i < S.length(); i++) {
            if(stk.empty()) {
                stk.push(i);
                vec.push_back(i);
            }
            else if(S[i] == '(') { 
                stk.push(i);
            }
            else if(S[i] == ')') {
                stk.pop();
                if(stk.empty()) {
                    vec.push_back(i);
                }
            }
        }
        
        
        for(int i = 0; i < vec.size(); i+=2) {
            int ll = vec.at(i);
            int ul = vec.at(i+1);
            
            for(int j = ll+1; j < ul; j++) {
                res.push_back(S[j]);
            }
            
        }
        
        return res;
    }
};
