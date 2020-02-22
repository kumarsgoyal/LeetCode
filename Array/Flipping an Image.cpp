class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res;
        auto x = res.begin();
        for(auto i = A.begin(); i != A.end(); i++) {
            vector<int> temp;
            for(auto j = i->rbegin(); j != i->rend();j++) {
                if(*j) {
                    temp.push_back(0);
                }
                else {
                    temp.push_back(1);
                }
            }
            res.push_back(temp);
        }
        
        return res;
    }
};
