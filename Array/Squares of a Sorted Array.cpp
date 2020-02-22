class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        
        int i = 0;
        int j = 0;
        int size = A.size();
        
        // find first +ve index;
        while(j < size && A.at(j) < 0) {
            j++;
        }
        
        // last -ve index
        i = j-1;
        
        while(i >= 0 && j < size) {
            if(A.at(i)*A.at(i) < A.at(j)*A.at(j)) {
                res.push_back(A.at(i)*A.at(i));
                    i--;
            }
            else {
                res.push_back(A.at(j)*A.at(j));
                j++;
            }
        }
        
        // -ve number remain
        while(i >= 0) {
            res.push_back(A.at(i)*A.at(i));
            i--;
        }
        
        // +ve number remain
        while(j < size) {
            res.push_back(A.at(j)*A.at(j));
            j++;
        }
        
        return res;
    }
};
