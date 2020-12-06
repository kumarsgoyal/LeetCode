class Solution {
    public int maxNumberOfBalloons(String text) {
        int a = 0, b = 0, l = 0, o = 0, n = 0;
        
        for(char c : text.toCharArray()) {
            if(c == 'a') 
                a++;
            else if(c == 'b') 
                b++;
            else if(c == 'l') 
                l++;
            else if(c == 'o') 
                o++;
            else if(c == 'n') 
                n++;
        }
        
        int max = Math.min(a, Math.min(b, n));
        int maxx = Math.min(l, o);
    
        
        if((2 * max) <= maxx) 
            return max;
        else 
            return maxx/2;
    }
}
