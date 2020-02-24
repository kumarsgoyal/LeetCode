class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size()*nums[0].size() != r*c) {
            return nums;
        }
        vector<vector<int>> res;
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                temp.push_back(nums[i][j]);
                if(c == temp.size()) {
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        
        return res;
    }
};
