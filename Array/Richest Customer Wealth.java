class Solution {
    public int maximumWealth(int[][] accounts) {
        int sum = 0;
        int max = 0;
        
        for(int[] arr : accounts) {
            sum = 0;
            for(int i : arr) {
                sum += i;
            }
            
            if(sum > max) 
                max = sum;
        }
        
        return max;
    }
}
