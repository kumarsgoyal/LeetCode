class MyStack {
public:
    /** Initialize your data structure here. */
    int to;
    queue<int> q;
    queue<int> temp;
    MyStack() {
        to = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        to = x;
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = 0;
        
        if(q.size() == 0) {
            return res;
        }
        
        while(q.size() > 1) {
            temp.push(q.front());
            q.pop();
        }
        
        res = q.front();
        q.pop();
        
        if(temp.empty()) {
            to = 0;
        }

        while(!temp.empty()) {
            q.push(temp.front());
            to = temp.front();
            temp.pop();
        }
    
        return res;    
    }
    
    /** Get the top element. */
    int top() {
        return to;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.empty()) {
            return true;
        }
        
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
