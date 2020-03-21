class CustomStack {
public:
    int max;
    int size;
    stack<int> stk;
    CustomStack(int maxSize) {
        max = maxSize;
        size = 0;
    }
    
    void push(int x) {
        if(size < max) {
            stk.push(x);
            size++;
        }
    }
    
    int pop() {
        int top = -1;
        if(size > 0) {
            top = stk.top();
            stk.pop();
            size--;
        }
        
        return top;
    }
    
    void increment(int k, int val) {
            stack<int> temp;
            
            while(!stk.empty()) {
                temp.push(stk.top());
                stk.pop();
            }
            
            while(!temp.empty() && k--) {
                stk.push(temp.top() + val);
                temp.pop();
            }
        
            while(!temp.empty()) {
                stk.push(temp.top());
                temp.pop();
            }
            
        }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
