class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int diff = INT_MAX;
        int size = arr.size();
        vector<vector<int>> res;
        
        // calculate min diff;
        for(int i = 0; i < size-1; i++) {
            diff = min(diff, (arr.at(i+1)-arr.at(i)));
        }
        for(int i = 0; i < size-1; i++) {
            // pair having diff min push into vector
            if(diff == (arr.at(i+1) - arr.at(i))) {
                vector<int> tmp;
                tmp.push_back(arr.at(i));
                tmp.push_back(arr.at(i+1));
                res.push_back(tmp);
            }
        }
        
        return res;
    }
};
