class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        vector<int> res(T.size(), 0);
        
        for(int i = 0; i < T.size(); i++) {
            
            while(!stk.empty() && T[stk.top()] < T.at(i)) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
       
        
        return res;
    }
};
