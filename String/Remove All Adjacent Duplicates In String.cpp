class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        
        if(S.size() == 0) {
            return "";
        }
        
        for(int i = 0; i < S.length(); i++) {
            if((res.empty() == 0) && (res.back() == S[i])) {
                res.pop_back();
            }
            // if res is empty or last element res is not equal to current element 
            // S[i] mean they are not adjacent till now.
            else {
                res.push_back(S[i]);
            }
        }
        
        return res;
    }
};
