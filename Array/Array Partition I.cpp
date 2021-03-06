class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        
        for(auto i = nums.begin(); i != nums.end(); i++) {
            int a = *i;
            i++;
            sum += min(a, *i) ;
            
        }
        
        return sum;
    }
};
