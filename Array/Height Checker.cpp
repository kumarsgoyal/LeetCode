class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // store heights in temp and sort it
        vector<int> temp(heights);
        sort(temp.begin(), temp.end());
        
        int size = heights.size();
        int ans = 0;
        
        // compare value of height and temp
        for(int i = 0; i < size; i++) {
            if(heights.at(i) != temp.at(i)) {
                ++ans;
            }
        }
        return ans;
    }
};
