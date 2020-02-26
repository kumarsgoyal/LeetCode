class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> res(N+1, 0);
        
        for(vector<int> temp : trust) {
            res.at(temp[0]) -= 1;
            res.at(temp[1]) += 1;
        }
        
        for(int i = 1; i <= N; i++) {
            if(res[i] == (N - 1)) {
                res.clear();
                return i;
            }
        }
        return -1;
    }
    
};
