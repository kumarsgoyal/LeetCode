class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        
        int size = A.size();
        int i = 0; // odd index
        int j = 0; // even index
        
        vector<int> res;
        
        while(i < size && j < size) {
            while((i < size) && (A.at(i)%2 == 0)) {
                i++;
            }
            while((j < size) && (A.at(j)%2 != 0)) {
                j++;
            }
            if(i < size && j < size) {
                res.push_back(A.at(j));
                res.push_back(A.at(i));
                j++;
                i++;
            }
        }
        return res;
        
    }
};
