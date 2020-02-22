class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto i = nums.begin(); i != nums.end(); i++) {
            int num = *i;
            int count = 0;
            while(num) {
                num = num/10;
                count++;
            }
            if(count%2 == 0) {
                res++;
            }
        }
        return res;
    }
};
