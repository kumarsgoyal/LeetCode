class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(auto i = grid.begin(); i != grid.end(); i++) {
            for(auto j = i->rbegin(); j != i->rend(); j++) {
                if(*j >= 0) {
                    break;
                }
                count++;
            }
        }
        return count;
    }
};
