class Solution {
public:
    void findnext(vector<int> num, vector<int> &next) {
        stack<int> stk;
        for(int i = 0; i < num.size(); i++) {
            if(stk.empty() || num.at(stk.top()) > num.at(i)) {
                stk.push(i);
            }
            else {
                while(!stk.empty() && num.at(stk.top()) < num.at(i)) {
                    next.at(stk.top()) = num.at(i);
                    stk.pop();
                }
                stk.push(i);
            }
        }
    }
    
    void binarysearch(vector<int> num1, vector<int> num2, vector<int> next, vector<int> &res) {
        for(int i = 0; i < num1.size(); i++) {
            auto j = find(num2.begin(), num2.end(), num1.at(i));
            // not found
            if(j == num2.end()) {
                res.push_back(-1);
            }
            else {
                res.push_back(next.at(j - num2.begin()));
            }
        }
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> next(nums2.size(), -1);
        vector<int> res;
        findnext(nums2, next);
        binarysearch(nums1, nums2, next, res);
        
        return res;
    }
};
