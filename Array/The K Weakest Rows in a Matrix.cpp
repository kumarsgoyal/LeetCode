class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int freq = 0, index = 0;
        vector<int> res;
        multimap<int, int> mapp;
        for(auto i = mat.begin(); i != mat.end(); i++) {
            freq = 0;
            for(auto j = i->begin(); j != i->end(); j++) {
                if(*j == 1) {
                    freq++;
                }
            }
            mapp.insert({freq, index});
            index++;
        }
        
        int mark = 0;
        for(auto i = mapp.begin(); i != mapp.end(); i++) {
            if(mark == k) {
                break;
            }
            res.push_back(i->second);
            mark++;
        }
        
        
        return res;
        
    }
};
