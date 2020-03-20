class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        int temp = 0;
        stack<int> stk;
        
        for(int i = 0; i < ops.size(); i++) {
            
            if(ops.at(i) == "C") {
                stk.pop();
            }
            else if(ops.at(i) == "D") {
                stk.push(2 * stk.top());
            }
            else if(ops.at(i) == "+") {
                int top1 = stk.top();
                stk.pop();
                int top2 = stk.top();
                stk.push(top1);
                
                stk.push(top1 + top2);
            }
            else {
                temp = stoi(ops.at(i));
                stk.push(temp);
            }

        }
        
        while(!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        
        return sum;
    }
};
