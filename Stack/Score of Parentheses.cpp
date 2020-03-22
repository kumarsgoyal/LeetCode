class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk;
        int score = 0;
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == '(') {
                stk.push(score);
                score = 0;
            }
            else {
                score = stk.top() + max(score*2, 1);
                stk.pop();
            }
        }
        
        return score;
    }
};
