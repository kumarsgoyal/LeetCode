class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        int *arr = new int[size];
        stack<int> stk;
    
        for(int i = 0; i < 2*size; i++) {
            while(!stk.empty() && nums[stk.top()] < nums[i%size]) {
                arr[stk.top()] = nums[i%size];
                stk.pop();
            }
            if(i < size) {
                stk.push(i);
            }
        }
        
        while(!stk.empty()) {
            arr[stk.top()] = -1;
            stk.pop();
        }
        
        
        vector<int> res (arr, arr+size);
        return res;
    }
};Next Greater Element I
