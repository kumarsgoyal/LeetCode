class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int index = 0;
        int val = 0;
        int sum = 0;
        for(int i = 0; i < A.size(); i++) {
            if(!(A[i]%2)) {
                sum += A[i];
            }
        }
        
        cout<<sum;
        
        for(int i = 0; i < queries.size(); i++) {
            val = queries[i][0];
            index = queries[i][1];
                
            if(A[index]%2) { // odd
                int temp = A[index];
                A[index] += val;
                if(A[index]%2 == 0) { // ifodd become even add to sum;
                    sum = sum + val + temp;
                }
                
            }
            else { // even
                int temp = A[index];
                A[index] += val;
                if(A[index]%2) { // even become odd
                    sum -= temp;
                }
                else {
                    sum += val; // add or sub val from sum;
                }
            }
            res.push_back(sum);
        }
        
        return res;
    }
};
