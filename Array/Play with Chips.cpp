class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int evenpos = 0;
        int oddpos = 0;
        int size = chips.size();
        
        // move all odd pos to one odd pos cost 0 unit
        // move all even pos to one even pos cost 0 unit
        
        for(int i = 0; i < size; i++) {
            if(chips[i] %2) {
                oddpos++;
            }
            else {
                evenpos++;
            }
        }
        
        // As all odd pos chips is at one pos 
        // and even chips all another pos
        // Now move all chips to single pos min chips of(odd, even)
        // cost 1 unit per chip;
        return min(oddpos, evenpos);
    }
};
