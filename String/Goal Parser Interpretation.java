class Solution {
    public String interpret(String command) {
        StringBuilder res = new StringBuilder();
        
        for(int i = 0; i < command.length(); i++) {
            if(command.charAt(i) == 'G') 
                res.append('G');
            else if(command.charAt(i) == 'a') 
                res.append("al"); 
            else if(command.charAt(i) == ')' && command.charAt(i - 1) == '(') 
                res.append("o");
        }
        
        return res.toString();
    }
}
