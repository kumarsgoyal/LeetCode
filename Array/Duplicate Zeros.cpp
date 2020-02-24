class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> res;
        int size = arr.size();
        for(int i = 0; i < size; i++) {
            if(res.size() <= size) {
                if(arr[i] == 0) {
                    res.push_back(arr[i]);
                    res.push_back(arr[i]);
                }
                else {
                    res.push_back(arr[i]);
                }
            }
            else {
                break;
            }
        }
        
        arr.clear();
        for(int i = 0; i <size; i++) {
            arr.push_back(res[i]);
        }
        res.clear();
    }
};
