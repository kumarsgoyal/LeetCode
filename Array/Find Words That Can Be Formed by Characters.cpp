class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int flag1[26] = {0};
        int flag2[26] = {0};
        int len = 0;
        int flag = 0;
        int res = 0;
        
        len = chars.size();
        
        // frequency of chars
        for(int i = 0; i < len; i++) {
            flag2[chars[i] - 'a'] += 1;
        }
        
        
        for(auto i = words.begin(); i != words.end(); i++) {
            string temp = *i; // store string in temp
            len = temp.size();
            flag = 0;
            
            // calculate frequency of string 
            for(int j = 0; j < len; j++) {
                flag1[temp[j] - 'a'] += 1;
            }
            
            for(int j = 0; j < 26; j++) {
                // if frequency of string is more than chars then string cannot be formed from chars
                if(flag2[j] < flag1[j]) {
                    flag = 1;
                }
                flag1[j] = 0;
            } 
            
            if(!flag) {
                res += len;
            }
        }
        
    return res;
    }
};
