class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        
        vector<int> res;
        
        
        // even numbers
        for(auto i = A.begin(); i != A.end(); i++) {
            if(((*i)%2) == 0) {
                res.push_back(*i);
            } 
        }
        
        
        // odd numbers
        for(auto i = A.begin(); i != A.end(); i++) {
            if((*i)%2) {
                res.push_back(*i);
            }
        }
        
        return res;
    }
};
