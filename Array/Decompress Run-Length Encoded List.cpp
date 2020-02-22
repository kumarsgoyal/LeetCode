class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(auto i = nums.begin(); i != nums.end(); i++) {
            int limit = *i;
            i++;
            for(int j = 0; j < limit; j++) {
                res.push_back(*i);
            }
        }
        return res;
    }
};
