class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mapp;
        
        
        for(auto i = arr1.begin(); i != arr1.end(); i++) {
            mapp[*i]++;
        }
        
        vector<int> res;
        
        for(auto i = arr2.begin(); i != arr2.end(); i++) {
            auto temp = mapp.find(*i);
            for(int j = 0; j < temp->second; j++) {
                res.push_back(*i);
            }
            mapp.erase(*i);
        }
        
        for(auto i = mapp.begin(); i != mapp.end(); i++) {
            for(int j = 0; j < i->second; j++) {
                res.push_back(i->first);
            }
        }
        
        mapp.clear();
        
        return res;
    }
};
