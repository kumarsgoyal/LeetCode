class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int[] index = new int[26];
        int max = -1;
        for(int i = 0; i < s.length(); i++) {
            char temp = s.charAt(i);
            if(index[temp - 'a'] == 0) {
                index[temp - 'a'] = i + 1;
            }
            else {
                max = Math.max(max, i - index[temp - 'a']);
            }
        }
        
        return max;
    }
}
