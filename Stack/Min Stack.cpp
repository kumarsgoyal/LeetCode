class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    int min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        if(min >= x) {
            min = x;
        }
        stk.push(x);
        stk.push(min);
    }
    
    void pop() {
        stk.pop(); // pop out min element
        int res = stk.top(); // top element of stack
        stk.pop();
        
        if(stk.empty()) {
            min = INT_MAX;
        }
        else {
            min = stk.top();
        }
    }
    
    int top() {
        int minn = stk.top();
        stk.pop();
        int tp = stk.top();
        stk.push(minn);
        
        return tp;
    }
    
    int getMin() {
        if(stk.empty()) {
            return 0;
        }
        return stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
