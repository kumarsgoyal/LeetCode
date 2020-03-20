class MyQueue {
public:
    
    int front;
    stack<int> s1;
    stack<int> s2;
    
    /** Initialize your data structure here. */
    MyQueue() {
        front = -1;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty()) {
            front = x;
        }
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = 0;
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        res = s2.top();
        s2.pop();
        
        // stack is empty or que is empty
        if(s2.empty() == false)
            front = s2.top();
        else 
            front = 0;
        
        
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
