class Solution {
    public List<String> stringMatching(String[] words) {
        
        if(words==null || words.length==0)
            return new ArrayList<String>();
        
        Set<String> ans = new HashSet();
        
        for(String word:words) {
            for(String word1:words) {
                if(!word.equals(word1) && !ans.contains(word1) && word.indexOf(word1) !=-1) {
                   ans.add(word1);
                }
            }
        }
        
        return new ArrayList(ans);
    }
}
