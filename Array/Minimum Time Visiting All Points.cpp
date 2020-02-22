class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x[2],y[2];
        int b;
        int size = points.size();
        auto i = points.begin();
        
        b = 0;
        for(auto a = i->begin(); a != i->end(); a++, b++) {
            x[b] = *a;
        }
        i++;
        
        int res = 0;
        
        for(int j = 1; j < size; j++) {
            
            b = 0;
            for(auto a = i->begin(); a != i->end(); a++, b++) {
                y[b] = *a;
            }
            
            int hor = abs(y[0] - x[0]);
            int ver = abs(y[1] - x[1]);
            res += max(hor, ver);
            x[0] = y[0];
            x[1] = y[1];
            i++;
        }
        
        return res;
    }
};
