class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n%2) {
            res.push_back(0);
            n--;
        }
        for(int i = 1; i <= n; i++) {
            res.push_back(i);
            res.push_back(-i);
            i++;
        }
        return res;
    }
};
