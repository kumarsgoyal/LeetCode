class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int rowcol[2];
        
        int res = 0;
        int **a = new int*[n];
        for(int x = 0; x < n; x++) {
            a[x] = new int[m];
        }
        
        
         for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                a[x][y] = 0;
            }
        }
        
        for(auto i = indices.begin(); i != indices.end(); i++) {
            int index = 0;
            
            for(auto j = i->begin(); j != i->end(); j++) {
                rowcol[index++] = *j; 
            }
            
            for(int x = 0;x < m; x++) { // move in that row
                a[rowcol[0]][x] += 1;
            }
            
            for(int x = 0; x < n; x++) { // move in that col
                a[x][rowcol[1]] +=1;
            }
            
        }
        
        // count
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                if(a[x][y]%2) {
                    res++;
                }
            }
        }
        
        return res;
    }
};
