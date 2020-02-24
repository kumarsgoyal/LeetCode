class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        vector<int> res;
        for(int i = 0; i < arr.size(); i++) 
            mp[arr[i]] = i; // arr[i] value as key
        
        int rank = 1;
        for(auto i = mp.begin(); i != mp.end(); i++) {
            i->second = rank++;
        }
        
        for(int i = 0; i < arr.size(); i++) {
            res.push_back(mp.find(arr[i])->second);
        }
        
        return res;
    }
};
