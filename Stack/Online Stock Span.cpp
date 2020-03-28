class StockSpanner {
public:
    stack<int> stk;
    vector<int> vec;
    int index;
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        vec.push_back(price);
        while(!stk.empty() && vec[stk.top()] <= price) {
            stk.pop();
        }
        
        int res = (stk.empty()) ? index + 1 : index-stk.top(); 
        
        stk.push(index++);
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
