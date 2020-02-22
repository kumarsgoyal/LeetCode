class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res;
        vector<int> finalres;
        int max = -1;
        for(auto i = arr.rbegin(); i != arr.rend(); i++) {
            res.push_back(max);
            if(max < *i) {
                max = *i;
            }
        }
        
        for(auto i = res.rbegin(); i != res.rend(); i++) {
            finalres.push_back(*i);
        }
        
        res.clear();
        return finalres;
    }
};
